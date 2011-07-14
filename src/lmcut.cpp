#include "Options.h"
#include "lmcut.h"
#include "foreach.h"
#include "hmax.h"
#include "SearchNode.h"

#include <stack>

using namespace std;

UIntEx lmCut(RelaxedTask &task) {
    OptimizationOptions options;
    SearchNode initialNode = SearchNode(task, options);
    return initialNode.heuristicValue;
}

UIntEx lmCut(RelaxedTask &task, VariableSet &state) {
    OperatorCosts operatorCosts;
    foreach(RelaxedOperator &op, task.operators) {
        operatorCosts[&op] = op.baseCost;
    }
    list<Landmark> landmarks;
    list<Landmark>::iterator *firstAdded = NULL;
    return lmCut(task, state, operatorCosts, landmarks, firstAdded);
}

UIntEx lmCut(RelaxedTask &task, VariableSet &state, OperatorCosts &operatorCosts, list<Landmark> &landmarks, list<Landmark>::iterator *firstAdded) {
    bool isFirst = true;
    // in case no landmarks are added
    *firstAdded = landmarks.end();
    UIntEx hmax_value = hmax(task, state, operatorCosts);
    if (hmax_value == UIntEx::INF) {
        return UIntEx::INF;
    }
    int lmcutValue = 0;
    while (hmax_value != 0) {
        landmarks.push_back(Landmark());
        if (isFirst && (firstAdded != NULL)) {
            *firstAdded = --landmarks.end();
            isFirst = false;
        }
        Landmark &cut = landmarks.back();
        findCut(task, state, operatorCosts, cut);
        int landmarkCost = cut.cost;
        lmcutValue += landmarkCost;
        foreach(Landmark::value_type &entry, cut) {
            RelaxedOperator *op = entry.first;
            operatorCosts[op] -= landmarkCost;
        }
        hmax_value = hmax(task, state, operatorCosts);
    }
    return lmcutValue;
}

void findCut(RelaxedTask &task, VariableSet &state, OperatorCosts &operatorCosts, Landmark &cut) {
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
    VariableSet goalZone;
    stack<Variable *> goalStack;
    goalStack.push(task.goal);
    while (!goalStack.empty()) {
        Variable *var = goalStack.top();
        goalStack.pop();
        if (goalZone.contains(var))
            continue;
        goalZone.add(var);
        PointerMap<Variable, list<RelaxedOperator *> >::iterator it =
                effectToZeroCostOp.find(var);
        if (it == effectToZeroCostOp.end())
            continue;
        foreach(RelaxedOperator *op, it->second) {
            if (operatorCosts[op] == UIntEx::INF || op->preconditionChoice == NULL)
                continue;
            goalStack.push(op->preconditionChoice);
        }
    }
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
        if (var->closed)
            continue;
        var->closed = true;
        foreach(RelaxedOperator *op, var->precondition_of) {
            unsigned int operatorCost;
            if (!operatorCosts[op].hasFiniteValue(operatorCost)) {
                // operator cost == infinity --> operator forbidden
                continue;
            }
            op->unsatisfiedPreconditions--;
            if (op->unsatisfiedPreconditions == 0) {
                bool addedToCut = false;
                foreach(Variable *effect, op->effects) {
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
