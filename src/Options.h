#ifndef OPTIONS_H_
#define OPTIONS_H_

// very heavy on the output, use only for bug tracing
// #define FULL_DEBUG

// TODO use command line options to set these instead of constants
struct OptimizationOptions {
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
     * If set to true, the search will only run until a first solution is discovered.
     * This is only useful to get an idea of the range in which h+ falls.
     * To emphasize that this doesn't calculate h+, the search returns infinity.
     */
    static const bool breakOnFirstSolution = false;
};

#endif /* OPTIONS_H_ */
