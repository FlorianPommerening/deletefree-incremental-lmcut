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

    /*
     * The last layer is the layer in which a solution is discovered.
     * This is work that has to be done in Branch and Bound search as well.
     */
    int getExpansionCountLastLayer() const {
        return this->bnbSearch.getExpansionCount();
    }

    int getTimeLastLayer() const {
        return this->currentLayerTime;
    }

    /*
     * The second to last layer would be enough to proof that there is no better solution after a solution has been discovered.
     * This is the non-redundant part of the proof
     */
    int getExpansionCountSecondToLastLayer() const {
        return this->previousLayerExpansions;
    }

    int getTimeSecondToLastLayer() const {
        return this->previousLayerTime;
    }

    int getUnitPropagationCount() const {
        return this->unitPropagationCount;
    }
private:
    const RelaxedTask &task;
    BranchAndBoundSearch bnbSearch;
    const OptimizationOptions &options;
    int expansionCount;
    int previousLayerExpansions;
    int previousLayerTime;
    int currentLayerTime;
    int unitPropagationCount;
};



#endif /* IDASTARSEARCH_H_ */
