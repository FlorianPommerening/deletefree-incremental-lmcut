#include "BranchAndBoundSearch.h"

#include "foreach.h"
#include <iostream>

using namespace std;

/*
 * Only used in full debug mode. Outputs the node with all details to stdout
 */
void printNode(SearchNode &searchNode, UIntEx &upperBound);

BranchAndBoundSearch::BranchAndBoundSearch(RelaxedTask &task, OperatorSelector &operatorSelector, OptimizationOptions &options) :
    expansionCount(0),
    unitPropagationCount(0),
    task(task),
    operatorSelector(operatorSelector),
    options(options),
    costUpperBound(UIntEx::INF),
    costLowerBound(0) {
}

UIntEx BranchAndBoundSearch::run() {
    // reset values
    this->costUpperBound = UIntEx::INF;
    this->expansionCount = 0;
    this->unitPropagationCount = 0;
    // construct search node representing the initial state without any forbidden or applied operators
    SearchNode initialNode = SearchNode(this->task, this->options);
    this->costLowerBound = initialNode.heuristicValue;
    cout << "    Starting with bounds (" << this->costLowerBound << "-" << this->costUpperBound << ")" << endl;
    return this->recursiveBranchAndBound(initialNode);
}

UIntEx BranchAndBoundSearch::recursiveBranchAndBound(SearchNode &searchNode) {
    if (this->options.breakOnFirstSolution && this->plan.size() > 0) {
        return UIntEx::INF;
    }
#ifdef FULL_DEBUG
    printNode(searchNode, this->costUpperBound);
#endif
    // The heuristic estimate never overestimates, so in this case the best solution in this subtree can at most be as cheap as the current best.
    // This means there is no _better_ solution in this subtree.
    if (searchNode.getCostLowerBound() >= this->costUpperBound) {
#ifdef FULL_DEBUG
        cout << endl << "Exceeded bound (" << searchNode.getCostLowerBound() << " >= " << this->costUpperBound << ")" << endl << endl;
#endif
        return UIntEx::INF;
    }

    // Have we reached the goal? If so, update the current best solution and return with its cost.
    // Test on heuristic == 0 is faster than subset test and should filter out most of the nodes during the search.
    // TODO could optimize this by saving goal in every VariableSet and setting a flag as soon as goal is added
    if (searchNode.heuristicValue == 0 && searchNode.currentState.contains(this->task.goal)) {
        this->costUpperBound = searchNode.currentCost;
        this->plan.clear();
        this->plan.assign(searchNode.partialPlan.begin(), searchNode.partialPlan.end());
        cout << "    New Solution, updated bounds (" << this->costLowerBound << "-" << this->costUpperBound << ")" << endl;
        return this->costUpperBound;
    }

    // If this is not a goal yet we need to choose an operator and apply it now or remove it from the problem.
    RelaxedOperator *nextOperator = NULL;
    // if addFirst == true the successor that applies the operator is is tried first, otherwise it is tried as the second choice.
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
    // iterate over 2 successors to avoid writing the same code twice.
    // it would be easier to iterate directly over the two values of bool to determine if we are considering the first or second successor.
    for (int iSuc = 0; iSuc < 2; ++iSuc) {
        if (iSuc > 1) {
            // this is just here so no one changes the number of loops ;-)
            throw "There are only two successors. Do not call the loop more often!";
        }
        bool first = (iSuc == 0);
        // make a copy of the current search node that can be changed.
        successor = new SearchNode(searchNode);
        if (first ^ addFirst) {
#ifdef FULL_DEBUG
            cout << endl << "Forbidding operator " << nextOperator->name << endl;
#endif
            successor->forbidOperator(nextOperator);
        } else {
#ifdef FULL_DEBUG
            cout << endl << "Applying operator " << nextOperator->name << endl;
#endif
            successor->applyOperator(nextOperator);
        }
        this->expansionCount++;
        // Applying or forbidding an operator could have lead to unit propagations; add them to the running total.
        this->unitPropagationCount += successor->unitPropagationCount;
        // recursively continue the search in depth first manner
        UIntEx planCost = this->recursiveBranchAndBound(*successor);
        // a finite return value means, that a better solution was found in this subtree
        if (planCost.hasFiniteValue()) {
            foundBetterPlan = true;
            // When expanding the first successor lead to a solution with the cost previously predicted by the heuristic
            // the second successor cannot yield a better solution. In this case generating the second successor (and
            // possibly calculating LM-cut for it) can be avoided.
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
    foreach(RelaxedOperator *op, searchNode.task.operators) {
        if (!searchNode.operatorCost[op->id].hasFiniteValue()) {
            std::cout << op->name << ", ";
        }
    }
    std::cout << std::endl;
    std::cout << "Landmarks" << std::endl;
    int nLandmarks = searchNode.landmarkCollection.getValidLandmarkIds();
    for(LandmarkId landmarkId=0; landmarkId < nLandmarks; ++landmarkId) {
        foreach(RelaxedOperator *op, searchNode.landmarkCollection.iterateLandmark(landmarkId)) {
            std::cout << op->name << ", ";
        }
        std::cout << std::endl;
    }
    std::cout << "END NODE" << std::endl;
}
