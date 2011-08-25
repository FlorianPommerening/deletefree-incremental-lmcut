#include "steinertreeImprove.h"

#include "foreach.h"
#include "UIntEx.h"
#include "Options.h"

#include <algorithm>
#include <queue>

using namespace std;
PlanSet extractPlan(const RelaxedTask &task, vector<RelaxedOperator *> &hAddAchiever, const State *initialState=NULL,
                    Variable *goalVariable=NULL, Variable *assumedVariable=NULL);
State collectAchievedFacts(const PlanSet &planSet);
void addContainedFluents(const PlanSet &planSet, State &state);
PlanSet findReplacedPlanPart(const RelaxedTask &task, vector<RelaxedOperator *> &hAddAchiever, Variable *const y, const PlanSet &planSet);
PlanSet findDependentPlanPart(const RelaxedTask &task, vector<RelaxedOperator *> &hAddAchiever, Variable *const y);
void findDependentPlanPartRec(vector<RelaxedOperator *> &hAddAchiever, Variable *const y, Variable *const goalVariable, vector<bool> &isDependent, PlanSet &dependentPart);
bool improvePlan(const RelaxedTask &task, vector<RelaxedOperator *> &hAddAchiever, const PlanSet &planSet);

PlanSet discoverPlan(const RelaxedTask &task, vector<RelaxedOperator *> &hAddAchiever,
        const State *initialState, Variable *goalVariable, const State *ignoredAddEffects) {
    State defaultInitialState;
    if (initialState == NULL) {
        defaultInitialState.add(task.init);
        initialState = &defaultInitialState;
    }
    if (goalVariable == NULL) {
        goalVariable = task.goal;
    }
    vector<UIntEx> hAddOperatorCost = vector<UIntEx>(task.operators.size());
    foreach(RelaxedOperator *op, task.operators) {
        hAddOperatorCost[op->id] = op->baseCost;
        op->unsatisfiedPreconditions = op->preconditions.size();
    }
    vector<UIntEx> hAddVariableCost = vector<UIntEx>(task.variables.size());
    foreach(Variable *v, task.variables) {
        hAddVariableCost[v->id] = UIntEx::INF;
    }

    // TODO use PriorityQueue class for both this and hmax (needs some changes in hmax)
    typedef pair<UIntEx, Variable *> QueueEntry;
    priority_queue<QueueEntry, vector<QueueEntry>, greater<QueueEntry> > queue;
    foreach(Variable *v, *initialState) {
        if (ignoredAddEffects != NULL && ignoredAddEffects->contains(v)) {
            continue;
        }
        hAddVariableCost[v->id] = 0;
        hAddAchiever[v->id] = NULL;
        queue.push(make_pair(0, v));
    }

    while (!queue.empty()) {
        QueueEntry entry = queue.top();
        queue.pop();
        UIntEx cost = entry.first;
        Variable *v = entry.second;
        if (hAddVariableCost[v->id] < cost) {
            continue;
        }
        if (v == goalVariable) {
            break;
        }
        foreach(RelaxedOperator *op, v->precondition_of) {
            hAddOperatorCost[op->id] += hAddVariableCost[v->id];
            --op->unsatisfiedPreconditions;
            if (op->unsatisfiedPreconditions == 0) {
                foreach(Variable *w, op->effects) {
                    if (hAddVariableCost[w->id] > hAddOperatorCost[op->id]) {
                        // TODO avoid duplicated push code
                        if (ignoredAddEffects != NULL && ignoredAddEffects->contains(w)) {
                            continue;
                        }
                        hAddVariableCost[w->id] = hAddOperatorCost[op->id];
                        hAddAchiever[w->id] = op;
                        queue.push(make_pair(hAddOperatorCost[op->id], w));
                    }
                }
            }
        }
    }
    PlanSet planSet = extractPlan(task, hAddAchiever, initialState, goalVariable);
    return planSet;

}

PlanSet optimizePlan(const RelaxedTask &task, PlanSet &planSet, vector<RelaxedOperator *> &hAddAchiever) {
    while (improvePlan(task, hAddAchiever, planSet)) {
        planSet = extractPlan(task, hAddAchiever);
        cout << "        improved solution to cost " << planCost(planSet) << endl;
    }
    return planSet;
}

