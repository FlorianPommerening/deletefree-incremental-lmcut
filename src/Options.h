#ifndef OPTIONS_H_
#define OPTIONS_H_

// very heavy on the output, use only for bug tracing
// #define FULL_DEBUG

// TODO use command line options to set these instead of constants
struct OptimizationOptions {
    /*
     * Use the Steiner tree plan improvement procedure to calculate an initial upper bound
     */
    static const bool initialUpperBound = true;
    /*
     * Use the Steiner tree plan improvement procedure to improve plans found during the search
     */
    static const bool improveIntermediatePlans = true;
    /*
     * Use iterative deepening A* to search for h^+ (default is Branch-and-Bound-Search)
     */
    static const bool idaStarSearch = false;
    /*
     * selectOperatorInSmallestLandmark
     * true: An applicable operator contained a minimal size landmark is chosen in each step
     * false: The first applicable operator that is discovered is chosen in each step.
     */
    static const bool selectOperatorInSmallestLandmark = true;
    /*
     * If the heuristic value of a state is 0, the goal operator is always checked first for applicability
     */
    // TODO this is redundant now that 0-cost operators are applied during unit propagation
    static const bool tryGoalOnZeroHeuristic = true;
    /*
     * If set to true, all applicable operators in landmarks of size 1 are applied
     * without recalculating LM-cut every time after an operator is applied or forbidden.
     */
    static const bool autoApplyUnitLandmarks = true;
    /*
     * If set to true, all applicable operators with base cost 0 are applied
     * without recalculating LM-cut every time after an operator is applied or forbidden.
     */
    static const bool autoApplyZeroCostOperators = true;
    /*
     * If the first successor finds a perfect solution (one matching the heuristic prediction) the
     * second successor cannot find a better one and can be avoided.
     */
    static const bool avoidExpandingSecondSuccessor = true;
    /*
     * If set to true, the heuristic calculation re-uses old landmarks and only updates the cost partitioning
     * This leads to a shorter time per node but potentially worse landmarks.
     * If set to true, LM-cut is run with the default cost function in each step.
     */
    static const bool incrementalSearch = true;
    /*
     * If set to true, operators occurring in the current plan are preferred over
     * other operators in landmarks with minimal size (i.e. minimal size counts more than this)
     */
    static const bool preferOperatorsFromCurrentPlan = true;
    /*
     * If set to true, the search will only run until a first solution is discovered.
     * This is only useful to get an idea of the range in which h+ falls.
     * To emphasize that this doesn't calculate h+, the search returns infinity.
     */
    static const bool breakOnFirstSolution = false;

    // TODO somehow this doesn't work as static const int, so we set it in the c'tor for now (all of this should be changed to command line options anyway)
    /*
     * If this is set to a value other than 0, the search will stop after that amount of expansions and return infinity
     */
    int expansionLimit;

    OptimizationOptions() {
        expansionLimit = 0;
    }
};

#endif /* OPTIONS_H_ */
