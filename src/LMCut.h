#ifndef LMCUT_H_
#define LMCUT_H_

#include <map>
#include <vector>

#include "RelaxedTask.h"

int calculateLMCut(RelaxedTask &task);

class Landmark {
public:
    typedef std::map<RelaxedOperator *, int>::value_type value_type;
    typedef std::map<RelaxedOperator *, int>::iterator iterator;
    typedef std::map<RelaxedOperator *, int>::const_iterator const_iterator;
    int cost;
    void add(RelaxedOperator *op, int opCost);
    void remove(RelaxedOperator *op);
    int size() {return this->operatorEntries.size(); }

    // allow iteration over operators
    iterator begin() { return this->operatorEntries.begin(); }
    iterator end() { return this->operatorEntries.end(); }
    const_iterator begin() const  { return this->operatorEntries.begin(); }
    const_iterator end() const { return this->operatorEntries.end(); }
    // allow searching in a list of Landmarks
    // we will never create duplicate landmarks so instead of comparing their content,
    // we just compare the address (i.e. no two Landmark objects are the same)
    bool operator==(const Landmark &other) const {
        return (this == &other);
    }
private:
    // this copies the cost values for each operator which uses more space
    // but has a nicer interface (remove needs to know the cost of all operators in the LM)
    // if there are problems with running out of memory, change this to
    // vector<RelaxedOperator *>
    std::map<RelaxedOperator *, int> operatorEntries;
};

class LMCutState {
public:
    LMCutState(RelaxedTask &task);
    LMCutState(const LMCutState &other);
    LMCutState& operator=(const LMCutState &rhs);

    int initialState();
    int operatorApplied(RelaxedOperator *appliedOp, VariableSet &resultingState);
    int operatorForbidden(RelaxedOperator *forbiddenOp, VariableSet &resultingState);
    int heuristicValue;
private:
    int lmCut(VariableSet &state);
    void findCut(VariableSet &state, Landmark &cut);
    RelaxedTask *task;
    // has to be a list so pointers stay valid
    std::list<Landmark> landmarks;
    OperatorCosts operatorCost;
    std::map<RelaxedOperator *, Landmark *> operatorToLandmark;
};

#endif /* LMCUT_H_ */
