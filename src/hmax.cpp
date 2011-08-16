#include "hmax.h"

#include "foreach.h"
#include "PriorityQueue.h"

using namespace std;

UIntEx hmax(RelaxedTask &task) {
    // start calculation for initial state
    State initialState;
    initialState.add(task.init);
    return hmax(task, initialState);
}

UIntEx hmax(RelaxedTask &task, State &state) {
    // start calculation for default operator cost function
    OperatorCosts operatorCosts = OperatorCosts(task.operators.size());
    foreach(RelaxedOperator *op, task.operators) {
        operatorCosts[op->id] = op->baseCost;
    }
    return hmax(task, state, operatorCosts);
}

UIntEx hmax(RelaxedTask &task, State &state, OperatorCosts &operatorCosts) {
    // reset all temporary variables
    foreach(Variable *var, task.variables) {
        var->hmax = UIntEx::INF;
        var->closed = false;
    }
    foreach(RelaxedOperator *op, task.operators) {
        op->preconditionChoice = NULL;
        op->unsatisfiedPreconditions = op->preconditions.size();
    }
    // Initialize the queue with variables contained in the state.
    // Values are ordered by hmax costs and (for tie-breaking) the depth in which they were discovered
    PriorityQueue queue;
    foreach(Variable *var, state) {
        queue.push(var, 0, 0);
    }

    while (!queue.empty()) {
        int hmax, depth;
        Variable *var = queue.pop(hmax, depth);
        if (var == NULL) {
            break;
        }
        var->closed = true;
        foreach(RelaxedOperator *op, var->precondition_of) {
            unsigned int operatorCost;
            if (!operatorCosts[op->id].hasFiniteValue(operatorCost)) {
                // if the operator's cost is infinity his means that the operator was previously forbidden
                continue;
            }
            op->unsatisfiedPreconditions--;
            if (op->unsatisfiedPreconditions == 0) {
                // We discovered all preconditions of this action.
                // Since preconditions are expanded in order of their hmax-cost,
                // one of the maximizing preconditions is always expanded last
                // and we can just choose var as precondition.
                // We could also iterate over op->preconditions and search for other preconditions
                // with the same hmax cost.
                op->preconditionChoice = var;
                foreach(Variable *effect, op->effects) {
                    if (effect->closed) {
                        // The variable was already discovered with a lower hmax cost.
                        continue;
                    }
                    int successorCost = hmax + operatorCost;
                    if (effect->hmax == UIntEx::INF) {
                        // This is the first time we discover this variable
                        queue.push(effect, successorCost, depth+1);
                    }
                    else if (effect->hmax > successorCost) {
                        // This variable was discovered before
                        queue.decreaseKey(effect, successorCost, depth+1);
                    }
                }
            }
        }
    }
    return task.goal->hmax;
}



void handleOperators(vector<Variable *> &fromQueue, vector<Variable *> &toQueue, OperatorCosts &operatorCosts, int requiredCost);

UIntEx UnitCostHmax(RelaxedTask &task, State &state, OperatorCosts &operatorCosts) {
    // reset all temporary variables
    foreach(Variable *var, task.variables) {
        var->hmax = UIntEx::INF;
        var->closed = false;
    }
    foreach(RelaxedOperator *op, task.operators) {
        op->preconditionChoice = NULL;
        op->unsatisfiedPreconditions = op->preconditions.size();
    }
    // Initialize the queue with variables contained in the state.
    vector<Variable *> currentHmaxLevel;
    currentHmaxLevel.reserve(task.variables.size());
    vector<Variable *> nextHmaxLevel;
    nextHmaxLevel.reserve(task.variables.size());
    foreach(Variable *var, state) {
        var->hmax = 0;
        var->closed = true;
        currentHmaxLevel.push_back(var);
    }
    while (!currentHmaxLevel.empty()) {
        handleOperators(currentHmaxLevel, currentHmaxLevel, operatorCosts, 0);
        handleOperators(currentHmaxLevel, nextHmaxLevel, operatorCosts, 1);
        swap(currentHmaxLevel, nextHmaxLevel);
        nextHmaxLevel.clear();
    }
    return task.goal->hmax;
}


void handleOperators(vector<Variable *> &fromQueue, vector<Variable *> &toQueue, OperatorCosts &operatorCosts, int requiredCost) {
    unsigned currentId = 0;
    while (currentId < fromQueue.size()) {
        Variable *var = fromQueue[currentId++];
        foreach(RelaxedOperator *op, var->precondition_of) {
            if (operatorCosts[op->id] != requiredCost) {
                continue;
            }
            op->unsatisfiedPreconditions--;
            if (op->unsatisfiedPreconditions == 0) {
                // We discovered all preconditions of this action.
                // Since preconditions are expanded in order of their hmax-cost,
                // one of the maximizing preconditions is always expanded last
                // and we can just choose var as precondition.
                // We could also iterate over op->preconditions and search for other preconditions
                // with the same hmax cost.
                op->preconditionChoice = var;
                UIntEx successorCost = var->hmax + requiredCost;
                foreach(Variable *effect, op->effects) {
                    if (effect->closed) {
                        // The variable was already discovered with a lower hmax cost.
                        continue;
                    }
                    effect->hmax = successorCost;
                    effect->closed = true;
                    toQueue.push_back(effect);
                }
            }
        }
    }
}



