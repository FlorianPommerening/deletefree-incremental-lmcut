#include "SearchNode.h"
#include "foreach.h"
#include "hmax.h"
#include "lmcut.h"

#include <stack>
#include <algorithm>

using namespace std;

SearchNode::SearchNode(RelaxedTask &task, OptimizationOptions &options):
        heuristicValue(0),
        currentCost(0),
        landmarkCollection(task.operators),
        task(task),
        unitPropagationCount(0),
        options(options) {
    this->currentState.add(task.init);
    // create default cost function
    this->operatorCost.resize(task.operators.size());
    foreach(RelaxedOperator *op, task.operators) {
        this->operatorCost[op->id] = op->baseCost;
    }
    this->updateHeuristicValue();
    this->partialPlan.reserve(task.operators.size());
}

SearchNode::~SearchNode() {
}

SearchNode::SearchNode(const SearchNode &other):
                    heuristicValue(other.heuristicValue),
                    currentCost(other.currentCost),
                    currentState(other.currentState),
                    partialPlan(other.partialPlan),
                    landmarkCollection(other.landmarkCollection),
                    operatorCost(other.operatorCost),
                    task(other.task),
                    unitPropagationCount(0),
                    options(other.options) {
}

SearchNode& SearchNode::operator=(const SearchNode& /* rhs */) {
    throw "Assignment operator should not be used for SearchNode";
}

SearchNode& SearchNode::applyOperator(RelaxedOperator *appliedOp) {
    bool needsHeuristicUpdate = this->applyOperatorWithoutUpdate(appliedOp);
    this->unitPropagation();
    if (needsHeuristicUpdate) {
        this->updateHeuristicValue();
    }
    return *this;
}

SearchNode& SearchNode::forbidOperator(RelaxedOperator *forbiddenOp) {
    this->operatorCost[forbiddenOp->id] = UIntEx::INF;
    bool needsHeuristicUpdate = true;
    if (this->options.incrementalSearch) {
        LandmarkId landmarkId = this->landmarkCollection.containingLandmark(forbiddenOp);
        if (landmarkId == -1) {
            // if the operator doesn't occur in a landmark, there will not be any change in the cost function
            // apart from setting this op to infinity.
            // forbidding an operator with baseCost==0 can lead to new landmarks or unsolvable tasks.
            // on the other hand forbidding an operator with baseCost==1 will never lead to a change in hmax,
            // when the hmax value was previously 0 (as in the last LM-cut step from the previous LM-cut calculation).
            // with an hmax value of 0 no new landmarks can be discovered.
            if (forbiddenOp->baseCost != 0) {
                // if operatorCost[forbiddenOp] != 0, the hmax value doesn't depend on forbiddenOp, and will not change
                // if operatorCost[forbiddenOp] == 0, there is a last time (t*) this was set to 0
                // cost values are only decreased when a landmark is discovered, so forbiddenOp was in a landmark but is not anymore
                // its costs are not INF, so it was not the operator applied or removed in any previous step
                // the only other option how the landmark containing forbiddenOp was removed is when applying another operator from that landmark,
                // but in this case the cost of forbiddenOp would increase by the cost of the landmark.
                // since only non-zero cost operators are contained in a landmark, the cost would be >0 afterwards and would have to be decreased again
                // but the decrease in the assumption (t*) was the last time.
                needsHeuristicUpdate = false;
            }
        } else {
            // remove operator from landmark. If it was the only one,
            // the problem becomes unsolvable
            bool stillValid = this->landmarkCollection.removeOperatorFromContainingLandmark(forbiddenOp);
            if (!stillValid) {
                this->heuristicValue = UIntEx::INF;
                return *this;
            }
            // value of landmark cannot change in unit cost setting
            // this->heuristicValue -= (oldLandmarkCost - newLandmarkCost);
        }
    }
    this->unitPropagation();
    // search for additional landmarks
    if (needsHeuristicUpdate) {
        this->updateHeuristicValue();
    }
    return *this;
}


