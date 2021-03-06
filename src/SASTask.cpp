#include <stdlib.h>
#include <sstream>
#include <boost/algorithm/string/predicate.hpp>
#include <boost/lexical_cast.hpp>

#include <iostream>

#include "SASTask.h"
#include "foreach.h"

using namespace std;

bool SASParser::parseTask(const string &taskFilename, SASTask &taskOut) {
    // parse task file
    this->taskfile.open(taskFilename.c_str());
    int version;
    int metric;
    if (!this->parseVersion(version) || version != 3) {
        this->error = "Unknown version of translated file.";
        return false;
    }
    bool success = (
            this->parseMetric(metric) &&
            this->parseVariables(taskOut.variables) &&
            this->parseMutexGroups() &&
            this->parseInitialState(taskOut.variables, taskOut.init) &&
            this->parseGoal(taskOut.variables, taskOut.goal) &&
            this->parseOperators(taskOut.variables, metric, taskOut.operators) &&
            this->parseAxioms(taskOut.variables, taskOut.axioms));
    this->taskfile.close();
    return success;
}

bool SASParser::parseVersion(int &version) {
    bool success = (
            this->isNextLine("begin_version") &&
            this->nextLineAsInt(version) &&
            this->isNextLine("end_version"));
    return success;
}

bool SASParser::parseMetric(int &metric) {
    bool success = (
            this->isNextLine("begin_metric") &&
            this->nextLineAsInt(metric) &&
            this->isNextLine("end_metric"));
    return success;
}

bool SASParser::parseVariables(vector<SASVariable> &variables) {
    int nVariables;
    if (!this->nextLineAsInt(nVariables)) { return false; }
    variables.resize(nVariables);
    for (unsigned int varId = 0; varId < nVariables; ++varId) {
        if (!this->parseVariable(variables, varId)) {
            return false;
        }
    }
    return true;
}

bool SASParser::parseVariable(vector<SASVariable> &variables, int varId) {
    if (!this->isNextLine("begin_variable")) { return false; }
    string expectedName = "var" + boost::lexical_cast<string>(varId);
    if (!this->isNextLine(expectedName)) { return false; }
    if (!this->nextLineAsInt(variables[varId].axiomLayer)) { return false; }
    int range;
    if (!this->nextLineAsInt(range)) { return false; }
    variables[varId].id = varId;
    variables[varId].values.reserve(range);
    for (int i = 0; i < range; ++i) {
        string valueName;
        if (!this->nextLine(valueName)) { return false; }
        variables[varId].values.push_back(valueName);
    }
    if (!this->isNextLine("end_variable")) { return false; }
    return true;
}
bool SASParser::parseMutexGroups() {
    int nMutexGroups;
    if (!this->nextLineAsInt(nMutexGroups)) { return false; }
    for (unsigned int mutexGroupId = 0; mutexGroupId < nMutexGroups; ++mutexGroupId) {
        if (!this->parseMutexGroup()) {
            return false;
        }
    }
    return true;
}

bool SASParser::parseMutexGroup() {
    if (!this->isNextLine("begin_mutex_group")) { return false; }
    vector<string> mutexEntries;
    if (!this->nextLinesAsList(mutexEntries)) { return false; }
    // ignored for now
    if (!this->isNextLine("end_mutex_group")) { return false; }
}



bool SASParser::parseInitialState(vector<SASVariable> &variables,
                                  vector<SASVariableAssignment> &init) {
    if (!this->isNextLine("begin_state")) { return false; }
    init.resize(variables.size());
    for (unsigned int i = 0; i < variables.size(); ++i) {
        int valueIndex;
        if (!this->nextLineAsInt(valueIndex)) { return false; }
        init[i].variable = &(variables[i]);
        init[i].valueIndex = valueIndex;
    }
    if (!this->isNextLine("end_state")) { return false; }
    return true;
}

bool SASParser::parseGoal(vector<SASVariable> &variables,
                          vector<SASVariableAssignment> &goal) {
    bool success = (
            this->isNextLine("begin_goal") &&
            this->parseAssignment(this->taskfile, '\n', variables, goal) &&
            this->isNextLine("end_goal"));
    return success;
}

bool SASParser::parseOperators(vector<SASVariable> &variables, int metric,
                               vector<SASOperator> &operators) {
    int nOperators;
    if (!this->nextLineAsInt(nOperators)) { return false; }
    operators.resize(nOperators);
    for (int i = 0; i < nOperators; ++i) {
        if (!parseOperator(variables, metric, operators[i])) { return false; }
    }
    return true;
}

