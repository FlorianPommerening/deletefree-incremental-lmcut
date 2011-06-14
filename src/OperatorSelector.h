#ifndef OPERATORSELECTOR_H_
#define OPERATORSELECTOR_H_

#include "RelaxedOperator.h"

class BranchAndBoundSearch;

class OperatorSelector {
public:
    void select(BranchAndBoundSearch &search, RelaxedOperator *nextOperator, bool *addFirst);
};

#endif /* OPERATORSELECTOR_H_ */
