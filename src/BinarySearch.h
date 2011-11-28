#ifndef BINARYSEARCH_H_
#define BINARYSEARCH_H_

#include "Options.h"
#include "RelaxedTask.h"
#include "OperatorSelector.h"
#include "UIntEx.h"
#include "BranchAndBoundSearch.h"

class BinarySearch  {
public:
    BinarySearch(const RelaxedTask &task, const OperatorSelector &operatorSelector, const OptimizationOptions &options);

    UIntEx run();

    UIntEx getCostUpperBound() const {
        return this->bnbSearch.getCostUpperBound();
    }

    const std::vector<const RelaxedOperator *> &getPlan() const {
        return this->bnbSearch.getPlan();
    }

    int getExpansionCount() const {
        return this->expansionCount;
    }

    int getUnitPropagationCount() const {
        return this->unitPropagationCount;
    }
private:
    const RelaxedTask &task;
    BranchAndBoundSearch bnbSearch;
    const OptimizationOptions &options;
    int expansionCount;
    int unitPropagationCount;
};



#endif /* BINARYSEARCH_H_ */
