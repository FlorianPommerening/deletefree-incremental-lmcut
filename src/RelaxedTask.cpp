#include <stdlib.h>
#include <string>
#include <iostream>
#include <queue>
#include <algorithm>
#include <iostream>

#include "RelaxedTask.h"
#include "foreach.h"
#include "Timer.h"

using namespace std;

RelaxedTask::RelaxedTask() {
}

RelaxedTask::~RelaxedTask() {
    foreach(RelaxedOperator *op, this->operators) {
        delete op;
    }
    foreach(Variable *v, this->variables) {
        delete v;
    }
}

RelaxedTask::RelaxedTask(const RelaxedTask& /* other */) {
    throw "Copying the task will break it. Too lazy to change it.";
}

RelaxedTask& RelaxedTask::operator=(const RelaxedTask& /* rhs */) {
    throw "Copying the task will break it. Too lazy to change it.";
}

void RelaxedTask::parseFile(const char *filename) {
    ifstream taskfile(filename);
    try {
        this->parseTask(taskfile);
    } catch (...) {
        taskfile.close();
        throw;
    }
    taskfile.close();
}

Variable *RelaxedTask::getVariable(const std::string &name) const {
    foreach(Variable *var, this->variables) {
        if (var->name == name) {
            return var;
        }
    }
    throw "Unknown variable '" + name + "'";
}

bool RelaxedTask::removeUnnecessaryParts(vector<pair<pair<string, float>, pair<int, int> > > &filteredElements) {
    this->crossreference();
    vector<bool> variableNecesary = vector<bool>(this->variables.size(), true);
    vector<bool> operatorNecesary = vector<bool>(this->operators.size(), true);

    Timer cpuTimer(CPU_TIME);

    int filteredVariables;
    int filteredOperators;
    this->filterFirstAchieversForRelevantVariable(variableNecesary, operatorNecesary, &filteredVariables, &filteredOperators);
    filteredElements.push_back(make_pair(make_pair("combined", cpuTimer.elapsed()), make_pair(filteredVariables, filteredOperators)));
#ifdef FULL_DEBUG
    cout << "Combined analysis filtered " << filteredVariables << " variables and " << filteredOperators << " operators" << endl;
#endif
    if (!variableNecesary[this->init->id]) {
        // unsolvable
        return false;
    }

    // remove unnecessary operators and unnecessary variables from preconditions and effects
    Variable *dummyPrecondition = this->getVariable("@@precond");
    if (!dummyPrecondition) {
        throw "Task is not in canonical form. Use parse function to create a task object.";
    }
    vector<RelaxedOperator *>::iterator itOp = this->operators.begin();
    while (itOp != this->operators.end()) {
        RelaxedOperator *op = *itOp;
        if (operatorNecesary[op->id]) {
            op->effects.removeUnnecessary(variableNecesary);
            op->preconditions.removeUnnecessary(variableNecesary);
            if (op->effects.size() == 0) {
                operatorNecesary[op->id] = false;
            }
            else if (op->preconditions.size() == 0) {
                // make sure the task stays in canonical form
                op->preconditions.add(dummyPrecondition);
                // if each operator already has a precondition, this might never trigger
                // and the dummy precondition will be removed again
                variableNecesary[dummyPrecondition->id] = true;
            }
        }
        if (!operatorNecesary[op->id]) {
            itOp = this->operators.erase(itOp);
        } else {
            ++itOp;
        }
    }
    // remove unnecessary variables
    vector<Variable *> relevantVariables;
    relevantVariables.reserve(this->variables.size());
    foreach(Variable *var, this->variables) {
        if (variableNecesary[var->id]) {
            relevantVariables.push_back(var);
        }
    }
    std::swap(this->variables, relevantVariables);

    State::setFullVariableSet(&this->variables);

    // cross reference entries can be invalid, so recreate them
    this->crossreference();
    if (this->operators.empty()) {
        return this->init == this->goal;
    }
    return true;
}