bool SASParser::parseOperator(vector<SASVariable> &variables, int metric,
                              SASOperator &op) {
    if (!this->isNextLine("begin_operator")) { return false; }
    if (!this->nextLine(op.name)) { return false; }
    if (!this->parseAssignment(taskfile, '\n', variables, op.prevail)) { return false; }

    vector<string> effectLines;
    if (!this->nextLinesAsList(effectLines)) { return false; }
    op.effects.resize(effectLines.size());
    for (unsigned int i = 0; i < effectLines.size(); ++i) {
        stringstream lineStream(effectLines[i]);
        if (!this->parseAssignment(lineStream, ' ', variables, op.effects[i].condition)) { return false; }
        int var;
        if (!this->nextTokenAsInt(lineStream, var)) { return false; }
        op.effects[i].variable = &(variables[var]);
        if (!this->nextTokenAsInt(lineStream, op.effects[i].valueIndexBefore)) { return false; }
        if (!this->nextTokenAsInt(lineStream, op.effects[i].valueIndexAfter)) { return false; }
    }
    if (!this->nextLineAsInt(op.cost)) { return false; }
    if (metric == 0) {
            op.cost = 1;
    }
    if (!this->isNextLine("end_operator")) { return false; }
    return true;
}

bool SASParser::parseAxioms(vector<SASVariable> &variables,
                            vector<SASAxiom> &axioms) {
    int nAxioms;
    if (!this->nextLineAsInt(nAxioms)) { return false; }
    axioms.resize(nAxioms);
    for (int i = 0; i < nAxioms; ++i) {
        if (!parseAxiom(variables, axioms[i])) { return false; }
    }
    return true;
}

bool SASParser::parseAxiom(vector<SASVariable> &variables,
                           SASAxiom &axiom) {
    if (!this->isNextLine("begin_rule")) { return false; }
    if (!this->parseAssignment(taskfile, '\n', variables, axiom.condition)) { return false; }
    string effectLine;
    if (!this->nextLine(effectLine)) { return false; }
    stringstream lineStream(effectLine);
    int var, pre, post;
    if (!this->nextTokenAsInt(lineStream, var)) { return false; }
    axiom.effect.variable = &(variables[var]);
    if (!this->nextTokenAsInt(lineStream, pre)) { return false; }
    if (!this->nextTokenAsInt(lineStream, post)) { return false; }
    if (pre != 1 - post) {
        this->error = "Axiom used effect with non-binary variable";
        return false;
    }
    axiom.effect.valueIndex = post;
    if (!this->isNextLine("end_rule")) { return false; }
    return true;
}

bool SASParser::parseAssignment(istream &aStream, const char delimiter,
                                vector<SASVariable> &variables,
                                vector<SASVariableAssignment> &assignments) {
    int nAssignments;
    if (!this->nextTokenAsInt(aStream, nAssignments, delimiter)) { return false; }
    assignments.resize(nAssignments);
    for (int i = 0; i < nAssignments; ++i) {
        int var, val;
        if (!this->nextTokenAsInt(aStream, var, ' ')) { return false; }
        assignments[i].variable = &(variables[var]);
        if (!this->nextTokenAsInt(aStream, val, delimiter)) { return false; }
        assignments[i].valueIndex = val;
    }
    return true;
}

bool SASParser::nextToken(istream &tokenStream, string& token, const char delimiter) {
    if (!getline(tokenStream, token, delimiter)) {
        this->error = "Unexpected end of stream";
        return false;
    }
    return true;
}

bool SASParser::nextTokenAsInt(istream &tokenStream, int& value, const char delimiter) {
    string token;
    if (!this->nextToken(tokenStream, token, delimiter)) { return false; }
    if (!tryParseInt(token, value)) {
        this->error = "Expected integer but got '" + token + "'";
        return false;
    }
    return true;
}

bool SASParser::isNextToken(istream &tokenStream, const string &text, const char delimiter) {
    string token;
    if (!this->nextToken(tokenStream, token, delimiter)) { return false; }
    if (token != text) {
        this->error = "Expected '" + text + "' but got '" + token + "'";
        return false;
    }
    return true;
}

bool SASParser::nextLine(string& line) {
    return this->nextToken(this->taskfile, line, '\n');
}

bool SASParser::nextLineAsInt(int& value) {
    return this->nextTokenAsInt(this->taskfile, value, '\n');
}

