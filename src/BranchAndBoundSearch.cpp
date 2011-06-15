#include "BranchAndBoundSearch.h"

#include "foreach.h"
#include <iostream>
using namespace std;

BranchAndBoundSearch::BranchAndBoundSearch(RelaxedTask &task, OperatorSelector &operatorSelector) :
    task(task),
    operatorSelector(operatorSelector),
    costUpperBound(INFINITY) {
}

UIntEx BranchAndBoundSearch::run() {
    this->costUpperBound = INFINITY;
    SearchNode initialNode = SearchNode(this->task);
    return this->recursiveBranchAndBound(initialNode);
}

UIntEx BranchAndBoundSearch::recursiveBranchAndBound(SearchNode &searchNode) {
    // very heavy on the output, use only for bug tracing
    // printNode(searchNode, this->costUpperBound);

    if (searchNode.getCostLowerBound() >= this->costUpperBound) {
        return INFINITY;
    }
    // TODO could optimize this by saving goal in every VariableSet and setting a flag as soon as goal is added
    if (searchNode.currentState.contains(this->task.goal)) {
        this->costUpperBound = searchNode.currentCost;
        return this->costUpperBound;
    }

    RelaxedOperator *nextOperator = NULL;
    bool addFirst = true;
    this->operatorSelector.select(searchNode, this->costUpperBound, &nextOperator, &addFirst);
    if (nextOperator == NULL) {
        return INFINITY;
    }
    // TODO remove redundant operators???
    bool foundBetterPlan = false;
    SearchNode *successor = NULL;
    // iterate over 2 successors to avoid writing the same code twice
    for (int iSuc = 0; iSuc < 2; ++iSuc) {
        if (iSuc > 1) throw "There are only two successors. Do not call the loop more often!";
        bool first = (iSuc == 0);
        if (first ^ addFirst) {
            successor = new SearchNode(searchNode);
            successor->ForbidOperator(nextOperator);
        } else {
            successor = new SearchNode(searchNode);
            successor->ApplyOperator(nextOperator);
        }
        UIntEx planCost = this->recursiveBranchAndBound(*successor);
        if (planCost != INFINITY) {
            foundBetterPlan = true;
            if (searchNode.getCostLowerBound() >= this->costUpperBound)
                break;
        }
        delete successor; successor = NULL;
    }

    if (foundBetterPlan)
        return this->costUpperBound;
    // else
    return INFINITY;
}

void printNode(SearchNode &searchNode, UIntEx &upperBound) {
    std::cout << std::endl;
    std::cout << "BEGIN NODE (" << searchNode.currentCost << " + " << searchNode.heuristicValue << " = " << searchNode.getCostLowerBound() << " <= X <= " << upperBound << ")" << std::endl;
    std::cout << "Plan" << std::endl;
    foreach(RelaxedOperator *op, searchNode.partialPlan) {
        std::cout << op->name << ", ";
    }
    std::cout << std::endl;
    std::cout << "Forbidden" << std::endl;
    foreach(RelaxedOperator &op, searchNode.task->operators) {
        if (searchNode.operatorCost[&op] == INFINITY)
            std::cout << op.name << ", ";
    }
    std::cout << std::endl;
    std::cout << "Landmarks" << std::endl;
    foreach(Landmark &landmark, searchNode.landmarks) {
        foreach(Landmark::value_type &entry, landmark) {
            RelaxedOperator *op = entry.first;
            std::cout << op->name << ", ";
        }
        std::cout << std::endl;
    }
    std::cout << "END NODE" << std::endl;
}