PlanSet optimizePlan(const RelaxedTask &task, Plan &plan) {
    // TODO do some mojo with the h^add supporters, so that plan will be discovered in the first step
    // then call the other overload
    throw "Not implemented";
}

int planCost(PlanSet &planSet) {
    vector<RelaxedOperator *> alreadyCounted;
    alreadyCounted.reserve(planSet.size());
    int cost = 0;
    foreach(const PlanSetEntry &entry, planSet) {
        RelaxedOperator *op = entry.first;
        if (find(alreadyCounted.begin(), alreadyCounted.end(), op) == alreadyCounted.end()) {
            cost += op->baseCost;
            alreadyCounted.push_back(op);
        }
    }
    return cost;
}

vector<RelaxedOperator *> serializePlan(const PlanSet &planSet, const State &initialState) {
    State currentState = initialState;
    vector<RelaxedOperator *> serializedPlan;
    bool finished = false;
    while (!finished) {
        finished = true;
        foreach(const PlanSetEntry &entry, planSet) {
            RelaxedOperator *op = entry.first;
            if (currentState.contains(entry.second)) {
                continue;
            }
            if (op->isApplicable(currentState)) {
                op->apply(currentState);
                serializedPlan.push_back(op);
            } else {
                finished = false;
            }
        }
    }
    return serializedPlan;
}




PlanSet extractPlan(const RelaxedTask &task, vector<RelaxedOperator *> &hAddAchiever, const State *initialState,
                    Variable *goalVariable, Variable *assumedVariable) {
    State defaultInitialState;
    if (initialState == NULL) {
        defaultInitialState.add(task.init);
        initialState = &defaultInitialState;
    }
    if (goalVariable == NULL) {
        goalVariable = task.goal;
    }
    foreach(Variable *var, task.variables) {
        var->closed = (initialState->contains(var));
    }
    PlanSet planSet;
    if (assumedVariable != NULL) {
        if (assumedVariable == goalVariable) {
            return planSet;
        }
        assumedVariable->closed = true;
    }
    vector<Variable *> stack;
    stack.push_back(goalVariable);
    while (!stack.empty()) {
        Variable *v = stack.back();
        stack.pop_back();
        RelaxedOperator *achiever = hAddAchiever[v->id];
        planSet.push_back(make_pair(achiever, v));
        foreach(Variable *w, achiever->preconditions) {
            if (!w->closed) {
                w->closed = true;
                stack.push_back(w);
            }
        }
    }
    return planSet;
}

State collectAchievedFacts(const PlanSet &planSet) {
    State achieved;
    foreach(const PlanSetEntry &entry, planSet) {
        achieved.add(entry.first->effects);
    }
    return achieved;
}

void addContainedFluents(const PlanSet &planSet, State &state) {
    foreach(const PlanSetEntry &entry, planSet) {
        state.add(entry.second);
    }
}

PlanSet findReplacedPlanPart(const RelaxedTask &task, vector<RelaxedOperator *> &hAddAchiever, Variable *const y, const PlanSet &planSet) {
    PlanSet planAssumingY = extractPlan(task, hAddAchiever, NULL, NULL, y);
    PlanSet remainingPart;
    foreach(const PlanSetEntry &planSetEntry, planSet) {
        RelaxedOperator *op = planSetEntry.first;
        bool operatorUsedForDifferentPurpose = false;
        foreach(const PlanSetEntry &planAssumingYEntry, planAssumingY) {
            if (planAssumingYEntry.first == op) {
                operatorUsedForDifferentPurpose = true;
            }
        }
        if (!operatorUsedForDifferentPurpose) {
            remainingPart.push_back(planSetEntry);
        }
    }
    return remainingPart;
}

PlanSet findDependentPlanPart(const RelaxedTask &task, vector<RelaxedOperator *> &hAddAchiever, Variable *const y) {
    vector<bool> isDependent = vector<bool>(task.variables.size());
    foreach(Variable *var, task.variables) {
        var->closed = false;
    }
    task.init->closed = true;
    isDependent[task.init->id] = false;

    PlanSet dependentPart;
    findDependentPlanPartRec(hAddAchiever, y, task.goal, isDependent, dependentPart);
    return dependentPart;
}

