#include "BranchAndBoundSearch.h"

#include "foreach.h"
#include "Timer.h"

#include <iostream>

using namespace std;

/*
 * Only used in full debug mode. Outputs the node with all details to stdout
 */
void printNode(const SearchNode &searchNode, const UIntEx &upperBound);

BranchAndBoundSearch::BranchAndBoundSearch(const RelaxedTask &task, const OperatorSelector &operatorSelector, const OptimizationOptions &options) :
    task(task),
    operatorSelector(operatorSelector),
    options(options),
    costUpperBound(UIntEx::INF),
    costLowerBound(0),
    expansionCount(0),
    unitPropagationCount(0),
    initialPlanCost(0),
    initialPlanTime(0),
    optimizedInitialPlanCost(0),
    optimizedInitialPlanTime(0) {
}

UIntEx BranchAndBoundSearch::run() {
    return this->run(0, UIntEx::INF);
}

UIntEx BranchAndBoundSearch::run(const int initialLowerBound, const UIntEx initialUpperBound) {
    // reset values
    this->costUpperBound = initialUpperBound;
    this->costLowerBound = initialLowerBound;
    this->expansionCount = 0;
    this->unitPropagationCount = 0;
    // construct search node representing the initial state without any forbidden or applied operators
    SearchNode initialNode = SearchNode(this->task, this->options);
    if (this->costLowerBound < initialNode.heuristicValue) {
        this->costLowerBound = initialNode.heuristicValue;
    }

    // try to get better initial upper bound by using Steiner tree improvement
    if (this->options.initialUpperBound) {
        cout << "    Discovering initial bound ... " << flush;
        Timer cpuTimer(CPU_TIME);
        vector<const RelaxedOperator *> hAddAchiever;
        hAddAchiever.resize(this->task.variables.size());
        PlanSet initialPlanSet = discoverPlan(this->task, hAddAchiever);
        this->initialPlanCost = planCost(this->task, initialPlanSet);
        this->initialPlanTime = cpuTimer.elapsed();
        cout << "done (" << this->initialPlanCost << ") " << this->initialPlanTime << endl;
        if (this->costLowerBound == this->initialPlanCost) {
            cout << "    Initial solution was perfect" << endl;
            this->setPlan(initialPlanSet);
            return this->initialPlanCost;
        }
        cout << "    Trying to improve initial solution ... " << endl << flush;
        cpuTimer.restart();
        PlanSet optimizedInitialPlanSet = optimizePlan(this->task, initialPlanSet, hAddAchiever);
        this->optimizedInitialPlanCost = planCost(this->task, optimizedInitialPlanSet);
        this->optimizedInitialPlanTime = cpuTimer.elapsed();
        cout << "      done (" << this->optimizedInitialPlanCost << ") " << this->optimizedInitialPlanTime << endl;
        this->setPlan(optimizedInitialPlanSet);
        if (this->costUpperBound > optimizedInitialPlanCost) {
            this->costUpperBound = optimizedInitialPlanCost;
        }
        if (this->costLowerBound == optimizedInitialPlanCost) {
            cout << "    Optimization of initial solution was perfect" << endl;
            // its not necessary to return here (the search would do that anyway in the first step)
            // but this way we can see the reasoning for returning better
            return optimizedInitialPlanCost;
        }
    }

    cout << "    Starting with bounds (" << this->costLowerBound << "-" << this->costUpperBound << ")" << endl;
    UIntEx result = this->recursiveBranchAndBound(initialNode);
    if (result == UIntEx::INF && !this->plan.empty() && initialUpperBound >= this->optimizedInitialPlanCost && initialLowerBound <= this->optimizedInitialPlanCost) {
        // optimized initial plan was perfect and is within expected bounds. no better plan could be discovered
        return this->optimizedInitialPlanCost;
    }
    return result;
}

UIntEx BranchAndBoundSearch::recursiveBranchAndBound(const SearchNode &searchNode) {
    if (this->options.breakOnFirstSolution && !this->plan.empty()) {
        return UIntEx::INF;
    }
#ifdef FULL_DEBUG
    printNode(searchNode, this->costUpperBound);
#endif
    // The heuristic estimate never overestimates, so in this case the best solution in this subtree can at most be as cheap as the current best.
    // This means there is no _better_ solution in this subtree.
    if (searchNode.getCostLowerBound() > this->costUpperBound ||
        (searchNode.getCostLowerBound() == this->costUpperBound && !this->plan.empty())) {
#ifdef FULL_DEBUG
        cout << endl << "Exceeded bound (" << searchNode.getCostLowerBound() << " >= " << this->costUpperBound << ")" << endl << endl;
#endif
        return UIntEx::INF;
    }

    // Have we reached the goal? If so, update the current best solution and return with its cost.
    // Test on heuristic == 0 is faster than subset test and should filter out most of the nodes during the search.
    if (searchNode.heuristicValue == 0 && searchNode.currentState.contains(this->task.goal)) {
        // can use swap, as the search node is no longer needed (this is a bit of a hack)
        this->setPlan(const_cast<SearchNode &>(searchNode).partialPlan);
        this->costUpperBound = searchNode.currentCost;
        cout << "    New Solution, updated bounds (" << this->costLowerBound << "-" << this->costUpperBound << ")" << endl;
        if (this->options.improveIntermediatePlans) {
            PlanSet optimizedPlanSet = optimizePlan(this->task, this->plan);
            int optimizedPlanCost = planCost(this->task, optimizedPlanSet);
            if (this->costUpperBound > optimizedPlanCost) {
                this->setPlan(optimizedPlanSet);
                this->costUpperBound = optimizedPlanCost;
                cout << "    New Solution, updated bounds (" << this->costLowerBound << "-" << this->costUpperBound << ")" << endl;
            }
        }
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
        if (this->options.expansionLimit != 0 && this->expansionCount >= this->options.expansionLimit) {
            return UIntEx::INF;
        }
        // a finite return value means, that a better solution was found in this subtree
        if (planCost.hasFiniteValue()) {
            foundBetterPlan = true;
            // When expanding the first successor lead to a solution with the cost previously predicted by the heuristic
            // the second successor cannot yield a better solution. In this case generating the second successor (and
            // possibly calculating LM-cut for it) can be avoided.
            if (this->options.avoidExpandingSecondSuccessor && this->boundsOverlap(searchNode)) {
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

void printNode(const SearchNode &searchNode, const UIntEx &upperBound) {
    std::cout << std::endl;
    std::cout << "BEGIN NODE (" << searchNode.currentCost << " + " << searchNode.heuristicValue << " = " << searchNode.getCostLowerBound() << " <= X <= " << upperBound << ")" << std::endl;
    std::cout << "Plan" << std::endl;
    foreach(const RelaxedOperator *op, searchNode.partialPlan) {
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
            if (op->isApplicable(searchNode.currentState)) {
                std::cout << "*";
            }
            std::cout << op->name << ", ";
        }
        std::cout << std::endl;
    }
    std::cout << "END NODE" << std::endl;
}
