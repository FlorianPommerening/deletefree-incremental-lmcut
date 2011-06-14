#include "OperatorSelector.h"

#include "foreach.h"
#include "Landmark.h"

#include "limits.h"

void AchieveLandmarksOperatorSelector::select(SearchNode &searchNode, int costUpperBound, RelaxedOperator *nextOperator, bool *addFirst) {
    *addFirst = true;
    nextOperator = NULL;
    int best = INT_MAX;
    VariableSet &currentState = searchNode.currentState;
    foreach(Landmark &landmark, searchNode.landmarks) {
        if (nextOperator != NULL && landmark.size() >= best)
            continue;
        foreach(Landmark::value_type &entry, landmark) {
            RelaxedOperator *op = entry.first;
            if (op->isApplicable(currentState)) {
                nextOperator = op;
                best = landmark.size();
            }
        }
    }
    if (nextOperator != NULL)
        return;
    // pick first applicable
    foreach(RelaxedOperator &op, searchNode.task->operators) {
        if (op.isApplicable(currentState)) {
            nextOperator = &op;
            return;
        }
    }
    // no operator applicable
}