bool RelaxedTask::filterFirstAchieversForRelevantVariable(vector<bool> &variableNecesary, vector<bool> &operatorNecesary, int *filteredVariables, int *filteredOperators) {
    bool filteredSomething = false;
    *filteredVariables = 0;
    *filteredOperators = 0;
    vector<bool> isFirstAchiever = vector<bool>(this->operators.size(), false);
    vector<vector<RelaxedOperator*> > firstAchievers = vector<vector<RelaxedOperator*> >(this->variables.size());
    foreach(Variable *v, this->variables) {
        if (v == this->init) {
            // init needs no achievers
            continue;
        }
        if (!variableNecesary[v->id]) {
            // removed by previous filter
            continue;
        }
        bool hasAchiver = false;
        // get maximal reachable state without using operators that add v
        foreach(RelaxedOperator *op, this->operators) {
            op->unsatisfiedPreconditions = op->preconditions.size();
        }
        State maximalStateWithoutV;
        maximalStateWithoutV.add(this->init);
        vector<Variable *> reachedStack;
        reachedStack.reserve(this->variables.size());
        reachedStack.push_back(this->init);
        while (!reachedStack.empty()) {
            Variable *reachedVar = reachedStack.back();
            reachedStack.pop_back();
            foreach(RelaxedOperator *op, reachedVar->precondition_of) {
                op->unsatisfiedPreconditions--;
                if (op->unsatisfiedPreconditions != 0 ||
                        !operatorNecesary[op->id] ||
                        find(op->effects.begin(), op->effects.end(), v) != op->effects.end()) {
                    continue;
                }
                foreach(Variable *eff, op->effects) {
                    if (!maximalStateWithoutV.contains(eff)) {
                        maximalStateWithoutV.add(eff);
                        reachedStack.push_back(eff);
                    }
                }
            }
        }
        foreach(RelaxedOperator *op, v->effect_of) {
            if (!operatorNecesary[op->id] || !op->isApplicable(maximalStateWithoutV)) {
                // removed by previous filter or not reachable without reaching v first
                continue;
            }
            isFirstAchiever[op->id] = true;
            firstAchievers[v->id].push_back(op);
            hasAchiver = true;
        }
        if (!hasAchiver) {
            variableNecesary[v->id] = false;
            filteredSomething = true;
            (*filteredVariables)++;
        }
    }
    foreach(RelaxedOperator *op, this->operators) {
        if (operatorNecesary[op->id] & !isFirstAchiever[op->id]) {
            operatorNecesary[op->id] = false;
            filteredSomething = true;
            (*filteredOperators)++;
        }
    }

    // start with assuming nothing but the goal is relevant and mark backwards
    vector<bool> relevant = vector<bool>(this->variables.size());
    vector<bool> operatorRelevant = vector<bool>(this->operators.size());
    foreach(Variable *var, this->variables) {
        relevant[var->id] = false;
    }
    queue<Variable *> relevantVariableQueue;
    relevantVariableQueue.push(this->goal);
    while (!relevantVariableQueue.empty()) {
        Variable *var = relevantVariableQueue.front();
        relevantVariableQueue.pop();
        if (relevant[var->id]) {
            // we have already seen this variable
            continue;
        }
        relevant[var->id] = true;
        // push all preconditions that havn't been previously removed
        foreach(RelaxedOperator *op, firstAchievers[var->id]) {
            if (operatorNecesary[op->id]) {
                operatorRelevant[op->id] = true;
                foreach(Variable *pre, op->preconditions) {
                    if (variableNecesary[pre->id]) {
                        relevantVariableQueue.push(pre);
                    }
                }
            }
        }
    }
    // update filter
    foreach(Variable *v, this->variables) {
        if (variableNecesary[v->id] & !relevant[v->id]) {
            variableNecesary[v->id] = false;
            filteredSomething = true;
            (*filteredVariables)++;
        }
    }
    foreach(RelaxedOperator *op, this->operators) {
        if (operatorNecesary[op->id] & !operatorRelevant[op->id]) {
            operatorNecesary[op->id] = false;
            filteredSomething = true;
            (*filteredOperators)++;
        }
    }

    return filteredSomething;
}

