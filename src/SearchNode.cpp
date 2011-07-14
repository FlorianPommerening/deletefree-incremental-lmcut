#include "SearchNode.h"
#include "foreach.h"
#include "hmax.h"
#include "lmcut.h"

#include <stack>

using namespace std;

SearchNode::SearchNode(RelaxedTask &task, OptimizationOptions &options):
        heuristicValue(0),
        currentCost(0),
        task(task),
        unitPropagationCount(0),
        options(options) {
    this->currentState.add(task.init);
    foreach(RelaxedOperator &op, task.operators) {
        this->operatorCost[&op] = op.baseCost;
    }
    this->updateHeuristicValue();
}

SearchNode::SearchNode(const SearchNode &other):
                    heuristicValue(other.heuristicValue),
                    currentCost(other.currentCost),
                    currentState(other.currentState),
                    partialPlan(other.partialPlan),
                    landmarks(other.landmarks),
                    operatorCost(other.operatorCost),
                    task(other.task),
                    unitPropagationCount(0),
                    options(other.options) {
    foreach(Landmark &landmark, this->landmarks) {
        foreach(Landmark::value_type &entry, landmark) {
            RelaxedOperator *op = entry.first;
            this->operatorToLandmark[op] = &landmark;
        }
        if (landmark.size() == 1) {
            this->singleOperatorLandmarks.push_back(&landmark);
        }
    }
}

SearchNode& SearchNode::operator=(const SearchNode& /* rhs */) {
    throw "Assignment operator should not be used for SearchNode";
}

SearchNode& SearchNode::applyOperator(RelaxedOperator *appliedOp) {
    this->applyOperatorWithoutUpdate(appliedOp);
    if (this->options.useUnitPropagation) {
        this->unitPropagation();
    }
    this->updateHeuristicValue();
    return *this;
}

SearchNode& SearchNode::forbidOperator(RelaxedOperator *forbiddenOp) {
    this->operatorCost[forbiddenOp] = UIntEx::INF;
    PointerMap<RelaxedOperator, Landmark *>::iterator it = this->operatorToLandmark.find(forbiddenOp);
    if (it != this->operatorToLandmark.end()) {
        Landmark *containingLM = it->second;
        // remove operator from landmark. If it was the only one,
        // the problem becomes unsolvable
        int oldLandmarkCost = containingLM->cost;
        containingLM->remove(forbiddenOp);
        int newLandmarkCost = containingLM->cost;
        if (containingLM->size() == 0) {
            this->heuristicValue = UIntEx::INF;
            return *this;
        } else if (containingLM->size() == 1) {
            this->singleOperatorLandmarks.push_back(containingLM);
        }
        this->heuristicValue -= (oldLandmarkCost - newLandmarkCost);
    }
    // search for additional landmarks
    if (this->options.useUnitPropagation) {
        this->unitPropagation();
    }
    this->updateHeuristicValue();
    return *this;
}


void SearchNode::applyOperatorWithoutUpdate(RelaxedOperator *appliedOp) {
    appliedOp->apply(this->currentState);
    partialPlan.push_back(appliedOp);
    this->currentCost += appliedOp->baseCost;
    this->operatorCost[appliedOp] = UIntEx::INF;
    PointerMap<RelaxedOperator, Landmark *>::iterator it = this->operatorToLandmark.find(appliedOp);
    if (it != this->operatorToLandmark.end()) {
        Landmark *containingLM = it->second;
        // "undo" this landmark: decrease heuristic value and
        // increase all contained operator's costs by the LM's cost
        int landmarkCost = containingLM->cost;
        this->heuristicValue -= landmarkCost;
        foreach(Landmark::value_type &entry, *containingLM) {
            RelaxedOperator *op = entry.first;
            if (op != appliedOp) {
                this->operatorCost[op] += landmarkCost;
            }
        }
        if (containingLM->size() == 1) {
            // TODO remove could be replaced by erase if operator to iterator mapping is saved
            this->singleOperatorLandmarks.remove(containingLM);
        }
        // TODO remove could be replaced by erase if operator to iterator mapping is saved
        this->landmarks.remove(*containingLM);
        this->operatorToLandmark.erase(it);
    }
}

void SearchNode::updateHeuristicValue() {
    list<Landmark>::iterator firstAdded;
    UIntEx lmCutValue = lmCut(this->task, this->currentState, this->operatorCost, this->landmarks, &firstAdded);
    for (list<Landmark>::iterator it = firstAdded; it != this->landmarks.end(); ++it) {
        Landmark &landmark = *it;
        foreach(Landmark::value_type &entry, landmark) {
            RelaxedOperator *op = entry.first;
            this->operatorToLandmark[op] = &landmark;
        }
        if (landmark.size() == 1) {
            this->singleOperatorLandmarks.push_back(&landmark);
        }
    }
    this->heuristicValue += lmCutValue;
}

void SearchNode::unitPropagation() {
    bool stateChanged = true;
    while (stateChanged && !this->singleOperatorLandmarks.empty()) {
        stateChanged = false;
        list<Landmark *>::iterator it = this->singleOperatorLandmarks.begin();
        while (it != this->singleOperatorLandmarks.end()) {
            // applyOperatorWithoutUpdate() will delete the entry in singleOperatorLandmarks
            // copy iterator so it can be used for erase without breaking the loop
            list<Landmark *>::iterator current = it;
            // increment iterator before (!!!) erase
            ++it;
            Landmark *unitClause = *current;
            RelaxedOperator *op = unitClause->begin()->first;
            if (op->isApplicable(this->currentState)) {
#ifdef FULL_DEBUG
                cout << endl << "Operator applied in unit propagation: " << op->name << endl;
#endif
                this->applyOperatorWithoutUpdate(op);
                stateChanged = true;
                this->unitPropagationCount++;
            }
        }
    }
}

