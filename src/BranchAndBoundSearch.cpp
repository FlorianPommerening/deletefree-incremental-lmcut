#include "BranchAndBoundSearch.h"

#include "foreach.h"
#include <iostream>

using namespace std;

void printNode(SearchNode &searchNode, UIntEx &upperBound);

BranchAndBoundSearch::BranchAndBoundSearch(RelaxedTask &task, OperatorSelector &operatorSelector, OptimizationOptions &options) :
    task(task),
    operatorSelector(operatorSelector),
    options(options),
    costUpperBound(UIntEx::INF) {
}

UIntEx BranchAndBoundSearch::run() {
    this->costUpperBound = UIntEx::INF;
    this->expansionCount = 0;
    this->unitPropagationCount = 0;
    SearchNode initialNode = SearchNode(this->task, this->options);
    return this->recursiveBranchAndBound(initialNode);
}

UIntEx BranchAndBoundSearch::recursiveBranchAndBound(SearchNode &searchNode) {
#ifdef FULL_DEBUG
    printNode(searchNode, this->costUpperBound);
#endif
    if (searchNode.getCostLowerBound() >= this->costUpperBound) {
#ifdef FULL_DEBUG
        cout << endl << "Exceeded bound (" << searchNode.getCostLowerBound() << " >= " << this->costUpperBound << ")" << endl << endl;
#endif
        return UIntEx::INF;
    }

    // TODO could optimize this by saving goal in every VariableSet and setting a flag as soon as goal is added
    if (searchNode.currentState.contains(this->task.goal)) {
        this->costUpperBound = searchNode.currentCost;
        this->plan.clear();
        this->plan.assign(searchNode.partialPlan.begin(), searchNode.partialPlan.end());
#ifdef FULL_DEBUG
        cout << endl << "New Solution, updated bound (" << this->costUpperBound << ")" << endl << endl;
#endif
        return this->costUpperBound;
    }

    RelaxedOperator *nextOperator = NULL;
    bool addFirst = true;
    this->operatorSelector.select(searchNode, this->costUpperBound, &nextOperator, &addFirst);
    if (nextOperator == NULL) {
#ifdef FULL_DEBUG
        cout << endl << "No more applicable operators. Backtracking" << endl << endl;
#endif
        return UIntEx::INF;
    }
    // TODO remove redundant operators???
    bool foundBetterPlan = false;
    SearchNode *successor = NULL;
    // iterate over 2 successors to avoid writing the same code twice
    for (int iSuc = 0; iSuc < 2; ++iSuc) {
        if (iSuc > 1) {
            throw "There are only two successors. Do not call the loop more often!";
        }
        bool first = (iSuc == 0);
        if (first ^ addFirst) {
#ifdef FULL_DEBUG
            cout << endl << "Forbidding operator " << nextOperator->name << endl;
#endif
            successor = new SearchNode(searchNode);
            successor->forbidOperator(nextOperator);
        } else {
#ifdef FULL_DEBUG
            cout << endl << "Applying operator " << nextOperator->name << endl;
#endif
            successor = new SearchNode(searchNode);
            successor->applyOperator(nextOperator);
        }
        this->expansionCount++;
        this->unitPropagationCount += successor->unitPropagationCount;
        UIntEx planCost = this->recursiveBranchAndBound(*successor);
        if (planCost != UIntEx::INF) {
            foundBetterPlan = true;
            if (this->options.avoidExpandingSecondSuccessor && searchNode.getCostLowerBound() >= this->costUpperBound) {
#ifdef FULL_DEBUG
                cout << endl << "Found perfect solution for this subtree, ignoring second successor" << endl;
#endif
                delete successor; successor = NULL;
                break;
            }
        }
        delete successor; successor = NULL;
    }

    if (foundBetterPlan) {
#ifdef FULL_DEBUG
        cout << endl << "Backtracking with better plan of cost " << this->costUpperBound << endl;
#endif
        return this->costUpperBound;
    }
    // else
#ifdef FULL_DEBUG
    cout << endl << "Backtracking without better plan" << endl;
#endif
    return UIntEx::INF;
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
    foreach(RelaxedOperator &op, searchNode.task.operators) {
        if (searchNode.operatorCost[&op] == UIntEx::INF) {
            std::cout << op.name << ", ";
        }
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
