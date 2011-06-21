#include "SearchNode.h"
#include "foreach.h"
#include "hmax.h"
#include "lmcut.h"

#include <stack>

using namespace std;

SearchNode::SearchNode(RelaxedTask &task):
        heuristicValue(0),
        currentCost(0),
        task(&task) {
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
                    task(other.task) {
    foreach(Landmark &landmark, this->landmarks) {
        foreach(Landmark::value_type &entry, landmark) {
            RelaxedOperator *op = entry.first;
            this->operatorToLandmark[op] = &landmark;
        }
    }
}

SearchNode& SearchNode::operator=(const SearchNode &rhs) {
    throw "Assignment operator should not be used for SearchNode";
}

SearchNode& SearchNode::applyOperator(RelaxedOperator *appliedOp) {
    this->applyOperatorWithoutUpdate(appliedOp);
    this->unitPropagation();
    this->updateHeuristicValue();
    return *this;
}

SearchNode& SearchNode::forbidOperator(RelaxedOperator *forbiddenOp) {
    this->operatorCost[forbiddenOp] = INFINITY;
    map<RelaxedOperator *, Landmark *>::iterator it = this->operatorToLandmark.find(forbiddenOp);
    if (it != this->operatorToLandmark.end()) {
        Landmark *containingLM = this->operatorToLandmark[forbiddenOp];
        // remove operator from landmark. If it was the only one,
        // the problem becomes unsolvable
        int oldLandmarkCost = containingLM->cost;
        containingLM->remove(forbiddenOp);
        int newLandmarkCost = containingLM->cost;
        if (containingLM->size() == 0) {
            this->heuristicValue = INFINITY;
            return *this;
        } else if (containingLM->size() == 1) {
            this->singleOperatorLandmarks.push_back(containingLM);
        }
        this->heuristicValue -= (oldLandmarkCost - newLandmarkCost);
    }
    // search for additional landmarks
    this->unitPropagation();
    this->updateHeuristicValue();
    return *this;
}


void SearchNode::applyOperatorWithoutUpdate(RelaxedOperator *appliedOp) {
    appliedOp->apply(this->currentState);
    partialPlan.push_back(appliedOp);
    this->currentCost += appliedOp->baseCost;
    this->operatorCost[appliedOp] = INFINITY;
    map<RelaxedOperator *, Landmark *>::iterator it = this->operatorToLandmark.find(appliedOp);
    if (it != this->operatorToLandmark.end()) {
        Landmark *containingLM = this->operatorToLandmark[appliedOp];
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
        this->landmarks.remove(*containingLM);
        this->operatorToLandmark.erase(it);
    }
}

void SearchNode::updateHeuristicValue() {
    // HACK find a better way to do this
    bool hadPreviousLandmarks = !this->landmarks.empty();
    list<Landmark>::iterator it;
    if (hadPreviousLandmarks) {
        // remember last landmark, to update only new landmarks
        it = --this->landmarks.end();
    }
    UIntEx lmCutValue = lmCut(*(this->task), this->currentState, this->operatorCost, this->landmarks);
    if (hadPreviousLandmarks) {
        // move iterator to first new landmark;
        it++;
    } else {
        it = this->landmarks.begin();
    }
    for (;it != this->landmarks.end(); ++it) {
        Landmark &landmark = *it;
        foreach(Landmark::value_type &entry, landmark) {
            RelaxedOperator *op = entry.first;
            this->operatorToLandmark[op] = &landmark;
            if (landmark.size() == 1) {
                this->singleOperatorLandmarks.push_back(&landmark);
            }
        }
    }
    //TODO use 'it' to update operatorToLandmark and singleOperatorLandmarks instead of doing it in lmCut
    // use 'it' as reference parameter and make it point to the first inserted landmark

    this->heuristicValue += lmCutValue;
}

void SearchNode::unitPropagation() {
    bool stateChanged = true;
    while (stateChanged && !this->singleOperatorLandmarks.empty()) {
        stateChanged = false;
        list<Landmark *>::iterator it = this->singleOperatorLandmarks.begin();
        while (it != this->singleOperatorLandmarks.end()) {
            // copy iterator so it can be used for erase without breaking the loop
            list<Landmark *>::iterator current = it;
            // increment iterator before (!!!) erase
            ++it;
            Landmark *unitClause = *current;
            RelaxedOperator *op = unitClause->begin()->first;
            if (op->isApplicable(this->currentState)) {
                this->applyOperatorWithoutUpdate(op);
                stateChanged = true;
            }
            this->singleOperatorLandmarks.erase(current);
        }
    }
    this->updateHeuristicValue();
}

