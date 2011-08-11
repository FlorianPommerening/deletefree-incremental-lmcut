#include <stdlib.h>
#include <string>
#include <iostream>
#include <queue>
#include <algorithm>
#include <iostream>

#include "RelaxedTask.h"
#include "foreach.h"
#include "PointerMap.h"

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

Variable *RelaxedTask::getVariable(const std::string &name) {
    foreach(Variable *var, this->variables) {
        if (var->name == name) {
            return var;
        }
    }
    throw "Unknown variable '" + name + "'";
}

bool RelaxedTask::removeIrrelevantVariables() {
    this->crossreference();
    // The goal is relevant. If an operator adds a relevant variable all its preconditions are relevant
    PointerMap<Variable, bool> relevant;
    foreach(Variable *var, this->variables) {
        relevant[var] = false;
    }
    queue<Variable *> relevantVariableQueue;
    relevantVariableQueue.push(this->goal);
    while (!relevantVariableQueue.empty()) {
        Variable *var = relevantVariableQueue.front();
        relevantVariableQueue.pop();
        if (relevant[var]) {
            // we have already seen this variable
            continue;
        }
        relevant[var] = true;
        foreach(RelaxedOperator *op, var->effect_of) {
            foreach(Variable *pre, op->preconditions) {
                relevantVariableQueue.push(pre);
            }
        }
    }
    if (!relevant[this->init]) {
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
        op->effects.removeIrrelevant(relevant);
        op->preconditions.removeIrrelevant(relevant);
        if (op->effects.size() == 0) {
            itOp = this->operators.erase(itOp);
            continue;
        }
        if (op->preconditions.size() == 0) {
            // make sure the task stays in canonical form
            op->preconditions.add(dummyPrecondition);
            // if each operator already has a precondition, this might never trigger
            // and the dummy precondition will be removed again
            relevant[dummyPrecondition] = true;
        }
        ++itOp;
    }
    // remove unnecessary variables
    vector<Variable *> relevantVariables;
    relevantVariables.reserve(relevant.size());
    for (vector<Variable *>::iterator itVar = this->variables.begin(); itVar != this->variables.end(); ++itVar) {
        if (relevant[*itVar]) {
            relevantVariables.push_back(*itVar);
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

void RelaxedTask::crossreference() {
    this->zeroBaseCostOperators.clear();
    int i = 0;
    foreach(Variable *var, this->variables) {
        var->id = i++;
        var->effect_of.clear();
        var->precondition_of.clear();
    }
    foreach(RelaxedOperator *op, this->operators) {
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
        RelaxedOperator *op = new RelaxedOperator();
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

void RelaxedTask::printReadable() {
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
