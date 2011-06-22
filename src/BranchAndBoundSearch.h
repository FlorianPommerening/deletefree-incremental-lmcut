#ifndef BRANCHANDBOUNDSEARCH_H_
#define BRANCHANDBOUNDSEARCH_H_

#include "Options.h"
#include "RelaxedTask.h"
#include "SearchNode.h"
#include "OperatorSelector.h"
#include "UIntEx.h"

class BranchAndBoundSearch  {
public:
    BranchAndBoundSearch(RelaxedTask &task, OperatorSelector &operatorSelector, OptimizationOptions &options);
    UIntEx run();
    std::list<RelaxedOperator *> plan;
    int expansionCount;
    int unitPropagationCount;
private:
    RelaxedTask &task;
    OperatorSelector &operatorSelector;
    OptimizationOptions &options;
    UIntEx costUpperBound;
    UIntEx recursiveBranchAndBound(SearchNode &searchNode);
};

#endif /* BRANCHANDBOUNDSEARCH_H_ */
