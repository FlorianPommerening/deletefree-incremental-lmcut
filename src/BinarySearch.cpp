#include "BinarySearch.h"
#include "lmcut.h"
#include "Timer.h"

#include <iostream>

using namespace std;

BinarySearch::BinarySearch(const RelaxedTask &task, const OperatorSelector &operatorSelector, const OptimizationOptions &options):
                                            task(task),
                                            bnbSearch(task, operatorSelector, options),
                                            options(options) {
}

UIntEx BinarySearch::run() {
    this->expansionCount = 0;
    this->unitPropagationCount = 0;
    UIntEx lowerBound = lmCut(this->task);
    if (!lowerBound.hasFiniteValue()) {
        return UIntEx::INF;
    }

    vector<const RelaxedOperator *> hAddAchiever;
    hAddAchiever.resize(this->task.variables.size());
    PlanSet initialPlanSet = discoverPlan(this->task, hAddAchiever);
    int initialPlanCost = planCost(this->task, initialPlanSet);
    if (lowerBound == initialPlanCost) {
        return initialPlanCost;
    }
    PlanSet optimizedInitialPlanSet = optimizePlan(this->task, initialPlanSet, hAddAchiever);
    UIntEx upperBound = planCost(this->task, optimizedInitialPlanSet);
    while (lowerBound != upperBound) {
        cout << "interval [" << lowerBound << "," << upperBound << "] ";
        unsigned int lowerBoundInt, upperBoundInt;
        lowerBound.hasFiniteValue(lowerBoundInt);
        upperBound.hasFiniteValue(upperBoundInt);
        int middleBound = (lowerBoundInt + upperBoundInt -1) / 2;
        cout << "searching in [" << middleBound << "," << middleBound << "]" << endl;
        UIntEx solution = this->bnbSearch.run(middleBound, middleBound);
        this->expansionCount += this->bnbSearch.getExpansionCount();
        if (this->options.expansionLimit != 0 && this->expansionCount >= this->options.expansionLimit) {
            return UIntEx::INF;
        }
        this->unitPropagationCount += this->bnbSearch.getUnitPropagationCount();
        if (solution.hasFiniteValue()) {
            upperBound = middleBound;
        }
        else {
            lowerBound = middleBound + 1;
        }
    }
    return upperBound;
}
