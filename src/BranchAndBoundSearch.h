#ifndef BRANCHANDBOUNDSEARCH_H_
#define BRANCHANDBOUNDSEARCH_H_

#include "Options.h"
#include "RelaxedTask.h"
#include "SearchNode.h"
#include "OperatorSelector.h"
#include "UIntEx.h"

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
    BranchAndBoundSearch(RelaxedTask &task, OperatorSelector &operatorSelector, OptimizationOptions &options);
    /*
     * Runs the branch and bound search and returns the h^+ value of the initial state.
     */
    UIntEx run();

    /*
     * Always contains the best plan discovered so far. If run() returns, this contains a plan with cost h^+.
     */
    std::list<RelaxedOperator *> plan;
    /*
     * Number of nodes expanded during the search. A node counts as expanded, when at least one of its successors was generated.
     */
    int expansionCount;
    /*
     * Number of operators applied in unit propagation steps during the search.
     */
    int unitPropagationCount;
private:
    RelaxedTask &task;
    OperatorSelector &operatorSelector;
    OptimizationOptions &options;
    /*
     * cost of the currently best solution or infinity if no solution was found yet.
     */
    UIntEx costUpperBound;
    /*
     * Returns the value of the best solution in the subtree starting in searchNode if it is cheaper than the current upper bound
     * or infinity if there is no (cheaper) solution in this subtree.
     */
    UIntEx recursiveBranchAndBound(SearchNode &searchNode);
};

#endif /* BRANCHANDBOUNDSEARCH_H_ */
