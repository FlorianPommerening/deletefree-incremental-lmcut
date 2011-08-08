#ifndef OPERATORSELECTOR_H_
#define OPERATORSELECTOR_H_

#include "Options.h"
#include "RelaxedOperator.h"
#include "SearchNode.h"
#include "UIntEx.h"

// forward declaration
class BranchAndBoundSearch;

/*
 * A strategy that defines which operator is applied or forbidden in each search node and whether it is applied first or forbidden first.
 */
class OperatorSelector {
public:
    OperatorSelector(OptimizationOptions &options): options(options) {}
    /*
     * A valid select method sets nextOperator to an operator applicable in searchNode.currentState or to NULL if there is no
     * choice that can lead to plan that reaches the goal with cost < costUpperBound.
     * addFirst defaults to true, but can be set to false if the successor where the operator is forbidden should be tried first.
     */
    virtual void select(SearchNode &searchNode, UIntEx &costUpperBound, RelaxedOperator **nextOperator, bool *addFirst) =0;
protected:
    OptimizationOptions &options;
};

/*
 * This operator selector always chooses an operator from a landmark of minimal size.
 * If no operator in a landmark is applicable, a (more or less) random applicable operator is chosen.
 * This behavior can be toggled in the options class
 */
class AchieveLandmarksOperatorSelector: public OperatorSelector {
public:
    AchieveLandmarksOperatorSelector(OptimizationOptions &options): OperatorSelector(options) {}
    void select(SearchNode &searchNode, UIntEx &costUpperBound, RelaxedOperator **nextOperator, bool *addFirst);
};

/*
 * This operator selector extends the AchieveLandmarksOperatorSelector by trying to apply the goal operator as soon as the heurist value is 0
 * This behavior can be toggled in the options class
 */
// TODO: this is somewhat redundant since operators with 0-cost are always applied in unit propagation
class AchieveLandmarksTryGoalOperatorSelector: public AchieveLandmarksOperatorSelector {
public:
    AchieveLandmarksTryGoalOperatorSelector(OptimizationOptions &options):
        AchieveLandmarksOperatorSelector(options), goalOperator(NULL) {}
    void select(SearchNode &searchNode, UIntEx &costUpperBound, RelaxedOperator **nextOperator, bool *addFirst);
private:
    RelaxedOperator *goalOperator;
};

/*
 * Try to use operators that achieves a variable in a source component of the strongly connected component graph
 * i.e. the strongly connected components of the graph that contains variables as nodes and an edge (x,y) iff
 * there is an operator o with x in pre(o) and y in add(o).
 * Landmarks size is used as a tie breaker among the operators that add variables in source components.
 */
class SSCOperatorSelector: public OperatorSelector {
public:
    SSCOperatorSelector(OptimizationOptions &options): OperatorSelector(options) {}
    void select(SearchNode &searchNode, UIntEx &costUpperBound, RelaxedOperator **nextOperator, bool *addFirst);
};
#endif /* OPERATORSELECTOR_H_ */
