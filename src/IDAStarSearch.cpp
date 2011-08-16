#include "IDAStarSearch.h"
#include "lmcut.h"

#include <iostream>

using namespace std;

IDAStarSearch::IDAStarSearch(RelaxedTask &task, OperatorSelector &operatorSelector, OptimizationOptions &options):
                                            task(task),
                                            bnbSearch(task, operatorSelector, options) {
}

UIntEx IDAStarSearch::run() {
    UIntEx currentBound = lmCut(this->task);
    if (!currentBound.hasFiniteValue()) {
        return UIntEx::INF;
    }
    while (true) {
        cout << "Trying to find a solution with " << endl;
        // TODO: If there is a good way to get a lower bound from BnB Search (apart from h^lm-cut(init), obviously)
        // this could be used to skip some bounds in the loop
        UIntEx solution = this->bnbSearch.run(currentBound);
        if (solution.hasFiniteValue()) {
            return solution;
        }
        ++currentBound;
    }
}