bool SASParser::nextLinesAsList(vector<string>& list) {
    list.clear();
    string line;
    int nLines;
    if (!this->nextLineAsInt(nLines)) { return false; }
    list.reserve(nLines);
    for (int i = 0; i < nLines; ++i) {
        if (!this->nextLine(line)) {
            this->error = "List doesn't have enough entries.";
            return false;
        }
        list.push_back(line);
    }
    return true;
}

bool SASParser::isNextLine(const string &text) {
    return this->isNextToken(this->taskfile, text, '\n');
}


bool DeleteRelaxer::deleteRelaxation(SASTask &sasTask, RelaxedTask &task) {
    if (sasTask.axioms.size() > 0) {
        this->error = "Axioms not supported";
        return false;
    }
    // start with one variable for each value of each SASVariable (some of those
    // might be removed again by relevance analysis)
    vector<vector<Variable*> > variableTranslations;
    variableTranslations.resize(sasTask.variables.size());
    int varID = 0;
    for (unsigned int sasVarId = 0; sasVarId < sasTask.variables.size(); ++sasVarId) {
        SASVariable* sasVar = &(sasTask.variables[sasVarId]);
        variableTranslations[sasVar->id].reserve(sasVar->values.size());
        for (unsigned int valId = 0; valId < sasVar->values.size(); ++valId) {
            string name = sasVar->values[valId];
            if (name == "<none of those>") {
                // try to keep names unique
                name = "None of var" + boost::lexical_cast<string>(sasVarId);
            };
            Variable *var = new Variable(name, varID++);
            task.variables.push_back(var);
            variableTranslations[sasVar->id].push_back(var);
        }
    }
    // canonicalization (if @@precond is not needed it will be removed by the relevance analysis)
    Variable *dummyPrecondition = new Variable("@@precond", varID++);
    task.variables.push_back(dummyPrecondition);
    task.init = new Variable("@@init", varID++);
    task.variables.push_back(task.init);
    task.goal = new Variable("@@goal", varID++);
    task.variables.push_back(task.goal);

    State::setFullVariableSet(&task.variables);

    // Operator creating the initial state
    RelaxedOperator *initOperator = new RelaxedOperator(task.operators.size());
    initOperator->name = "@@init-operator";
    initOperator->baseCost = 0;
    initOperator->preconditions.add(task.init);
    foreach(SASVariableAssignment &assignment, sasTask.init) {
        Variable *var = variableTranslations[assignment.variable->id][assignment.valueIndex];
        initOperator->effects.add(var);
    }
    initOperator->effects.add(dummyPrecondition);
    task.operators.push_back(initOperator);

    // Operator achieving the goal
    RelaxedOperator *goalOperator = new RelaxedOperator(task.operators.size());
    goalOperator->name = "@@goal-operator";
    goalOperator->baseCost = 0;
    foreach(SASVariableAssignment &assignment, sasTask.goal) {
        Variable *var = variableTranslations[assignment.variable->id][assignment.valueIndex];
        goalOperator->preconditions.add(var);
    }
    goalOperator->effects.add(task.goal);
    task.operators.push_back(goalOperator);

    // Relax operators
    foreach(SASOperator &sasOp, sasTask.operators) {
        RelaxedOperator *op = new RelaxedOperator(task.operators.size());
        op->name = sasOp.name;
        op->baseCost = sasOp.cost;
        // every prevail condition of the SASOperator is a precondition of the RelaxedOperator
        foreach(SASVariableAssignment &sasPrevail, sasOp.prevail){
            Variable *var = variableTranslations[sasPrevail.variable->id][sasPrevail.valueIndex];
            op->preconditions.add(var);
        }
        foreach(SASEffect &sasEffect, sasOp.effects){
            if (sasEffect.condition.size() > 0) {
                this->error = "Conditional effects not supported";
                return false;
            }
            // sasEffect.valueIndexBefore == -1 means "don't care"
            // otherwise add it to preconditions
            if (sasEffect.valueIndexBefore != -1) {
                Variable *var = variableTranslations[sasEffect.variable->id][sasEffect.valueIndexBefore];
                op->preconditions.add(var);
            }
            // add effect
            Variable *var = variableTranslations[sasEffect.variable->id][sasEffect.valueIndexAfter];
            op->effects.add(var);
        }
        if (op->preconditions.size() == 0) {
            op->preconditions.add(dummyPrecondition);
        }
        task.operators.push_back(op);
    }
    return true;
}

bool tryParseInt(const string &str, int &value) {
    istringstream converterStream(str);
    char leftoverChar;
    if (!(converterStream >> value) || converterStream.get(leftoverChar)) {
        return false;
    }
    return true;
}
