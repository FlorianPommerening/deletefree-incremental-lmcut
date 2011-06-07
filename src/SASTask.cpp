#include <stdlib.h>
#include <sstream>
#include <boost/algorithm/string/predicate.hpp>

#include <iostream>

#include "SASTask.h"
#include "foreach.h"

using namespace std;

bool SASParser::parseTask(const char *taskFilename, const char *translationKeyFilename,
                          SASTask &taskOut) {
    this->taskfile.open(taskFilename);
    int metric;
    bool success = (
            this->parseMetric(metric) &&
            this->parseVariables(taskOut.variables) &&
            this->parseInitialState(taskOut.variables, taskOut.init) &&
            this->parseGoal(taskOut.variables, taskOut.goal) &&
            this->parseOperators(taskOut.variables, metric, taskOut.operators) &&
            this->parseAxioms(taskOut.variables, taskOut.axioms));
    this->taskfile.close();
    if (!success || translationKeyFilename == NULL)
        return success;

    this->taskfile.open(translationKeyFilename);
    success = this->parseTranslationKey(taskOut.variables);
    this->taskfile.close();
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
    vector<string> variableLines;
    if (!this->isNextLine("begin_variables")) return false;
    if (!this->nextLinesAsList(variableLines)) return false;
    variables.resize(variableLines.size());
    for (unsigned int varId = 0; varId < variableLines.size(); ++varId) {
        stringstream lineStream(variableLines[varId]);
        string expectedName = "var" + intToStr(varId);
        if (!this->isNextToken(lineStream, expectedName)) return false;
        int range;
        if (!this->nextTokenAsInt(lineStream, range)) return false;
        variables[varId].values.reserve(range);
        for (int i = 0; i < range; ++i) {
            variables[varId].values.push_back(intToStr(i));
        }
        if (!this->nextTokenAsInt(lineStream, variables[varId].axiomLayer)) return false;
    }
    if (!this->isNextLine("end_variables")) return false;
    return true;
}

bool SASParser::parseInitialState(vector<SASVariable> &variables,
                                  vector<SASVariableAssignment> &init) {
    if (!this->isNextLine("begin_state")) return false;
    init.resize(variables.size());
    for (unsigned int i = 0; i < variables.size(); ++i) {
        int valueIndex;
        if (!this->nextLineAsInt(valueIndex)) return false;
        init[i].variable = &(variables[i]);
        init[i].valueIndex = valueIndex;
    }
    if (!this->isNextLine("end_state")) return false;
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
    if (!this->nextLineAsInt(nOperators)) return false;
    operators.resize(nOperators);
    for (int i = 0; i < nOperators; ++i) {
        if (!parseOperator(variables, metric, operators[i])) return false;
    }
    return true;
}

bool SASParser::parseOperator(vector<SASVariable> &variables, int metric,
                              SASOperator &op) {
    if (!this->isNextLine("begin_operator")) return false;
    if (!this->nextLine(op.name)) return false;
    if (!this->parseAssignment(taskfile, '\n', variables, op.prevail)) return false;

    vector<string> effectLines;
    if (!this->nextLinesAsList(effectLines)) return false;
    op.effects.resize(effectLines.size());
    for (unsigned int i = 0; i < effectLines.size(); ++i) {
        stringstream lineStream(effectLines[i]);
        if (!this->parseAssignment(lineStream, ' ', variables, op.effects[i].condition)) return false;
        int var;
        if (!this->nextTokenAsInt(lineStream, var)) return false;
        op.effects[i].variable = &(variables[var]);
        if (!this->nextTokenAsInt(lineStream, op.effects[i].valueIndexBefore)) return false;
        if (!this->nextTokenAsInt(lineStream, op.effects[i].valueIndexAfter)) return false;
    }
    if (!this->nextLineAsInt(op.cost)) return false;
    if (metric == 0) {
            op.cost = 1;
    }
    if (!this->isNextLine("end_operator")) return false;
    return true;
}

bool SASParser::parseAxioms(vector<SASVariable> &variables,
                            vector<SASAxiom> &axioms) {
    int nAxioms;
    if (!this->nextLineAsInt(nAxioms)) return false;
    axioms.resize(nAxioms);
    for (int i = 0; i < nAxioms; ++i) {
        if (!parseAxiom(variables, axioms[i])) return false;
    }
    return true;
}

bool SASParser::parseAxiom(vector<SASVariable> &variables,
                           SASAxiom &axiom) {
    if (!this->isNextLine("begin_rule")) return false;
    if (!this->parseAssignment(taskfile, '\n', variables, axiom.condition)) return false;
    string effectLine;
    if (!this->nextLine(effectLine)) return false;
    stringstream lineStream(effectLine);
    int var, pre, post;
    if (!this->nextTokenAsInt(lineStream, var)) return false;
    axiom.effect.variable = &(variables[var]);
    if (!this->nextTokenAsInt(lineStream, pre)) return false;
    if (!this->nextTokenAsInt(lineStream, post)) return false;
    if (pre != 1 - post) {
        this->error = "Axiom used effect with non-binary variable";
        return false;
    }
    axiom.effect.valueIndex = post;
    if (!this->isNextLine("end_rule")) return false;
    return true;
}

