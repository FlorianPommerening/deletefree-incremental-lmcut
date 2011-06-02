#ifndef SASTASK_H_
#define SASTASK_H_

#include <vector>
#include <string>
#include <iostream>

struct SASVariable;
struct SASVariableAssignment;
struct SASEffect;
struct SASOperator;
struct SASAxiom;

struct SASTask {
    std::vector<SASVariable> variables;
    std::vector<SASVariableAssignment> init;
    std::vector<SASVariableAssignment> goal;
    std::vector<SASOperator> operators;
    std::vector<SASAxiom> axioms;
};

struct SASVariable {
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

class SASParser {
public:
    bool parseTask(const std::string &taskFilename, const std::string &translationKeyFilename,
                   SASTask &task);
    std::string getLastError() { return this->error; }
private:
    std::string error;
    std::ifstream taskfile;
    bool parseMetric(int &metric);
    bool parseVariables(std::vector<SASVariable> &variables);
    bool parseTranslationKey(const std::string &translationKeyFilename,
                            std::vector<SASVariable> &variables);
    bool parseInitialState(std::vector<SASVariable> &variables,
                          std::vector<SASVariableAssignment> &init);
    bool parseGoal(std::vector<SASVariable> &variables,
                  std::vector<SASVariableAssignment> &goal);
    bool parseOperators(int metric, std::vector<SASOperator> &operators);
    bool parseOperator(int metric, SASOperator &op);
    bool parseAxioms(std::vector<SASAxiom> &axioms);
    bool parseAxiom(SASAxiom &axiom);

    bool nextLine(std::string &line);
    bool nextLineAsInt(int &value);
    bool isNextLine(const std::string &text);
};

#endif /* SASTASK_H_ */