void findDependentPlanPartRec(vector<RelaxedOperator *> &hAddAchiever, Variable *const y, Variable *const goalVariable, vector<bool> &isDependent, PlanSet &dependentPart) {
    if (goalVariable->closed) {
        return;
    }
    isDependent[goalVariable->id] = false;
    RelaxedOperator *achiever = hAddAchiever[goalVariable->id];
    foreach(Variable *v, achiever->preconditions) {
        if (v == y) {
            isDependent[goalVariable->id] = true;
            continue;
        }
        findDependentPlanPartRec(hAddAchiever, y, v, isDependent, dependentPart);
        if (isDependent[v->id]) {
            isDependent[goalVariable->id] = true;
        }
    }
    if (isDependent[goalVariable->id]) {
        pair<RelaxedOperator *, Variable *> newEntry = make_pair(achiever, goalVariable);
        if (find(dependentPart.begin(), dependentPart.end(), newEntry) == dependentPart.end()) {
            dependentPart.push_back(newEntry);
        }
    }
    goalVariable->closed = true;
}

bool improvePlan(const RelaxedTask &task, vector<RelaxedOperator *> &hAddAchiever, const PlanSet &planSet) {
    State improvableFacts = collectAchievedFacts(planSet);
    foreach(Variable *y, improvableFacts) {
#ifdef FULL_DEBUG
        cout << "IMPROVING ON " << y->name << endl;
#endif
        PlanSet replacedPlanPart = findReplacedPlanPart(task, hAddAchiever, y, planSet);
#ifdef FULL_DEBUG
        cout << "Replaced Part" << endl;
        foreach(PlanSetEntry entry, replacedPlanPart) {
            cout << "  " << entry.first->name << " achieving " << entry.second->name << endl;
        }
#endif
        if (replacedPlanPart.empty()) {
            continue;
        }
        PlanSet dependentPlanPart = findDependentPlanPart(task, hAddAchiever, y);
#ifdef FULL_DEBUG
        cout << "Dependent Part" << endl;
        foreach(PlanSetEntry entry, dependentPlanPart) {
            cout << "  " << entry.first->name << " achieving " << entry.second->name << endl;
        }
#endif
        PlanSet remainingPlanPart;
        foreach(PlanSetEntry entry, planSet) {
            if (find(replacedPlanPart.begin(), replacedPlanPart.end(), entry) == replacedPlanPart.end() &&
                find(dependentPlanPart.begin(), dependentPlanPart.end(), entry) == dependentPlanPart.end()) {
                remainingPlanPart.push_back(entry);
            }
        }
#ifdef FULL_DEBUG
        cout << "Remaining Part" << endl;
        foreach(PlanSetEntry entry, remainingPlanPart) {
            cout << "  " << entry.first->name << " achieving " << entry.second->name << endl;
        }
#endif
        State initialStateAfterReplace;
        initialStateAfterReplace.add(task.init);
        addContainedFluents(remainingPlanPart, initialStateAfterReplace);
#ifdef FULL_DEBUG
        cout << "Initial State" << endl;
        foreach(Variable *v, initialStateAfterReplace) {
            cout << "  " << v->name << endl;
        }
#endif
        State ignoredAddEffects;
        addContainedFluents(dependentPlanPart, ignoredAddEffects);
#ifdef FULL_DEBUG
        cout << "Ignored Add Effects" << endl;
        foreach(Variable *v, ignoredAddEffects) {
            cout << "  " << v->name << endl;
        }
#endif
        vector<RelaxedOperator *> alternativeHAddAchiever;
        alternativeHAddAchiever.resize(hAddAchiever.size());
        PlanSet alternativePlan = discoverPlan(task, alternativeHAddAchiever, &initialStateAfterReplace, y, &ignoredAddEffects);
#ifdef FULL_DEBUG
        cout << "Alternative Plan" << endl;
        foreach(PlanSetEntry entry, alternativePlan) {
            cout << "  " << entry.first->name << " achieving " << entry.second->name << endl;
        }
#endif
        if (planCost(alternativePlan) < planCost(replacedPlanPart)) {
            foreach(PlanSetEntry &entry, alternativePlan) {
            // TODO according to the paper this might also be:
            // for q in collect_achieved_facts(alternative_plan):
                hAddAchiever[entry.second->id] = entry.first;
            }
            return true;
        }
    }
    return false;
}
