#include "BranchAndBoundSearch.h"

BranchAndBoundSearch::BranchAndBoundSearch(RelaxedTask &task, OperatorSelector &operatorSelector) :
    task(task),
    operatorSelector(operatorSelector),
    costUpperBound(INFINITY) {
}

int BranchAndBoundSearch::run() {
    this->costUpperBound = INFINITY;
    LMCutState initialState = LMCutState(this->task).initialState();
    if (initialState.heuristicValue == UNSOLVABLE) {
        return UNSOLVABLE;
    }
    return this->recursiveBranchAndBound(initialState);
}

int BranchAndBoundSearch::recursiveBranchAndBound(LMCutState &lmcutState) {
    if (this->costUpperBound != INFINITY && lmcutState.costLowerBound >= this->costUpperBound) {
        return UNSOLVABLE;
    }
    // TODO could optimize this by saving goal in every VariableSet and setting a flag as soon as goal is added
    if (lmcutState.currentState.contains(this->task.goal)) {
        this->costUpperBound = lmcutState.currentCost;
        return this->costUpperBound;
    }

    RelaxedOperator *nextOperator = NULL;
    bool addFirst = true;
    this->operatorSelector.select(*this, nextOperator, &addFirst);
    if (nextOperator == NULL) {
        return UNSOLVABLE;
    }
    // TODO remove redundant operators???
    bool foundBetterPlan = false;
    LMCutState *successor = NULL;
    // iterate over 2 successors to avoid writing the same code twice
    for (int iSuc = 0; iSuc < 2; ++iSuc) {
        if (iSuc > 1) throw "There are only two successors. Do not call the loop more often!";
        bool first = (bool) iSuc;
        if (first ^ addFirst) {
            successor = new LMCutState(lmcutState);
            successor->ForbidOperator(nextOperator);
        } else {
            successor = new LMCutState(lmcutState);
            successor->ApplyOperator(nextOperator);
        }
        int planCost = this->recursiveBranchAndBound(*successor);
        if (planCost != UNSOLVABLE) {
            foundBetterPlan = true;
            if (lmcutState.costLowerBound >= this->costUpperBound)
                break;
        }
        delete successor; successor = NULL;
    }

    if (foundBetterPlan)
        return this->costUpperBound;
    // else
    return UNSOLVABLE;
}
