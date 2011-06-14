#ifndef BRANCHANDBOUNDSEARCH_H_
#define BRANCHANDBOUNDSEARCH_H_

#include "RelaxedTask.h"
#include "SearchNode.h"
#include "OperatorSelector.h"

enum UpperBoundSpecialCases {
    INFINITY = -1,
};

class BranchAndBoundSearch  {
public:
    BranchAndBoundSearch(RelaxedTask &task, OperatorSelector &operatorSelector);
    int run();
private:
    RelaxedTask &task;
    OperatorSelector &operatorSelector;
    int costUpperBound;
    int recursiveBranchAndBound(SearchNode &searchNode);
};

#endif /* BRANCHANDBOUNDSEARCH_H_ */
