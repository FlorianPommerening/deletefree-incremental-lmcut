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
    foreach(Landmark *landmark, this->landmarks) {
        delete landmark;
    }
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
        Landmark *containingLM = this->operatorToLandmark[forbiddenOp->id];
        if (containingLM == NULL) {
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
            int oldLandmarkCost = containingLM->cost;
            containingLM->remove(forbiddenOp);
            this->operatorToLandmark[forbiddenOp->id] = NULL;
            int newLandmarkCost = containingLM->cost;
            if (containingLM->size() == 0) {
                this->heuristicValue = UIntEx::INF;
                return *this;
            } else if (containingLM->size() == 1) {
                this->singleOperatorLandmarks.push_back(containingLM);
            }
            this->heuristicValue -= (oldLandmarkCost - newLandmarkCost);
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
        Landmark * containingLM = this->operatorToLandmark[appliedOp->id];
        if (containingLM == NULL) {
            // the cost function only changes for the applied operator (set to INF)
            // since reapplying this operator doesn't change the state it can't hurt to forbid this operator (i.e. set its cost to INF)
            // without influencing hmax. As hmax was 0 before, it will stay 0, so no new landmarks will be found.
            needsHeuristicUpdate = false;
        } else {
            // "undo" this landmark: decrease heuristic value and
            // increase all contained operator's costs by the LM's cost
            int landmarkCost = containingLM->cost;
            this->heuristicValue -= landmarkCost;
            foreach(Landmark::value_type &entry, *containingLM) {
                RelaxedOperator *op = entry.first;
                if (op != appliedOp) {
                    this->operatorCost[op->id] += landmarkCost;
                }
                this->operatorToLandmark[op->id] = NULL;
            }
            if (containingLM->size() == 1) {
                // if this was the only operator in the landmark, there cannot be any new landmarks with the same argument as above
                needsHeuristicUpdate = false;
                // TODO remove could be replaced by erase if operator to iterator mapping is saved
                vector<Landmark *>::iterator newEnd = remove(this->singleOperatorLandmarks.begin(), this->singleOperatorLandmarks.end(), containingLM);
                this->singleOperatorLandmarks.resize(newEnd - this->singleOperatorLandmarks.begin());
            }
            // TODO remove could be replaced by erase if operator to iterator mapping is saved
            vector<Landmark *>::iterator newEnd = remove(this->landmarks.begin(), this->landmarks.end(), containingLM);
            this->landmarks.resize(newEnd - this->landmarks.begin());
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
        this->landmarks.clear();
        this->operatorToLandmark.clear();
        this->operatorToLandmark.resize(this->task.operators.size());
        this->singleOperatorLandmarks.clear();
    }
    // run heuristic calculation
    int firstNewLandmark = this->landmarks.size();
    UIntEx lmCutValue = lmCut(this->task, this->currentState, this->operatorCost, this->landmarks);
    // sort and cross-reference new landmarks
    for (unsigned i=firstNewLandmark; i < this->landmarks.size(); ++i) {
        Landmark *landmark = this->landmarks[i];
        foreach(Landmark::value_type &entry, *landmark) {
            RelaxedOperator *op = entry.first;
            this->operatorToLandmark[op->id] = landmark;
        }
        if (landmark->size() == 1) {
            this->singleOperatorLandmarks.push_back(landmark);
        }
    }
    this->heuristicValue += lmCutValue;
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
        if (!this->options.autoApplyZeroCostOperators) {
            foreach(RelaxedOperator *freeOp, this->task.zeroBaseCostOperators) {
                stateChanged = this->tryApplyUnitPropagationOperator(freeOp);
            }
        }
        // try operators in landmarks of size 1
        if (!this->options.autoApplyUnitLandmarks) {
            vector<Landmark *>::iterator it = this->singleOperatorLandmarks.begin();
            while (it != this->singleOperatorLandmarks.end()) {
                // applyOperatorWithoutUpdate() can delete the entry in singleOperatorLandmarks
                // copy iterator so it can be used for erase without breaking the loop
                vector<Landmark *>::iterator current = it;
                // increment iterator before (!!!) erase
                ++it;
                Landmark *unitClause = *current;
                RelaxedOperator *op = unitClause->begin()->first;
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
