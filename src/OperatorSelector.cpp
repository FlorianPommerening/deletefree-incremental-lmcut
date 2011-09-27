#include "OperatorSelector.h"

#include "foreach.h"
#include "Landmark.h"
#include "GabowSCC.h"

#include <limits.h>
#include <stdexcept>
#include <stdlib.h>

using namespace std;

void AchieveLandmarksOperatorSelector::select(const SearchNode &searchNode, const UIntEx &costUpperBound, RelaxedOperator **nextOperator, bool *addFirst) const {
    *addFirst = true;
    *nextOperator = NULL;
    const State &currentState = searchNode.currentState;
    if (this->options.selectOperatorInSmallestLandmark) {
        vector<RelaxedOperator *> possibleChoices;
        int best = INT_MAX;
        int nLandmarks = searchNode.landmarkCollection.getValidLandmarkIds();
        for(LandmarkId landmarkId=0; landmarkId < nLandmarks; ++landmarkId) {
            // landmarks of size 1 are handled in unit propagation, but
            // an operator contained in a landmark of size 1 can still be applicable here if the landmark
            // was discovered after the last unit propagation, so do NOT ignore it
            //if (this->options.useUnitPropagation && landmark.size() == 1) {
            //    continue;
            //}
            int landmarkSize = searchNode.landmarkCollection.getSize(landmarkId);
            if (landmarkSize > best) {
                // we already know better operators
                continue;
            }
            foreach(RelaxedOperator *op, searchNode.landmarkCollection.iterateLandmark(landmarkId)) {
                if (searchNode.operatorCost[op->id].hasFiniteValue() && op->isApplicable(currentState)) {
                    if (landmarkSize < best) {
                        // forget operators in larger LMs
                        possibleChoices.clear();
                    }
                    best = landmarkSize;
                    possibleChoices.push_back(op);
                }
            }
        }
        // pick an operator from a smallest LM uniformly at random
        if (!possibleChoices.empty()) {
#ifdef FULL_DEBUG
            if (possibleChoices.size() == 1) {
                cout << endl << "Only 1 applicable operator in landmarks of minimal size" << endl;
            } else {
                cout << endl << "Choosing operator from " << possibleChoices.size() << " possible choices in landmarks of minimal size" << endl;
            }
#endif
            *nextOperator = possibleChoices[rand() % possibleChoices.size()];
            // *nextOperator = possibleChoices[0];
            // *nextOperator = possibleChoices[possibleChoices.size() -1];
            return;
        }
    }
    // pick first applicable
    foreach(RelaxedOperator *op, searchNode.task.operators) {
        if (searchNode.operatorCost[op->id].hasFiniteValue() && op->isApplicable(currentState)) {
            *nextOperator = op;
            return;
        }
    }
    // no operator applicable
}

void AchieveLandmarksTryGoalOperatorSelector::select(SearchNode &searchNode, UIntEx &costUpperBound, RelaxedOperator **nextOperator, bool *addFirst) {
    if (this->options.tryGoalOnZeroHeuristic) {
        if (this->goalOperator == NULL) {
            // determine and remember the goal operator once
            foreach(RelaxedOperator *op, searchNode.task.operators) {
                if (op->name == "@@goal-operator") {
                    this->goalOperator = op;
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


void SSCOperatorSelector::select(SearchNode &searchNode, UIntEx &costUpperBound, RelaxedOperator **nextOperator, bool *addFirst) {
    *addFirst = true;
    *nextOperator = NULL;
    GabowSCC &gabowSCC = GabowSCC::Instance();
    State &currentState = searchNode.currentState;
    vector<RelaxedOperator *> applicableOperators;
    applicableOperators.reserve(searchNode.task.operators.size());
    // remove all applicable operators for the SCC graph generation
    OperatorCosts operatorCostSCC = searchNode.operatorCost;
    foreach(RelaxedOperator *op, searchNode.task.operators) {
        if (op->isApplicable(currentState)) {
            applicableOperators.push_back(op);
            operatorCostSCC[op->id] = UIntEx::INF;
        }
    }
    gabowSCC.findSourceConnectedComponents(searchNode.task.variables, operatorCostSCC);
    vector<RelaxedOperator *> applicableOperatorsInSourceComponents;
    applicableOperatorsInSourceComponents.reserve(applicableOperators.size());
    // tie breaking with landmarks
    int bestLandmarkSize = INT_MAX;
    RelaxedOperator *best = NULL;
    foreach(RelaxedOperator *op, applicableOperators) {
        foreach(Variable *v, op->effects) {
            if (gabowSCC.isInSourceComponent(v)) {
                LandmarkId landmarkId = searchNode.landmarkCollection.containingLandmark(op);
                if (landmarkId != -1) {
                    if (searchNode.landmarkCollection.getSize(landmarkId) < bestLandmarkSize) {
                        best = op;
                    }
                }
                applicableOperatorsInSourceComponents.push_back(op);
                break;
            }
        }
    }
    if (best != NULL) {
        *nextOperator = best;
    }
    else if (applicableOperatorsInSourceComponents.size() > 0) {
        *nextOperator = applicableOperatorsInSourceComponents.front();
    }
    else {
        *nextOperator = NULL;
    }
}
