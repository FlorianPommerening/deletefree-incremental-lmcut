#ifndef RELAXEDOPERATOR_H
#define RELAXEDOPERATOR_H

#include <string>
#include <iostream>
#include <fstream>

#include "Variable.h"
#include "UIntEx.h"
#include "PointerMap.h"

/*
 * An operator in a delete-free planning task.
 * Some temporary variables for h^max and h^LM-cut calculation are also stored here for faster access.
 */
class RelaxedOperator {
public:
    std::string name;
    int baseCost;
    VariableSet preconditions;
    // temporary variable for h^max and h^LM-cut calculation
    int unsatisfiedPreconditions;
    // temporary variable for h^max and h^LM-cut calculation
    Variable *preconditionChoice;
    VariableSet effects;
    /*
     * Returns true iff this operator is applicable in 'state'
     */
    bool isApplicable(const VariableSet &state) const {
        return this->preconditions.isSubsetOf(state);
    }
    /*
     * Changes 'state' to represent the state that results from applying this operator in state.
     * This operator must be applicable in 'state' for a correct result. To speed things up this is not checked again!
     */
    void apply(VariableSet &state) const {
        state.inplaceUnion(this->effects);
    }
};

/*
 * Operator costs map each allowed operator to a finite cost and all forbidden operators to infinity.
 */
typedef PointerMap<RelaxedOperator, UIntEx> OperatorCosts;
typedef OperatorCosts::value_type OperatorCostEntry;

#endif