bool SearchNode::applyOperatorWithoutUpdate(RelaxedOperator *appliedOp) {
    bool needsHeuristicUpdate = true;
    appliedOp->apply(this->currentState);
    partialPlan.push_back(appliedOp);
    this->currentCost += appliedOp->baseCost;
    this->operatorCost[appliedOp->id] = UIntEx::INF;
    if (this->options.incrementalSearch) {
        LandmarkId landmarkId = this->landmarkCollection.containingLandmark(appliedOp);
        if (landmarkId == -1) {
            // the cost function only changes for the applied operator (set to INF)
            // since reapplying this operator doesn't change the state it can't hurt to forbid this operator (i.e. set its cost to INF)
            // without influencing hmax. As hmax was 0 before, it will stay 0, so no new landmarks will be found.
            needsHeuristicUpdate = false;
        } else {
            // "undo" this landmark: decrease heuristic value and
            // increase all contained operator's costs by the LM's cost
            // in unit cost setting all landmarks have cost 1
            const int landmarkCost = 1;
            this->heuristicValue -= landmarkCost;
            foreach(RelaxedOperator *op, this->landmarkCollection.iterateLandmark(landmarkId)) {
                if (op != appliedOp) {
                    this->operatorCost[op->id] += landmarkCost;
                }
            }
            if (this->landmarkCollection.getSize(landmarkId) == 1) {
                // if this was the only operator in the landmark, there cannot be any new landmarks with the same argument as above
                needsHeuristicUpdate = false;
            }
            this->landmarkCollection.removeLandmark(landmarkId);
        }
    }
    return needsHeuristicUpdate;
}

void SearchNode::updateHeuristicValue() {
    if (!this->options.incrementalSearch) {
        // reset cost mapping but keep the forbidden ops.
        for(unsigned i=0; i < this->task.operators.size(); ++i) {
            if (this->operatorCost[i] != UIntEx::INF) {
                this->operatorCost[i] = this->task.operators[i]->baseCost;
            }
        }
        // no previous heuristic value
        this->heuristicValue = 0;
        // no previous landmarks
        this->landmarkCollection.clear();
    }
    // run heuristic calculation
    UIntEx lmCutResult = lmCut(this->task, this->currentState, this->operatorCost, this->landmarkCollection);
    // TODO: is it safe to do this instead?   this->heuristicValue += lmCutResult;
    if (lmCutResult == UIntEx::INF) {
        this->heuristicValue = UIntEx::INF;
    } else {
        this->heuristicValue = this->landmarkCollection.getCost();
    }
}

void SearchNode::unitPropagation() {
    if (!(this->options.autoApplyUnitLandmarks || this->options.autoApplyZeroCostOperators)) {
        return;
    }
    bool stateChanged = true;
    // if the state changed, new operators could be applicable
    while (stateChanged) {
        stateChanged = false;
        // try 0-base-cost operators
        if (this->options.autoApplyZeroCostOperators) {
            foreach(RelaxedOperator *freeOp, this->task.zeroBaseCostOperators) {
                stateChanged = this->tryApplyUnitPropagationOperator(freeOp);
            }
        }
        // try operators in landmarks of size 1
        if (this->options.autoApplyUnitLandmarks) {
            vector<RelaxedOperator *> &singleOperatorLandmarks = this->landmarkCollection.getSingleOperatorLandmarks();
            foreach(RelaxedOperator *op, singleOperatorLandmarks) {
                stateChanged = this->tryApplyUnitPropagationOperator(op);
            }
        }
    }
}

bool SearchNode::tryApplyUnitPropagationOperator(RelaxedOperator *op) {
    if (op->isApplicable(this->currentState) && this->operatorCost[op->id] != UIntEx::INF) {
#ifdef FULL_DEBUG
        cout << endl << "Operator applied in unit propagation: " << op->name << endl;
#endif
        this->applyOperatorWithoutUpdate(op);
        this->unitPropagationCount++;
        return true;
    }
    return false;
}
