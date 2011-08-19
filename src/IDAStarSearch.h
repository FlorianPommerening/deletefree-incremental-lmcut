#ifndef IDASTARSEARCH_H_
#define IDASTARSEARCH_H_

#include "Options.h"
#include "RelaxedTask.h"
#include "OperatorSelector.h"
#include "UIntEx.h"
#include "BranchAndBoundSearch.h"

/*
 * Represents an iterative deepening A* search for h^+ for the initial state of a given task.
 * The search object allows to run the search and extract statistics after the search finished
 */
class IDAStarSearch  {
public:
    /*
     * task: Must be a relaxed cross-referenced task in canonical form. h^+ is calculated for the initial state
     * operatorSelector: Determines which operator is chosen in each step of the search an whether it is applied first or forbidden first
     * options: allow to toggle some optimizations such as incremental computation of LM-cut.
     */
    IDAStarSearch(const RelaxedTask &task, const OperatorSelector &operatorSelector, const OptimizationOptions &options);
    /*
     * Runs the ID-A* search and returns the h^+ value of the initial state.
     */
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

    int getExpansionCountLastLayer() const {
        return this->bnbSearch.getExpansionCount();
    }

    int getUnitPropagationCount() const {
        return this->unitPropagationCount;
    }
private:
    const RelaxedTask &task;
    BranchAndBoundSearch bnbSearch;
    int expansionCount;
    int unitPropagationCount;
};



#endif /* IDASTARSEARCH_H_ */
