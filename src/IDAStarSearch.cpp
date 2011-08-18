#include "IDAStarSearch.h"
#include "lmcut.h"

#include <iostream>

using namespace std;

IDAStarSearch::IDAStarSearch(const RelaxedTask &task, const OperatorSelector &operatorSelector, const OptimizationOptions &options):
                                            task(task),
                                            bnbSearch(task, operatorSelector, options) {
}

UIntEx IDAStarSearch::run() {
    this->expansionCount = 0;
    this->unitPropagationCount = 0;
    UIntEx initialBound = lmCut(this->task);
    unsigned int currentBound;
    if (!initialBound.hasFiniteValue(currentBound)) {
        return UIntEx::INF;
    }
    while (true) {
        cout << "Trying to find a solution with length " << currentBound << endl;
        // TODO: If there is a good way to get a lower bound from BnB Search (apart from h^lm-cut(init), obviously)
        // this could be used to skip some bounds in the loop
        UIntEx solution = this->bnbSearch.run(currentBound, currentBound);
        this->expansionCount += this->bnbSearch.getExpansionCount();
        this->unitPropagationCount += this->bnbSearch.getUnitPropagationCount();
        if (solution.hasFiniteValue()) {
            return solution;
        }
        ++currentBound;
    }
}
