#include "OperatorSelector.h"

#include "foreach.h"
#include "Landmark.h"

#include <limits.h>
#include <stdexcept>

using namespace std;

void AchieveLandmarksOperatorSelector::select(SearchNode &searchNode, UIntEx &costUpperBound, RelaxedOperator **nextOperator, bool *addFirst) {
    *addFirst = true;
    *nextOperator = NULL;
    int best = INT_MAX;
    VariableSet &currentState = searchNode.currentState;
    foreach(Landmark &landmark, searchNode.landmarks) {
        if (*nextOperator != NULL && landmark.size() >= best)
            continue;
        foreach(Landmark::value_type &entry, landmark) {
            RelaxedOperator *op = entry.first;
            if (searchNode.operatorCost[op] != INFINITY && op->isApplicable(currentState)) {
                *nextOperator = op;
                best = landmark.size();
            }
        }
    }
    if (*nextOperator != NULL)
        return;
    // pick first applicable
    foreach(RelaxedOperator &op, searchNode.task->operators) {
        if (searchNode.operatorCost[&op] != INFINITY && op.isApplicable(currentState)) {
            *nextOperator = &op;
            return;
        }
    }
    // no operator applicable
}


AchieveLandmarksTryGoalOperatorSelector::AchieveLandmarksTryGoalOperatorSelector() : goalOperator(NULL) {
}

void AchieveLandmarksTryGoalOperatorSelector::select(SearchNode &searchNode, UIntEx &costUpperBound, RelaxedOperator **nextOperator, bool *addFirst) {
    if (this->goalOperator == NULL) {
        foreach(RelaxedOperator &op, searchNode.task->operators) {
            if (op.name == "@@goal-operator") {
                this->goalOperator = &op;
            }
        }
        if (this->goalOperator == NULL) {
            throw runtime_error("could not find goal operator");
        }
    }
    if (searchNode.heuristicValue == 0 && this->goalOperator->isApplicable(searchNode.currentState)) {
        *nextOperator = this->goalOperator;
        *addFirst = true;
        return;
    }
    // call base implementation to achieve landmark
    AchieveLandmarksOperatorSelector::select(searchNode, costUpperBound, nextOperator, addFirst);
}