void RelaxedTask::crossreference() {
    this->zeroBaseCostOperators.clear();
    int varId = 0;
    foreach(Variable *var, this->variables) {
        var->id = varId++;
        var->effect_of.clear();
        var->precondition_of.clear();
    }
    int opId = 0;
    foreach(RelaxedOperator *op, this->operators) {
        op->id = opId++;
        foreach(Variable *effect, op->effects) {
            effect->effect_of.push_back(op);
        }
        foreach(Variable *precondition, op->preconditions) {
            precondition->precondition_of.push_back(op);
        }
        if (op->baseCost == 0) {
            this->zeroBaseCostOperators.push_back(op);
        }
    }
}

void RelaxedTask::parseTask(ifstream &taskfile) {
    // Parse task from a file. The format is similar to the sas task format,
    // but since this is not used right now, its not described in mor detail.
    string line;
    if (!getline(taskfile, line) || line != "Variables") { throw "'Variables' expected"; }
    if (!getline(taskfile, line)) { throw "Number of variables expected"; }
    int nVariables = atoi(line.c_str());
    this->variables.reserve(nVariables);
    for (int i = 0; i < nVariables; ++i) {
        if (!getline(taskfile, line)) { throw "Name of a variable expected"; }
        this->variables.push_back(new Variable(line, i));
    }
    State::setFullVariableSet(&this->variables);
    if (!getline(taskfile, line) || line != "Initial state") { throw "'Initial state' expected"; }
    if (!getline(taskfile, line) || line != "1") { throw "Number of variables in initial state expected (must be 1)"; }
    if (!getline(taskfile, line)) { throw "Initial state variable expected"; }
    this->init = this->getVariable(line);
    if (!getline(taskfile, line) || line != "Goal") { throw "'Goal' expected"; }
    if (!getline(taskfile, line) || line != "1") { throw "Number of variables in goal state expected (must be 1)"; }
    if (!getline(taskfile, line)) { throw "Goal state variable expected"; }
    this->goal = this->getVariable(line);
    if (!getline(taskfile, line) || line != "Operators") { throw "'Operators' expected"; }
    if (!getline(taskfile, line)) { throw "Number of operators expected"; }
    int nOperators = atoi(line.c_str());
    for (int i = 0; i < nOperators; ++i) {
        RelaxedOperator *op = new RelaxedOperator(i);
        if (!getline(taskfile, line) || line != "Operator") { throw "'Operator' expected"; }
        if (!getline(taskfile, op->name)) { throw "Operator name expected"; }
        if (!getline(taskfile, line)) { throw "Operator cost expected"; }
        op->baseCost = atoi(line.c_str());
        parseVariableSet(taskfile, op->preconditions);
        parseVariableSet(taskfile, op->effects);
        this->operators.push_back(op);
    }
}

template<class VariableSet>
void RelaxedTask::parseVariableSet(ifstream &taskfile, VariableSet &set) {
    string line;
    if (!getline(taskfile, line)) { throw "Number of variables expected"; }
    int nVariables = atoi(line.c_str());
    for (int i = 0; i < nVariables; ++i) {
        if (!getline(taskfile, line)) { throw "Name of variable expected"; }
        set.add(this->getVariable(line));
    }
}

void RelaxedTask::printReadable() const {
    cout << "BEGIN TASK" << endl;
    cout << "  " << this->variables.size() << " Variables" << endl;
    foreach(Variable *var, this->variables) {
        cout << "    " << var->name << endl;
        cout << "      Effect of" << endl;
        foreach(RelaxedOperator *op, var->effect_of) {
            cout << "        " << op->name << endl;
        }
        cout << "      Precondition of" << endl;
        foreach(RelaxedOperator *op, var->precondition_of) {
            cout << "        " << op->name << endl;
        }
    }
    cout << "  Init" << endl;
    cout << "    " << this->init->name << endl;
    cout << "  Goal" << endl;
    cout << "    " << this->goal->name << endl;
    cout << endl;
    foreach(RelaxedOperator *op, this->operators) {
        cout << "  Operator " << op->name << " (" << op->baseCost << ")" << endl;
        cout << "    " << op->preconditions.size() << " Preconditions" << endl;
        foreach(Variable *var, op->preconditions) {
            cout << "    " << var->name << endl;
        }
        cout << "    ==>" << endl;
        cout << "    " << op->effects.size() << " Effects" << endl;
        foreach(Variable *var, op->effects) {
            cout << "    " << var->name << endl;
        }
    }
    cout << "END TASK" << endl;
}
