#ifndef RELAXEDOPERATOR_H
#define RELAXEDOPERATOR_H

#include <string>
#include <iostream>
#include <fstream>
#include <map>

#include "Variable.h"

enum OperatorState {
    FORBIDDEN = -1,
};

class RelaxedOperator {
public:
    std::string name;
    int baseCost;
    VariableSet preconditions;
    int unsatisfiedPreconditions;
    Variable *preconditionChoice;
    VariableSet effects;
    bool isApplicable(const VariableSet &state) const;
    void apply(VariableSet &state) const;
};

inline bool RelaxedOperator::isApplicable(const VariableSet &state) const {
    return this->preconditions.isSubsetOf(state);
}

inline void RelaxedOperator::apply(VariableSet &state) const {
    state.inplaceUnion(this->effects);
}

typedef std::map<RelaxedOperator *, int> OperatorCosts;
typedef OperatorCosts::value_type OperatorCostEntry;

#endif
