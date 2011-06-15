#include "lmcut.h"
#include "foreach.h"
#include "hmax.h"
#include "SearchNode.h"

#include <stack>

using namespace std;

UIntEx lmCut(RelaxedTask &task) {
    SearchNode initialNode = SearchNode(task);
    return initialNode.heuristicValue;
}

UIntEx lmCut(RelaxedTask &task, VariableSet &state, OperatorCosts &operatorCosts,
          list<Landmark> &landmarks, map<RelaxedOperator *, Landmark *> &operatorToLandmark) {
    UIntEx hmax_value = hmax(task, state, operatorCosts);
    if (hmax_value == INFINITY) {
        return INFINITY;
    }
    int lmcutValue = 0;
    while (hmax_value != 0) {
        landmarks.push_back(Landmark());
        Landmark &cut = landmarks.back();
        findCut(task, state, operatorCosts, cut);
        int landmarkCost = cut.cost;
        lmcutValue += landmarkCost;
        foreach(Landmark::value_type &entry, cut) {
            RelaxedOperator *op = entry.first;
            operatorToLandmark[op] = &cut;
            operatorCosts[op] -= landmarkCost;
        }
        hmax_value = hmax(task, state, operatorCosts);
    }
    return lmcutValue;
}

void findCut(RelaxedTask &task, VariableSet &state, OperatorCosts &operatorCosts, Landmark &cut) {
    map<Variable *, list<RelaxedOperator *> > effectToZeroCostOp;
    foreach(OperatorCostEntry &entry, operatorCosts) {
        RelaxedOperator *op = entry.first;
        UIntEx &cost = entry.second;
        if (cost == 0) {
            foreach(Variable *effect, op->effects) {
                effectToZeroCostOp[effect].push_back(op);
            }
        }
    }
    set<Variable *> goalZone;
    stack<Variable *> goalStack;
    goalStack.push(task.goal);
    while (!goalStack.empty()) {
        Variable *var = goalStack.top();
        goalStack.pop();
        if (goalZone.find(var) != goalZone.end())
            continue;
        goalZone.insert(var);
        map<Variable *, list<RelaxedOperator *> >::iterator it =
                effectToZeroCostOp.find(var);
        if (it == effectToZeroCostOp.end())
            continue;
        foreach(RelaxedOperator *op, it->second) {
            if (operatorCosts[op] == INFINITY || op->preconditionChoice == NULL)
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
            cout << operatorCost << endl;
            op->unsatisfiedPreconditions--;
            if (op->unsatisfiedPreconditions == 0) {
                bool addedToCut = false;
                foreach(Variable *effect, op->effects) {
                    if (goalZone.find(effect) != goalZone.end()){
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
