#ifndef BRANCHANDBOUNDSEARCH_H_
#define BRANCHANDBOUNDSEARCH_H_

#include "RelaxedTask.h"
#include "SearchNode.h"
#include "OperatorSelector.h"
#include "UIntEx.h"

class BranchAndBoundSearch  {
public:
    BranchAndBoundSearch(RelaxedTask &task, OperatorSelector &operatorSelector);
    UIntEx run();
private:
    RelaxedTask &task;
    OperatorSelector &operatorSelector;
    UIntEx costUpperBound;
    UIntEx recursiveBranchAndBound(SearchNode &searchNode);
};

#endif /* BRANCHANDBOUNDSEARCH_H_ */
