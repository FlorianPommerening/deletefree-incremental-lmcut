#include "OperatorSelector.h"

#include "foreach.h"
#include "Landmark.h"

#include <limits.h>
#include <stdexcept>

using namespace std;

void AchieveLandmarksOperatorSelector::select(SearchNode &searchNode, UIntEx &costUpperBound, RelaxedOperator **nextOperator, bool *addFirst) {
    *addFirst = true;
    *nextOperator = NULL;
    VariableSet &currentState = searchNode.currentState;
    if (this->options.selectOperatorInSmallestLandmark) {
        int best = INT_MAX;
        foreach(Landmark &landmark, searchNode.landmarks) {
            // landmarks of size 1 are handled in unit propagation, but
            // an operator contained in a landmark of size 1 can still be applicable here if the landmark
            // was discovered after the last unit propagation, so do NOT ignore it
            //if (this->options.useUnitPropagation && landmark.size() == 1) {
            //    continue;
            //}
            if (*nextOperator != NULL && landmark.size() >= best) {
                // we already know an operator at least as good
                continue;
            }
            foreach(Landmark::value_type &entry, landmark) {
                RelaxedOperator *op = entry.first;
                if (searchNode.operatorCost[op] != UIntEx::INF && op->isApplicable(currentState)) {
                    *nextOperator = op;
                    best = landmark.size();
                }
            }
        }
        if (*nextOperator != NULL) {
            return;
        }
    }
    // pick first applicable
    foreach(RelaxedOperator &op, searchNode.task.operators) {
        if (searchNode.operatorCost[&op] != UIntEx::INF && op.isApplicable(currentState)) {
            *nextOperator = &op;
            return;
        }
    }
    // no operator applicable
}

void AchieveLandmarksTryGoalOperatorSelector::select(SearchNode &searchNode, UIntEx &costUpperBound, RelaxedOperator **nextOperator, bool *addFirst) {
    if (this->options.tryGoalOnZeroHeuristic) {
        if (this->goalOperator == NULL) {
            // determine and remember the goal operator once
            foreach(RelaxedOperator &op, searchNode.task.operators) {
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
    }
    // call base implementation to achieve landmark
    AchieveLandmarksOperatorSelector::select(searchNode, costUpperBound, nextOperator, addFirst);
}
