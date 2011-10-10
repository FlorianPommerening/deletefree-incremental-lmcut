#ifndef BRANCHANDBOUNDSEARCH_H_
#define BRANCHANDBOUNDSEARCH_H_

#include "Options.h"
#include "RelaxedTask.h"
#include "SearchNode.h"
#include "OperatorSelector.h"
#include "UIntEx.h"
#include "steinertreeImprove.h"

/*
 * Represents a search for h^+ for the initial state of a given task.
 * The search object allows to run the search and extract statistics after the search finished
 */
class BranchAndBoundSearch  {
public:
    /*
     * task: Must be a relaxed cross-referenced task in canonical form. h^+ is calculated for the initial state
     * operatorSelector: Determines which operator is chosen in each step of the search an whether it is applied first or forbidden first
     * options: allow to toggle some optimizations such as incremental computation of LM-cut.
     */
    BranchAndBoundSearch(const RelaxedTask &task, const OperatorSelector &operatorSelector, const OptimizationOptions &options);
    /*
     * Runs the branch and bound search and returns the h^+ value of the initial state.
     */
    UIntEx run();
    /*
     * Runs the branch and bound search and returns the h^+ value of the initial state if it is between initialLowerBound and initialUpperBound
     * and infinity in all other cases.
     */
    UIntEx run(const int initialLowerBound, const UIntEx initialUpperBound);

    UIntEx getCostUpperBound() const {
        return this->costUpperBound;
    }

    void setPlan(Plan &newPlan) {
        foreach(const RelaxedOperator *op, this->plan) {
            op->partOfCurrentBestPlan = false;
        }
        swap(this->plan, newPlan);
        foreach(const RelaxedOperator *op, this->plan) {
            op->partOfCurrentBestPlan = true;
        }
    }

    void setPlan(PlanSet &newPlanset) {
        Plan serializedPlan = serializePlan(newPlanset, this->task.init);
        setPlan(serializedPlan);
    }

    const std::vector<const RelaxedOperator *> &getPlan() const {
        return this->plan;
    }

    int getExpansionCount() const {
        return this->expansionCount;
    }

    int getUnitPropagationCount() const {
        return this->unitPropagationCount;
    }

    int getInitialPlanCost() const {
        return this->initialPlanCost;
    }

    float getInitialPlanTime() const {
        return this->initialPlanTime;
    }

    int getOptimizedInitialPlanCost() const {
        return this->optimizedInitialPlanCost;
    }

    float getOptimizedInitialPlanTime() const {
        return this->optimizedInitialPlanTime;
    }

    bool boundsOverlap(const SearchNode searchNode) const {
        UIntEx costLowerBound = searchNode.getCostLowerBound();
        if (costLowerBound < this->costLowerBound) {
            costLowerBound = this->costLowerBound;
        }
        return (costLowerBound > this->costUpperBound || (costLowerBound == this->costUpperBound && !this->plan.empty()));
    }
private:
    const RelaxedTask &task;
    const OperatorSelector &operatorSelector;
    const OptimizationOptions &options;
    /*
     * Cost of the currently best solution or infinity if no solution was found yet.
     */
    UIntEx costUpperBound;
    /*
     * Best proven approximation to h^+ from below. Currently the only time we can prove a lower
     * bound for the whole task is in the initial node. For all other search nodes, lower bounds
     * are only valid for the subtree rooted in the search node.
     * It is also possible to insert a lower bound at the start of the search to only look for solution in a specific range.
     */
    UIntEx costLowerBound;
    /*
     * Always contains the best plan discovered so far. If run() returns, this contains a plan with cost h^+.
     */
    Plan plan;
    /*
     * Number of nodes expanded during the search. A node counts as expanded, when at least one of its successors was generated.
     */
    int expansionCount;
    /*
     * Number of operators applied in unit propagation steps during the search.
     */
    int unitPropagationCount;

    /*
     * Initial upper bound found by Steiner tree improvement before optimization
     */
    int initialPlanCost;
    /*
     * Time used to calculate the initialPlan
     */
    float initialPlanTime;
    /*
     * Initial upper bound found by Steiner tree improvement after optimization
     */
    int optimizedInitialPlanCost;
    /*
     * Time used to optimize the initialPlan
     */
    float optimizedInitialPlanTime;

    /*
     * Returns the value of the best solution in the subtree starting in searchNode if it is cheaper than the current upper bound
     * or infinity if there is no (cheaper) solution in this subtree.
     */
    UIntEx recursiveBranchAndBound(const SearchNode &searchNode);
};

#endif /* BRANCHANDBOUNDSEARCH_H_ */
