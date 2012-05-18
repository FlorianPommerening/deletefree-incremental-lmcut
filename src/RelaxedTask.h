#ifndef RELAXEDTASK_H
#define RELAXEDTASK_H

#include <string>
#include <fstream>

#include "Variable.h"
#include "RelaxedOperator.h"

/*
 * A relaxed (or delete-free) planning task in canonical form
 *  (only one goal literal, only one literal in initial state and at least one precondition in each operator)
 */
class RelaxedTask {
public:
    RelaxedTask();
    ~RelaxedTask();
    /*
     * copy ctor and assignment operator throw exceptions to avoid accidental usage
     */
    RelaxedTask(RelaxedTask const &other);
    /*
     * copy ctor and assignment operator throw exceptions to avoid accidental usage
     */
    RelaxedTask& operator=(const RelaxedTask &rhs);

    // not a set of variables here, since all tasks are in canonical form
    Variable *init;
    // not a set of variables here, since all tasks are in canonical form
    Variable *goal;
    // using list here so pointers stay valid even if entries are deleted afterwards
    std::vector<Variable *> variables;
    std::vector<RelaxedOperator *> operators;
    // Operators without base cost are used in unit propagation. They are determined
    // while cross-referencing the task
    std::vector<RelaxedOperator *> zeroBaseCostOperators;

    void parseFile(const char *filename);
    // find a variable with that name and return its address
    Variable *getVariable(const std::string &name) const;
    // relevance analysis
    bool removeUnnecessaryParts(std::vector<std::pair<std::pair<std::string, float>, std::pair<int, int> > > &filteredElements);
    // creates mappings from effect to operator and from precondition to operator
    void crossreference();

    void printReadable() const;

private:
    bool filterFirstAchieversForRelevantVariable(std::vector<bool> &variableNecesary, std::vector<bool> &operatorNecesary, int *filteredVariables, int *filteredOperators);
    void parseTask(std::ifstream &taskfile);
    template <class VariableSet>
    void parseVariableSet(std::ifstream &taskfile, VariableSet &set);
};

#endif
