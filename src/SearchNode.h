#ifndef SEARCHNODE_H_
#define SEARCHNODE_H_

#include "Options.h"
#include "Landmark.h"
#include "RelaxedTask.h"

/*
 * Represents one node in the search space of the branch and bound search
 */
class SearchNode {
public:
    /*
     * Creates a search node for the initial state of 'task' where no operators have yet
     * been applied or forbidden.
     */
    SearchNode(const RelaxedTask &task, const OptimizationOptions &options);
    ~SearchNode();
    /*
     * Copies the node.
     */
    SearchNode(const SearchNode &other);
    /*
     * Throws an exception to avoid accidental usage.
     */
    SearchNode& operator=(const SearchNode &rhs);

    /*
     * applies the operator to the current state and updates the search node.
     * This should be done after copying the parent node.
     */
    SearchNode& applyOperator(const RelaxedOperator *const appliedOp);
    /*
     * forbids the operator in the subtree following this node and updates the search node.
     * This should be done after copying the parent node.
     */
    SearchNode& forbidOperator(RelaxedOperator *const forbiddenOp);
    /*
     * The lower bound consists of the cost to reach this node and the
     * heuristic estimate for the goal distance
     */
    UIntEx getCostLowerBound() const {
        return this->heuristicValue + this->currentCost;
    };

    UIntEx heuristicValue;
    unsigned int currentCost;
    State currentState;
    // plan used to reach this state
    Plan partialPlan;
    // Valid landmarks in this node, together with their cost partitioning.
    UnitCostLandmarkCollection landmarkCollection;
    // Cost function for the part of the cost partitioning that was not used in landmarks.
    OperatorCosts operatorCost;
    const RelaxedTask &task;
    // Number of operators applied in unit propagation in this node.
    int unitPropagationCount;

    //HACK
    mutable std::vector<const RelaxedOperator *> unitPropOps;

private:
    // Applies an operator and changes operator costs and landmarks accordingly
    // but does not update the heuristic value.
    // returns true if a heuristic update is necessary afterwards.
    bool applyOperatorWithoutUpdate(const RelaxedOperator *appliedOp);
    // Calls lmcut with the current cost function to discover new landmarks
    void updateHeuristicValue();
    // Tries to apply all 0-base-cost operators and operators in landmarks of size 1
    // without updating the heuristic value.
    void unitPropagation();
    // apply operator without update if it is applicable
    bool tryApplyUnitPropagationOperator(const RelaxedOperator *op);
    const OptimizationOptions &options;
};

#endif /* SEARCHNODE_H_ */
