#include <stdlib.h>

#include "SASTask.h"

using namespace std;

bool SASParser::parseTask(const string &taskFilename, const string &translationKeyFilename,
                          SASTask &taskOut) {
    this->taskfile = ifstream(filename);
    int metric;
    bool success = (
            this->parseMetric(metric) &&
            this->parseVariables(taskOut.variables) &&
            this->parseTranslationKey(translationKeyFilename, taskOut.variables) &&
            this->parseInitialState(taskOut.variables, taskOut.init) &&
            this->parseGoal(taskOut.variables, taskOut.goal) &&
            this->parseOperators(metric, taskOut.operators) &&
            this->parseAxioms(taskOut.axioms));
    this->taskfile.close();
    return success;
}

bool SASParser::parseMetric(int &metric) {

}

bool SASParser::parseVariables(vector<SASVariable> &variables) {

}

bool SASParser::parseTranslationKey(const string &translationKeyFilename,
                                    vector<SASVariable> &variables) {

}

bool SASParser::parseInitialState(vector<SASVariable> &variables,
                                  vector<SASVariableAssignment> &init) {

}

bool SASParser::parseGoal(vector<SASVariable> &variables,
                          vector<SASVariableAssignment> &goal) {

}

bool SASParser::parseOperators(int metric, vector<SASOperator> &operators) {

}

bool SASParser::parseOperator(int metric, SASOperator &op) {

}

bool SASParser::parseAxioms(vector<SASAxiom> &axioms) {

}

bool SASParser::parseAxiom(SASAxiom &axiom) {

}

bool SASParser::nextLine(string& line) {
    if (!getline(this->taskfile, line)) {
        this->error = "Unexpected end of file";
        return false;
    }
    return true;
}

bool SASParser::nextLineAsInt(int& value) {
    string line;
    if (!this->nextLine(line)) return false;
    const char *lastParsed = line.c_str();
    value = (int) strtol(line.c_str(), &lastParsed, 10);
    if (*lastParsed == '\0')
        return true;
    // else
    return false;
}

bool SASParser::isNextLine(const string &text) {
    string line;
    if (!this->nextLine(line)) return false;
    if (line != text) {
        this->error = "Expected '" + text + "' but got '" + line + "'";
        return false;
    }
    return true;
}
