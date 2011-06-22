#ifndef OPTIONS_H_
#define OPTIONS_H_

// very heavy on the output, use only for bug tracing
// #define FULL_DEBUG

// TODO use command line options to set these instead of constants
struct OptimizationOptions {
    static const bool selectOperatorInSmallestLandmark = true;
    static const bool tryGoalOnZeroHeuristic = true;
    static const bool useUnitPropagation = true;
    static const bool avoidExpandingSecondSuccessor = true;
};

#endif /* OPTIONS_H_ */
