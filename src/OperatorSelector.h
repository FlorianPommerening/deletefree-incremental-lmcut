#ifndef OPERATORSELECTOR_H_
#define OPERATORSELECTOR_H_

#include "Options.h"
#include "RelaxedOperator.h"
#include "SearchNode.h"
#include "UIntEx.h"

class BranchAndBoundSearch;

class OperatorSelector {
public:
    OperatorSelector(OptimizationOptions &options): options(options) {}
    virtual void select(SearchNode &searchNode, UIntEx &costUpperBound, RelaxedOperator **nextOperator, bool *addFirst) =0;
protected:
    OptimizationOptions &options;
};

class AchieveLandmarksOperatorSelector: public OperatorSelector {
public:
    AchieveLandmarksOperatorSelector(OptimizationOptions &options): OperatorSelector(options) {}
    void select(SearchNode &searchNode, UIntEx &costUpperBound, RelaxedOperator **nextOperator, bool *addFirst);
};

class AchieveLandmarksTryGoalOperatorSelector: public AchieveLandmarksOperatorSelector {
public:
    AchieveLandmarksTryGoalOperatorSelector(OptimizationOptions &options):
        AchieveLandmarksOperatorSelector(options), goalOperator(NULL) {}
    void select(SearchNode &searchNode, UIntEx &costUpperBound, RelaxedOperator **nextOperator, bool *addFirst);
private:
    RelaxedOperator *goalOperator;
};

#endif /* OPERATORSELECTOR_H_ */
