#ifndef SASTASK_H_
#define SASTASK_H_

#include <vector>
#include <string>
#include <fstream>

#include "RelaxedTask.h"

// forward declarations
struct SASVariable;
struct SASVariableAssignment;
struct SASEffect;
struct SASOperator;
struct SASAxiom;

/*
 * SAS+ planning task
 */
class SASTask {
public:
    std::vector<SASVariable> variables;
    std::vector<SASVariableAssignment> init;
    std::vector<SASVariableAssignment> goal;
    std::vector<SASOperator> operators;
    std::vector<SASAxiom> axioms;
};

struct SASVariable {
    int id;
    std::vector<std::string> values;
    int axiomLayer;
};

struct SASVariableAssignment {
    SASVariable *variable;
    int valueIndex;
};

struct SASEffect {
    std::vector<SASVariableAssignment> condition;
    SASVariable *variable;
    int valueIndexBefore;
    int valueIndexAfter;
};

struct SASOperator {
    std::string name;
    int cost;
    std::vector<SASVariableAssignment> prevail;
    std::vector<SASEffect> effects;
};

struct SASAxiom {
    std::vector<SASVariableAssignment> condition;
    SASVariableAssignment effect;
};

/*
 * Used to parse a SASTask from a file and keep track of any errors that occur while parsing
 */
class SASParser {
public:
    bool parseTask(const std::string &taskFilename, SASTask &task);
    std::string getLastError() { return this->error; }
private:
    std::string error;
    std::ifstream taskfile;
    bool parseVersion(int &version);
    bool parseMetric(int &metric);
    bool parseVariables(std::vector<SASVariable> &variables);
    bool parseVariable(std::vector<SASVariable> &variables, int varId);
    /* Mutex groups are ignored for now */
    bool parseMutexGroups();
    bool parseMutexGroup();
    bool parseInitialState(std::vector<SASVariable> &variables,
                          std::vector<SASVariableAssignment> &init);
    bool parseGoal(std::vector<SASVariable> &variables,
                  std::vector<SASVariableAssignment> &goal);
    bool parseOperators(std::vector<SASVariable> &variables, int metric,
                        std::vector<SASOperator> &operators);
    bool parseOperator(std::vector<SASVariable> &variables, int metric,
                       SASOperator &op);
    bool parseAxioms(std::vector<SASVariable> &variables,
                     std::vector<SASAxiom> &axioms);
    bool parseAxiom(std::vector<SASVariable> &variables,
                    SASAxiom &axiom);
    bool parseAssignment(std::istream &aStream, const char delimiter,
                         std::vector<SASVariable> &variables,
                         std::vector<SASVariableAssignment> &assignments);
    bool nextToken(std::istream &tokenStream, std::string& token, const char delimiter=' ');
    bool nextTokenAsInt(std::istream &tokenStream, int& value, const char delimiter=' ');
    bool isNextToken(std::istream &tokenStream, const std::string &text, const char delimiter=' ');

    bool nextLine(std::string &line);
    bool nextLineAsInt(int &value);
    bool nextLinesAsList(std::vector<std::string>& list);
    bool isNextLine(const std::string &text);
};

/*
 * Generates the delete relaxation of an SASTask and keeps track of errors that occur during the relaxation.
 */
class DeleteRelaxer {
public:
    bool deleteRelaxation(SASTask &sasTask, RelaxedTask &task);
    std::string getLastError() { return this->error; }
private:
    std::string error;
};


bool tryParseInt(const std::string &str, int &value);
std::string intToStr(int value);

#endif /* SASTASK_H_ */
