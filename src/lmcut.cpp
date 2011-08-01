#include "Options.h"
#include "lmcut.h"
#include "foreach.h"
#include "hmax.h"
#include "SearchNode.h"

#include <stack>

using namespace std;

UIntEx lmCut(RelaxedTask &task) {
    // TODO: change this to call lmCut(task, VariableSet(task->initialState))
    OptimizationOptions options;
    SearchNode initialNode = SearchNode(task, options);
    return initialNode.heuristicValue;
}

UIntEx lmCut(RelaxedTask &task, VariableSet &state) {
    // use default operator cost mapping
    OperatorCosts operatorCosts;
    foreach(RelaxedOperator &op, task.operators) {
        operatorCosts[&op] = op.baseCost;
    }
    // dummy list to contain the discovered landmark
    list<Landmark> landmarks;
    return lmCut(task, state, operatorCosts, landmarks);
}

UIntEx lmCut(RelaxedTask &task, VariableSet &state, OperatorCosts &operatorCosts, list<Landmark> &landmarks, list<Landmark>::iterator *firstAdded) {
    // only set firstAdded once and use landmarks.end() as default in case no landmarks are added
    bool isFirst = true;
    if (firstAdded != NULL) {
        *firstAdded = landmarks.end();
    }
    // calculating h^max also sets all hmax costs of variables and preconditionChoice values of operators
    UIntEx hmax_value = hmax(task, state, operatorCosts);
    if (hmax_value == UIntEx::INF) {
        // unsolvable problem
        return UIntEx::INF;
    }
    int lmcutValue = 0;
    while (hmax_value != 0) {
        // One new landmark is discovered in each iteration until h^max is 0
        landmarks.push_back(Landmark());
        if (isFirst && (firstAdded != NULL)) {
            *firstAdded = --landmarks.end();
            isFirst = false;
        }
        Landmark &cut = landmarks.back();
        findCut(task, state, operatorCosts, cut);
        int landmarkCost = cut.cost;
        lmcutValue += landmarkCost;
        // adjust cost function
        foreach(Landmark::value_type &entry, cut) {
            RelaxedOperator *op = entry.first;
            operatorCosts[op] -= landmarkCost;
        }
        // recalculate hmax to check if we can discover another landmark
        hmax_value = hmax(task, state, operatorCosts);
    }
    return lmcutValue;
}

void findCut(RelaxedTask &task, VariableSet &state, OperatorCosts &operatorCosts, Landmark &cut) {
    // Map effects to operators for 0-cost operators.
    // This mapping is already present in the task for all operators but recreating it only for 0-cost operators
    // should avoid some tests in the cost function later on.
    PointerMap<Variable, list<RelaxedOperator *> > effectToZeroCostOp;
    foreach(OperatorCostEntry &entry, operatorCosts) {
        RelaxedOperator *op = entry.first;
        UIntEx &cost = entry.second;
        if (cost == 0) {
            foreach(Variable *effect, op->effects) {
                effectToZeroCostOp[effect].push_back(op);
            }
        }
    }
    // First discover the goal zone by enumerating all variables that allow the goal to be reached with 0-cost.
    // That is, moving backwards from the goal along 0-cost operators from effect to preconditionChoice until no more
    // variables are discovered.
    VariableSet goalZone;
    stack<Variable *> goalStack;
    goalStack.push(task.goal);
    while (!goalStack.empty()) {
        Variable *var = goalStack.top();
        goalStack.pop();
        // TODO: this could be done in O(1) if variables store an isInGoalZone value
        if (goalZone.contains(var)) {
            continue;
        }
        goalZone.add(var);
        PointerMap<Variable, list<RelaxedOperator *> >::iterator it =
                effectToZeroCostOp.find(var);
        if (it == effectToZeroCostOp.end()) {
            continue;
        }
        foreach(RelaxedOperator *op, it->second) {
            if (operatorCosts[op] == UIntEx::INF || op->preconditionChoice == NULL) {
                // forbidden operator or unreachable operator
                // TODO: if there are operators with operatorCosts[op] != UIntEx::INF && op->preconditionChoice == NULL
                // they could probably be removed
                continue;
            }
            goalStack.push(op->preconditionChoice);
        }
    }

    // forward search starting from state (similar to hmax calculation)
    // reset temporary variables.
    foreach(RelaxedOperator &op, task.operators) {
        op.unsatisfiedPreconditions = op.preconditions.size();
    }
    foreach(Variable &var, task.variables) {
        var.closed = false;
    }

    stack<Variable *> reachedStack;
    foreach(Variable *var, state) {
        reachedStack.push(var);
    }
    while (!reachedStack.empty()) {
        Variable *var = reachedStack.top();
        reachedStack.pop();
        if (var->closed) {
            // already discovered this variable
            continue;
        }
        var->closed = true;
        foreach(RelaxedOperator *op, var->precondition_of) {
            unsigned int operatorCost;
            if (!operatorCosts[op].hasFiniteValue(operatorCost)) {
                // if the operator cost is not finite, the operator was previously forbidden
                continue;
            }
            op->unsatisfiedPreconditions--;
            if (op->unsatisfiedPreconditions == 0) {
                // add the effects of an operator to the stack if and only if the operator wasn't added to the cut
                bool addedToCut = false;
                foreach(Variable *effect, op->effects) {
                    // add op to cut if it contains an effect that is in the goal zone
                    if (goalZone.contains(effect)){
                        cut.add(op, operatorCost);
                        addedToCut = true;
                        break;
                    }
                }
                if (!addedToCut) {
                    foreach(Variable *effect, op->effects) {
                        reachedStack.push(effect);
                    }
                }
            }
        }
    }
}
