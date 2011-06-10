#include "LMCut.h"
#include "foreach.h"
#include "hmax.h"

#include <stack>

using namespace std;

int calculateLMCut(RelaxedTask &task) {
    LMCutState lmcut(task);
    return lmcut.initialState();
}

void Landmark::add(RelaxedOperator *op, int opCost) {
    if (opCost > this->cost) {
        this->cost = opCost;
    }
    this->operatorEntries[op] = opCost;
}

void Landmark::remove(RelaxedOperator *op) {
    map<RelaxedOperator *, int>::iterator it = this->operatorEntries.find(op);
    if (it != this->operatorEntries.end() && this->operatorEntries[op] == this->cost) {
        foreach(Landmark::value_type &entry, this->operatorEntries) {
            int opCost = entry.second;
            if (this->cost < opCost) {
                this->cost = opCost;
            }
        }
    }
    this->remove(op);
}

LMCutState::LMCutState(RelaxedTask &task): heuristicValue(0),
                                           task(&task) {
    foreach(RelaxedOperator &op, task.operators) {
        this->operatorCost[&op] = op.baseCost;
    }
}

LMCutState::LMCutState(const LMCutState &other):
                    heuristicValue(other.heuristicValue),
                    task(other.task),
                    landmarks(other.landmarks),
                    operatorCost(other.operatorCost){
    foreach(Landmark &landmark, this->landmarks) {
        foreach(Landmark::value_type &entry, landmark) {
            RelaxedOperator *op = entry.first;
            this->operatorToLandmark[op] = &landmark;
        }
    }
}

LMCutState& LMCutState::operator=(const LMCutState &rhs) {
    throw "Assignment operator should not be used for LMCutState";
}

int LMCutState::initialState() {
    VariableSet initSet;
    initSet.add(task->init);
    this->heuristicValue = this->lmCut(initSet);
    return this->heuristicValue;
}

int LMCutState::operatorApplied(RelaxedOperator *appliedOp, VariableSet &resultingState) {
    this->operatorCost[appliedOp] = FORBIDDEN;
    map<RelaxedOperator *, Landmark *>::iterator it = this->operatorToLandmark.find(appliedOp);
    if (it != this->operatorToLandmark.end()) {
        Landmark *containingLM = this->operatorToLandmark[appliedOp];
        // "undo" this landmark: decrease heuristic value and
        // increase all contained operator's costs by the LM's cost
        int landmarkCost = containingLM->cost;
        this->heuristicValue -= landmarkCost;
        foreach(Landmark::value_type &entry, *containingLM) {
            RelaxedOperator *op = entry.first;
            if (op != appliedOp) {
                this->operatorCost[op] -= landmarkCost;
            }
        }
        this->landmarks.remove(*containingLM);
        this->operatorToLandmark.erase(it);
    }
    // search for additional landmarks
    return this->lmCut(resultingState);
}

int LMCutState::operatorForbidden(RelaxedOperator *forbiddenOp, VariableSet &resultingState) {
    this->operatorCost[forbiddenOp] = FORBIDDEN;
    map<RelaxedOperator *, Landmark *>::iterator it = this->operatorToLandmark.find(forbiddenOp);
    if (it != this->operatorToLandmark.end()) {
        Landmark *containingLM = this->operatorToLandmark[forbiddenOp];
        // remove operator from landmark. If it was the only one,
        // the problem becomes unsolvable
        int oldLandmarkCost = containingLM->cost;
        containingLM->remove(forbiddenOp);
        int newLandmarkCost = containingLM->cost;
        if (containingLM->size() == 0) {
            this->heuristicValue = UNSOLVABLE;
            return UNSOLVABLE;
        }
        this->heuristicValue -= (oldLandmarkCost - newLandmarkCost);
    }
    // search for additional landmarks
    return this->lmCut(resultingState);
}

int LMCutState::lmCut(VariableSet &state) {
    int hmax_value = hmax(*(this->task), state, this->operatorCost);
    if (hmax_value == UNSOLVABLE) {
        return UNSOLVABLE;
    }
    int additionalCost = 0;
    while (hmax_value != 0) {
        this->landmarks.push_back(Landmark());
        Landmark &cut = this->landmarks.back();
        this->findCut(state, cut);
        int landmarkCost = cut.cost;
        additionalCost += landmarkCost;
        foreach(Landmark::value_type &entry, cut) {
            RelaxedOperator *op = entry.first;
            this->operatorToLandmark[op] = &cut;
            this->operatorCost[op] -= landmarkCost;
        }
        hmax_value = hmax(*(this->task), state, this->operatorCost);
    }
    this->heuristicValue += additionalCost;
    return this->heuristicValue;
}

void LMCutState::findCut(VariableSet &state, Landmark &cut) {
    map<Variable *, list<RelaxedOperator *> > effectToZeroCostOp;
    foreach(OperatorCostEntry &entry, this->operatorCost) {
        RelaxedOperator *op = entry.first;
        int cost = entry.second;
        if (cost == 0) {
            foreach(Variable *effect, op->effects) {
                effectToZeroCostOp[effect].push_back(op);
            }
        }
    }
    set<Variable *> goalZone;
    stack<Variable *> goalStack;
    goalStack.push(this->task->goal);
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
            if (this->operatorCost[op] == FORBIDDEN || op->preconditionChoice == NULL)
                continue;
            goalStack.push(op->preconditionChoice);
        }
    }
    foreach(RelaxedOperator &op, this->task->operators) {
        op.unsatisfiedPreconditions = op.preconditions.size();
    }
    foreach(Variable &var, this->task->variables) {
        var.closed = false;
    }

    stack<Variable *> reachedStack;
    reachedStack.push(this->task->init);
    while (!reachedStack.empty()) {
        Variable *var = reachedStack.top();
        reachedStack.pop();
        if (var->closed)
            continue;
        var->closed = true;
        foreach(RelaxedOperator *op, var->precondition_of) {
            int opCost = this->operatorCost[op];
            if (opCost == FORBIDDEN)
                continue;
            op->unsatisfiedPreconditions--;
            if (op->unsatisfiedPreconditions == 0) {
                bool addedToCut = false;
                foreach(Variable *effect, op->effects) {
                    if (goalZone.find(effect) != goalZone.end()){
                        cut.add(op, opCost);
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
