#ifndef OPERATORSELECTOR_H_
#define OPERATORSELECTOR_H_

#include "RelaxedOperator.h"
#include "SearchNode.h"
#include "UIntEx.h"

class BranchAndBoundSearch;

class OperatorSelector {
public:
    virtual void select(SearchNode &searchNode, UIntEx &costUpperBound, RelaxedOperator **nextOperator, bool *addFirst) =0;
};

class AchieveLandmarksOperatorSelector: public OperatorSelector {
public:
    void select(SearchNode &searchNode, UIntEx &costUpperBound, RelaxedOperator **nextOperator, bool *addFirst);
};

#endif /* OPERATORSELECTOR_H_ */
