#include "steinertreeImprove.h"

#include "foreach.h"
#include "UIntEx.h"
#include "Options.h"

#include <algorithm>
#include <queue>
#include <assert.h>

using namespace std;
PlanSet extractPlan(const RelaxedTask &task, vector<const RelaxedOperator *> &hAddAchiever, const State *initialState=NULL,
                    Variable *goalVariable=NULL, Variable *assumedVariable=NULL);
void addContainedFluents(const PlanSet &planSet, State &state);
PlanSet findReplacedPlanPart(const RelaxedTask &task, vector<const RelaxedOperator *> &hAddAchiever, Variable *const y, const PlanSet &planSet, vector<int> &markIn, const int markAs);
PlanSet findDependentPlanPart(const RelaxedTask &task, vector<const RelaxedOperator *> &hAddAchiever, Variable *const y, vector<int> &markIn, const int markAs);
void findDependentPlanPartRec(vector<const RelaxedOperator *> &hAddAchiever, Variable *const y, Variable *const goalVariable, vector<bool> &isDependent, PlanSet &dependentPart, vector<int> &markIn, const int markAs);
bool improvePlan(const RelaxedTask &task, vector<const RelaxedOperator *> &hAddAchiever, const PlanSet &planSet);

PlanSet discoverPlan(const RelaxedTask &task, vector<const RelaxedOperator *> &hAddAchiever,
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
        // TODO is this really enough to avoid popping the same variable twice? Otherwise operator costs could be off.
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

PlanSet optimizePlan(const RelaxedTask &task, PlanSet &planSet, vector<const RelaxedOperator *> &hAddAchiever) {
    while (improvePlan(task, hAddAchiever, planSet)) {
        planSet = extractPlan(task, hAddAchiever);
        cout << "        improved solution to cost " << planCost(task, planSet) << endl;
    }
    return planSet;
}

PlanSet optimizePlan(const RelaxedTask &task, const Plan &plan) {
    // TODO
    // removeRedundantOperators(plan);
    // set the achiever of a variable v to the operator in the plan that first achieves v
    vector<const RelaxedOperator *> hAddAchiever = vector<const RelaxedOperator *>(task.variables.size(), NULL);
    foreach(const RelaxedOperator *op, plan) {
        foreach(Variable *v, op->effects) {
            if (hAddAchiever[v->id] == NULL) {
                hAddAchiever[v->id] = op;
            }
        }
    }
    PlanSet planSet = extractPlan(task, hAddAchiever);
    // remove achievers that are not needed for the plan set (this gives the plan improvement procedure
    // the freedom to choose a different achiever for these variables)
    State containedFluents;
    addContainedFluents(planSet, containedFluents);
    foreach(const RelaxedOperator *op, plan) {
        foreach(Variable *v, op->effects) {
            if (!containedFluents.contains(v)) {
                hAddAchiever[v->id] = NULL;
            }
        }
    }
    return optimizePlan(task, planSet, hAddAchiever);
}

int planCost(const RelaxedTask &task, PlanSet &planSet) {
    vector<int> alreadyCounted = vector<int>(task.operators.size(), 0);
    int cost = 0;
    foreach(const PlanSetEntry &entry, planSet) {
        const RelaxedOperator *op = entry.first;
        if (alreadyCounted[op->id] == 0) {
            cost += op->baseCost;
            alreadyCounted[op->id] = 1;
        }
    }
    return cost;
}

Plan serializePlan(const PlanSet &planSet, Variable *initialStateVariable) {
    State currentState;
    currentState.add(initialStateVariable);
    Plan serializedPlan;
    bool finished = false;
    bool stateChanged = false;
    while (!finished) {
        finished = true;
        stateChanged = false;
        foreach(const PlanSetEntry &entry, planSet) {
            const RelaxedOperator *op = entry.first;
            if (currentState.contains(entry.second)) {
                continue;
            }
            if (op->isApplicable(currentState)) {
                op->apply(currentState);
                serializedPlan.push_back(op);
                stateChanged = true;
            } else {
                finished = false;
            }
        }
        assert(stateChanged);
    }
    return serializedPlan;
}

PlanSet extractPlan(const RelaxedTask &task, vector<const RelaxedOperator *> &hAddAchiever, const State *initialState,
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
        const RelaxedOperator *achiever = hAddAchiever[v->id];
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

void addContainedFluents(const PlanSet &planSet, State &state) {
    foreach(const PlanSetEntry &entry, planSet) {
        state.add(entry.second);
    }
}

PlanSet findReplacedPlanPart(const RelaxedTask &task, vector<const RelaxedOperator *> &hAddAchiever, Variable *const y,
                             const PlanSet &planSet, vector<int> &markIn, const int markAs) {
    PlanSet planAssumingY = extractPlan(task, hAddAchiever, NULL, NULL, y);
    vector<int> usedForDifferentPurpose =  vector<int>(task.operators.size(), 0);
    foreach(const PlanSetEntry &entry, planAssumingY) {
        usedForDifferentPurpose[entry.first->id] = 1;
    }
    PlanSet remainingPart;
    foreach(const PlanSetEntry &planSetEntry, planSet) {
        const RelaxedOperator *op = planSetEntry.first;
        if (usedForDifferentPurpose[op->id] == 0) {
            remainingPart.push_back(planSetEntry);
            markIn[planSetEntry.second->id] = markAs;
        }
    }
    return remainingPart;
}

PlanSet findDependentPlanPart(const RelaxedTask &task, vector<const RelaxedOperator *> &hAddAchiever, Variable *const y,
                              vector<int> &markIn, const int markAs) {
    vector<bool> isDependent = vector<bool>(task.variables.size());
    foreach(Variable *var, task.variables) {
        var->closed = false;
    }
    task.init->closed = true;
    isDependent[task.init->id] = false;

    PlanSet dependentPart;
    findDependentPlanPartRec(hAddAchiever, y, task.goal, isDependent, dependentPart, markIn, markAs);
    return dependentPart;
}

void findDependentPlanPartRec(vector<const RelaxedOperator *> &hAddAchiever, Variable *const y, Variable *const goalVariable, vector<bool> &isDependent,
                              PlanSet &dependentPart, vector<int> &markIn, const int markAs) {
    if (goalVariable->closed) {
        return;
    }
    isDependent[goalVariable->id] = false;
    const RelaxedOperator *achiever = hAddAchiever[goalVariable->id];
    foreach(Variable *v, achiever->preconditions) {
        if (v == y) {
            isDependent[goalVariable->id] = true;
            continue;
        }
        findDependentPlanPartRec(hAddAchiever, y, v, isDependent, dependentPart, markIn, markAs);
        if (isDependent[v->id]) {
            isDependent[goalVariable->id] = true;
        }
    }
    if (isDependent[goalVariable->id]) {
        pair<const RelaxedOperator *, Variable *> newEntry = make_pair(achiever, goalVariable);
        // note to self: be careful here, there could be a reason why closed is only set after this!
        if (markIn[goalVariable->id] != markAs) {
            dependentPart.push_back(newEntry);
            markIn[goalVariable->id] = markAs;
        }
    }
    goalVariable->closed = true;
}

bool improvePlan(const RelaxedTask &task, vector<const RelaxedOperator *> &hAddAchiever, const PlanSet &planSet) {
    const int NO_PART = 0;
    const int REPLACED_PART  = 1;
    const int DEPENDENT_PART = 2;
    State improvableFacts;
    addContainedFluents(planSet, improvableFacts);
    foreach(Variable *y, improvableFacts) {
#ifdef FULL_DEBUG
        cout << "IMPROVING ON " << y->name << endl;
#endif
        vector<int> planPart = vector<int>(task.variables.size(), NO_PART);
        PlanSet replacedPlanPart = findReplacedPlanPart(task, hAddAchiever, y, planSet, planPart, REPLACED_PART);
#ifdef FULL_DEBUG
        cout << "Replaced Part" << endl;
        foreach(PlanSetEntry entry, replacedPlanPart) {
            cout << "  " << entry.first->name << " achieving " << entry.second->name << endl;
        }
#endif
        if (replacedPlanPart.empty()) {
            continue;
        }
        PlanSet dependentPlanPart = findDependentPlanPart(task, hAddAchiever, y, planPart, DEPENDENT_PART);
#ifdef FULL_DEBUG
        cout << "Dependent Part" << endl;
        foreach(PlanSetEntry entry, dependentPlanPart) {
            cout << "  " << entry.first->name << " achieving " << entry.second->name << endl;
        }
#endif
        PlanSet remainingPlanPart;
        foreach(PlanSetEntry entry, planSet) {
            if (planPart[entry.second->id] != REPLACED_PART && planPart[entry.second->id] != DEPENDENT_PART) {
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
        vector<const RelaxedOperator *> alternativeHAddAchiever;
        alternativeHAddAchiever.resize(hAddAchiever.size());
        PlanSet alternativePlan = discoverPlan(task, alternativeHAddAchiever, &initialStateAfterReplace, y, &ignoredAddEffects);
#ifdef FULL_DEBUG
        cout << "Alternative Plan" << endl;
        foreach(PlanSetEntry entry, alternativePlan) {
            cout << "  " << entry.first->name << " achieving " << entry.second->name << endl;
        }
#endif
        if (planCost(task, alternativePlan) < planCost(task, replacedPlanPart)) {
            foreach(PlanSetEntry &entry, alternativePlan) {
                hAddAchiever[entry.second->id] = entry.first;
            }
            return true;
        }
    }
    return false;
}
