#include "hmax.h"

#include "foreach.h"
#include "PriorityQueue.h"

UIntEx hmax(RelaxedTask &task) {
    // start calculation for initial state
    VariableSet initialState;
    initialState.add(task.init);
    return hmax(task, initialState);
}

UIntEx hmax(RelaxedTask &task, VariableSet &state) {
    // start calculation for default operator cost function
    OperatorCosts operatorCosts;
    foreach(RelaxedOperator *op, task.operators) {
        operatorCosts[op] = op->baseCost;
    }
    return hmax(task, state, operatorCosts);
}

UIntEx hmax(RelaxedTask &task, VariableSet &state, OperatorCosts &operatorCosts) {
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
            if (!operatorCosts[op].hasFiniteValue(operatorCost)) {
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