bool SASParser::parseAssignment(istream &aStream, const char delimiter,
                                vector<SASVariable> &variables,
                                vector<SASVariableAssignment> &assignments) {
    int nAssignments;
    if (!this->nextTokenAsInt(aStream, nAssignments, delimiter)) return false;
    assignments.resize(nAssignments);
    for (int i = 0; i < nAssignments; ++i) {
        int var, val;
        if (!this->nextTokenAsInt(aStream, var, ' ')) return false;
        assignments[i].variable = &(variables[var]);
        if (!this->nextTokenAsInt(aStream, val, delimiter)) return false;
        assignments[i].valueIndex = val;
    }
    return true;
}

bool SASParser::parseTranslationKey(vector<SASVariable> &variables) {
    for (unsigned int varId = 0; varId < variables.size(); ++varId) {
        if (!this->isNextLine("var" + intToStr(varId) + ":")) return false;
        for (unsigned int valId = 0; valId < variables[varId].values.size(); ++valId) {
            string valLine;
            if (!this->nextLine(valLine)) return false;
            string prefix = "  " + intToStr(valId) + ": ";
            if (!boost::starts_with(valLine, prefix)) {
                this->error = "Expected line starting with '" + prefix + "' but got '" + valLine + "'";
                return false;
            }
            variables[varId].values[valId] = valLine.substr(prefix.length());
        }
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
    if (!this->nextToken(tokenStream, token, delimiter)) return false;
    if (!tryParseInt(token, value)) {
        this->error = "Expected integer but got '" + token + "'";
        return false;
    }
    return true;
}

bool SASParser::isNextToken(istream &tokenStream, const string &text, const char delimiter) {
    string token;
    if (!this->nextToken(tokenStream, token, delimiter)) return false;
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
    if (!this->nextLineAsInt(nLines)) return false;
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
    map<SASVariable*, vector<Variable*> > variableTranslations;
    for (unsigned int varId = 0; varId < sasTask.variables.size(); ++varId) {
        SASVariable* sasVar = &(sasTask.variables[varId]);
        variableTranslations[sasVar].reserve(sasVar->values.size());
        for (unsigned int valId = 0; valId < sasVar->values.size(); ++valId) {
            string name = sasVar->values[valId];
            if (name == "<none of those>") {
                name = "None of var" + intToStr(varId);
            };
            task.variables.push_back(Variable(name));
            variableTranslations[sasVar].push_back(&(task.variables.back()));
        }
    }
    // canonicalization (if @@precond is not needed it will be removed by the relevance analysis)
    task.variables.push_back(Variable("@@precond"));
    Variable *dummyPrecondition = &(task.variables.back());
    task.variables.push_back(Variable("@@init"));
    task.init = &(task.variables.back());
    task.variables.push_back(Variable("@@goal"));
    task.goal = &(task.variables.back());

    RelaxedOperator initOperator;
    initOperator.name = "@@init-operator";
    initOperator.cost = 0;
    initOperator.preconditions.add(task.init);
    foreach(SASVariableAssignment &assignment, sasTask.init) {
        Variable *var = variableTranslations[assignment.variable][assignment.valueIndex];
        initOperator.effects.add(var);
    }
    initOperator.effects.add(dummyPrecondition);
    task.operators.push_back(initOperator);

    RelaxedOperator goalOperator;
    goalOperator.name = "@@goal-operator";
    goalOperator.cost = 0;
    foreach(SASVariableAssignment &assignment, sasTask.goal) {
        Variable *var = variableTranslations[assignment.variable][assignment.valueIndex];
        goalOperator.preconditions.add(var);
    }
    goalOperator.effects.add(task.goal);
    task.operators.push_back(goalOperator);

    foreach(SASOperator &sasOp, sasTask.operators) {
        RelaxedOperator op;
        op.name = sasOp.name;
        op.cost = sasOp.cost;
        foreach(SASVariableAssignment &sasPrevail, sasOp.prevail){
            Variable *var = variableTranslations[sasPrevail.variable][sasPrevail.valueIndex];
            op.preconditions.add(var);
        }
        foreach(SASEffect &sasEffect, sasOp.effects){
            if (sasEffect.condition.size() > 0) {
                this->error = "Conditional effects not supported";
                return false;
            }
            // sasEffect.valueIndexBefore == -1 means "don't care"
            if (sasEffect.valueIndexBefore != -1) {
                Variable *var = variableTranslations[sasEffect.variable][sasEffect.valueIndexBefore];
                op.preconditions.add(var);
            }
            Variable *var = variableTranslations[sasEffect.variable][sasEffect.valueIndexAfter];
            op.effects.add(var);
        }
        if (op.preconditions.size() == 0) {
            op.preconditions.add(dummyPrecondition);
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

string intToStr(int value) {
    ostringstream sstream;
    sstream << value;
    return sstream.str();
}

