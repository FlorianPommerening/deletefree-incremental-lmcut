#ifndef BRANCHANDBOUNDSEARCH_H_
#define BRANCHANDBOUNDSEARCH_H_

#include "RelaxedTask.h"
#include "LMCut.h"
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
    int recursiveBranchAndBound(LMCutState &lmcutState);
};

#endif /* BRANCHANDBOUNDSEARCH_H_ */
