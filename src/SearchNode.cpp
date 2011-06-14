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
                    task(other.task),
                    landmarks(other.landmarks),
                    operatorCost(other.operatorCost){
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

SearchNode& SearchNode::ApplyOperator(RelaxedOperator *appliedOp) {
    appliedOp->apply(this->currentState);
    partialPlan.push_back(appliedOp);
    this->currentCost += appliedOp->baseCost;
    this->operatorCost[appliedOp] = FORBIDDEN;
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
                this->operatorCost[op] -= landmarkCost;
            }
        }
        this->landmarks.remove(*containingLM);
        this->operatorToLandmark.erase(it);
    }
    // search for additional landmarks
    this->updateHeuristicValue();
    return *this;
}

SearchNode& SearchNode::ForbidOperator(RelaxedOperator *forbiddenOp) {
    this->operatorCost[forbiddenOp] = FORBIDDEN;
    map<RelaxedOperator *, Landmark *>::iterator it = this->operatorToLandmark.find(forbiddenOp);
    if (it != this->operatorToLandmark.end()) {
        Landmark *containingLM = this->operatorToLandmark[forbiddenOp];
        // remove operator from landmark. If it was the only one,
        // the problem becomes unsolvable
        int oldLandmarkCost = containingLM->cost;
        containingLM->remove(forbiddenOp);
        int newLandmarkCost = containingLM->cost;
        if (containingLM->size() == 0) {
            this->heuristicValue = UNSOLVABLE;
            return *this;
        }
        this->heuristicValue -= (oldLandmarkCost - newLandmarkCost);
    }
    // search for additional landmarks
    this->updateHeuristicValue();
    return *this;
}

void SearchNode::updateHeuristicValue() {
    int lmCutValue = lmCut(*(this->task), this->currentState, this->operatorCost,
                           this->landmarks, this->operatorToLandmark);
    if (lmCutValue == UNSOLVABLE)
        this->heuristicValue = UNSOLVABLE;
    else
        this->heuristicValue += lmCutValue;
}
