#include <iostream>
#include "foreach.h"
#include "hmax.h"
#include "PriorityQueue.h"

int hmax(RelaxedTask &task) {
    VariableSet initialState;
    initialState.add(task.init);
    return hmax(task, initialState);
}

int hmax(RelaxedTask &task, VariableSet &state) {
    OperatorCosts operatorCosts;
    foreach(RelaxedOperator &op, task.operators) {
        operatorCosts[&op] = op.cost;
    }
    return hmax(task, state, operatorCosts);
}

int hmax(RelaxedTask &task, VariableSet &state, OperatorCosts &operatorCosts) {
    for (unsigned int i = 0; i < task.variables.size(); ++i) {
        task.variables[i].hmax = UNREACHABLE;
        task.variables[i].closed = false;
    }
    for (unsigned int i = 0; i < task.operators.size(); ++i) {
        task.operators[i].unsatisfiedPreconditions = task.operators[i].preconditions.size();
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
            if (operatorCosts[op] == FORBIDDEN) {
                continue;
            }
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
                    int successorCost = hmax + operatorCosts[op];
                    if (effect->hmax == UNREACHABLE) {
                        queue.push(effect, successorCost, depth+1);
                    }
                    else if (successorCost < effect->hmax) {
                        queue.decreaseKey(effect, successorCost, depth+1);
                    }
                }
            }
        }
    }
    return task.goal->hmax;
}
