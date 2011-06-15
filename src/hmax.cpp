#include "hmax.h"

#include <iostream>

#include "foreach.h"
#include "PriorityQueue.h"

UIntEx hmax(RelaxedTask &task) {
    VariableSet initialState;
    initialState.add(task.init);
    return hmax(task, initialState);
}

UIntEx hmax(RelaxedTask &task, VariableSet &state) {
    OperatorCosts operatorCosts;
    foreach(RelaxedOperator &op, task.operators) {
        operatorCosts[&op] = op.baseCost;
    }
    return hmax(task, state, operatorCosts);
}

UIntEx hmax(RelaxedTask &task, VariableSet &state, OperatorCosts &operatorCosts) {
    foreach(Variable &var, task.variables) {
        var.hmax = INFINITY;
        var.closed = false;
    }
    foreach(RelaxedOperator &op, task.operators) {
        op.preconditionChoice = NULL;
        op.unsatisfiedPreconditions = op.preconditions.size();
    }
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

            if (operatorCosts[op] == INFINITY) {
                continue;
            }
            int operatorCost = operatorCosts[op].integerValue();
            op->unsatisfiedPreconditions--;
            if (op->unsatisfiedPreconditions == 0) {
                // We discovered all preconditions of this action.
                // Since preconditions are expanded in order of their hmax-value,
                // one of the maximizing preconditions is always expanded last
                // can just choose var as precondition
                // (could also iterate over op.preconditions and search for other preconditions)
                op->preconditionChoice = var;
                foreach(Variable *effect, op->effects) {
                    if (effect->closed) {
                        continue;
                    }
                    int successorCost = hmax + operatorCost;
                    if (effect->hmax == INFINITY) {
                        queue.push(effect, successorCost, depth+1);
                    }
                    else if (effect->hmax > successorCost) {
                        queue.decreaseKey(effect, successorCost, depth+1);
                    }
                }
            }
        }
    }
    return task.goal->hmax;
}
