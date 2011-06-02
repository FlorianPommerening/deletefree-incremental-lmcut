#include <stdlib.h>
#include <string>
#include <iostream>

#include "RelaxedTask.h"
#include "foreach.h"

using namespace std;

RelaxedTask::RelaxedTask() {
}

RelaxedTask::RelaxedTask(const RelaxedTask &other) {
    throw "Copying the task will break it. Too lazy to change it";
}

RelaxedTask& RelaxedTask::operator=(const RelaxedTask &rhs) {
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

Variable *RelaxedTask::getVariable(const std::string name) {
    for (unsigned int i = 0; i < this->variables.size(); ++i) {
        if (this->variables[i].name == name) {
            return &(this->variables[i]);
        }
    }
    throw "Unknown variable '" + name + "'";
}

void RelaxedTask::crossreference() {
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
    this->variables.reserve(nVariables);
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
        op.cost = atoi(line.c_str());
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
