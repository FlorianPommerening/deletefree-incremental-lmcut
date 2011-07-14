#include <stdlib.h>
#include <string>
#include <iostream>
#include <queue>

#include "RelaxedTask.h"
#include "foreach.h"
#include "PointerMap.h"

using namespace std;

RelaxedTask::RelaxedTask() {
}

RelaxedTask::RelaxedTask(const RelaxedTask& /* other */) {
    throw "Copying the task will break it. Too lazy to change it";
}

RelaxedTask& RelaxedTask::operator=(const RelaxedTask& /* rhs */) {
    throw "Copying the task will break it. Too lazy to change it";
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
    foreach(Variable &var, this->variables) {
        if (var.name == name) {
            return &var;
        }
    }
    throw "Unknown variable '" + name + "'";
}

bool RelaxedTask::removeIrrelevantVariables() {
    this->crossreference();
    PointerMap<Variable, bool> relevant;
    foreach(Variable &var, this->variables) {
        relevant[&var] = false;
    }
    queue<Variable *> relevantVariableQueue;
    relevantVariableQueue.push(this->goal);
    while (!relevantVariableQueue.empty()) {
        Variable *var = relevantVariableQueue.front();
        relevantVariableQueue.pop();
        if (relevant[var]) continue;
        relevant[var] = true;
        foreach(RelaxedOperator *op, var->effect_of) {
            foreach(Variable *pre, op->preconditions) {
                relevantVariableQueue.push(pre);
            }
        }
    }
    if (!relevant[this->init]){
        // unsolvable
        return false;
    }
    Variable *dummyPrecondition = this->getVariable("@@precond");
    if (!dummyPrecondition) {
        throw "Task is not in canonical form. Use parse function to create a task object.";
    }
    list<RelaxedOperator>::iterator itOp = this->operators.begin();
    while (itOp != this->operators.end()) {
        itOp->effects.removeIrrelevant(relevant);
        itOp->preconditions.removeIrrelevant(relevant);
        if (itOp->effects.size() == 0) {
            itOp = this->operators.erase(itOp);
            continue;
        }
        if (itOp->preconditions.size() == 0) {
            itOp->preconditions.add(dummyPrecondition);
            relevant[dummyPrecondition] = true;
        }
        ++itOp;
    }
    list<Variable>::iterator itVar = this->variables.begin();
    while (itVar != this->variables.end()) {
        if (!relevant[&(*itVar)])
            itVar = this->variables.erase(itVar);
        else
            ++itVar;
    }
    // cross reference entries can be invalid, so recreate them
    this->crossreference();
    if (this->operators.empty()) {
        return this->init == this->goal;
    }
    return true;
}

void RelaxedTask::crossreference() {
    foreach(Variable &var, this->variables) {
        var.effect_of.clear();
        var.precondition_of.clear();
    }
    foreach(RelaxedOperator &op, this->operators) {
        foreach(Variable *effect, op.effects) {
            effect->effect_of.push_back(&op);
        }
        foreach(Variable *precondition, op.preconditions) {
            precondition->precondition_of.push_back(&op);
        }
    }
}

void RelaxedTask::parseTask(ifstream &taskfile) {
    string line;
    if (!getline(taskfile, line) || line != "Variables") throw "'Variables' expected";
    if (!getline(taskfile, line)) throw "Number of variables expected";
    int nVariables = atoi(line.c_str());
    for (int i = 0; i < nVariables; ++i) {
        if (!getline(taskfile, line)) throw "Name of a variable expected";
        this->variables.push_back(Variable(line));
    }
    if (!getline(taskfile, line) || line != "Initial state") throw "'Initial state' expected";
    if (!getline(taskfile, line) || line != "1") throw "Number of variables in initial state expected (must be 1)";
    if (!getline(taskfile, line)) throw "Initial state variable expected";
    this->init = this->getVariable(line);
    if (!getline(taskfile, line) || line != "Goal") throw "'Goal' expected";
    if (!getline(taskfile, line) || line != "1") throw "Number of variables in goal state expected (must be 1)";
    if (!getline(taskfile, line)) throw "Goal state variable expected";
    this->goal = this->getVariable(line);
    if (!getline(taskfile, line) || line != "Operators") throw "'Operators' expected";
    if (!getline(taskfile, line)) throw "Number of operators expected";
    int nOperators = atoi(line.c_str());
    for (int i = 0; i < nOperators; ++i) {
        RelaxedOperator op;
        if (!getline(taskfile, line) || line != "Operator") throw "'Operator' expected";
        if (!getline(taskfile, op.name)) throw "Operator name expected";
        if (!getline(taskfile, line)) throw "Operator cost expected";
        op.baseCost = atoi(line.c_str());
        parseVariableSet(taskfile, op.preconditions);
        parseVariableSet(taskfile, op.effects);
        this->operators.push_back(op);
    }
}

void RelaxedTask::parseVariableSet(ifstream &taskfile, VariableSet &set) {
    string line;
    if (!getline(taskfile, line)) throw "Number of variables expected";
    int nVariables = atoi(line.c_str());
    for (int i = 0; i < nVariables; ++i) {
        if (!getline(taskfile, line)) throw "Name of variable expected";
        set.add(this->getVariable(line));
    }
}
