#ifndef SEARCHNODE_H_
#define SEARCHNODE_H_

#include <list>

#include "Options.h"
#include "Landmark.h"
#include "RelaxedTask.h"
#include "PointerMap.h"

/*
 * Represents one node in the search space of the branch and bound search
 */
class SearchNode {
public:
    /*
     * Creates a search node for the initial state of 'task' where no operators have yet
     * been applied or forbidden.
     */
    SearchNode(RelaxedTask &task, OptimizationOptions &options);
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
    SearchNode& applyOperator(RelaxedOperator *appliedOp);
    /*
     * forbids the operator in the subtree following this node and updates the search node.
     * This should be done after copying the parent node.
     */
    SearchNode& forbidOperator(RelaxedOperator *forbiddenOp);
    /*
     * The lower bound consists of the cost to reach this node and the
     * heuristic estimate for the goal distance
     */
    UIntEx getCostLowerBound() {
        return this->heuristicValue + this->currentCost;
    };

    UIntEx heuristicValue;
    unsigned int currentCost;
    State currentState;
    // plan used to reach this state
    std::list<RelaxedOperator *> partialPlan;
    // Valid landmarks in this node, together with their cost partitioning.
    // Has to be a list so pointers stay valid, when removing landmarks.
    std::list<Landmark> landmarks;
    // Cost function for the part of the cost partitioning that was not used in landmarks.
    OperatorCosts operatorCost;
    RelaxedTask &task;
    // Number of operators applied in unit propagation in this node.
    int unitPropagationCount;
    // maps operators to landmarks (only possible in unit cost tasks)
    PointerMap<RelaxedOperator, Landmark *> operatorToLandmark;
    std::list<Landmark *> getSingleOperatorLandmarks() {
        return this->singleOperatorLandmarks;
    }
private:
    // Applies an operator and changes operator costs and landmarks accordingly
    // but does not update the heuristic value.
    // returns true if a heuristic update is necessary afterwards.
    bool applyOperatorWithoutUpdate(RelaxedOperator *appliedOp);
    // Calls lmcut with the current cost function to discover new landmarks
    void updateHeuristicValue();
    // Tries to apply all 0-base-cost operators and operators in landmarks of size 1
    // without updating the heuristic value.
    void unitPropagation();
    // apply operator without update if it is applicable
    bool tryApplyUnitPropagationOperator(RelaxedOperator *op);
    // list of landmarks that could be used for unit propagation
    std::list<Landmark *> singleOperatorLandmarks;
    OptimizationOptions &options;
};

#endif /* SEARCHNODE_H_ */
