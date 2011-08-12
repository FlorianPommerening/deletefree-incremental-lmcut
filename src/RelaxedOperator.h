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
    RelaxedOperator(): id(-1) {}
    RelaxedOperator(int id): id(id) {}

    std::string name;
    int baseCost;
    Preconditions preconditions;
    // temporary variable for h^max and h^LM-cut calculation
    int unsatisfiedPreconditions;
    // temporary variable for h^max and h^LM-cut calculation
    Variable *preconditionChoice;
    Effects effects;
    // values filled by cross-referencing the task
    int id;
    /*
     * Returns true iff this operator is applicable in 'state'
     */
    bool isApplicable(const State &state) const {
        return state.contains(this->preconditions);
    }
    /*
     * Changes 'state' to represent the state that results from applying this operator in state.
     * This operator must be applicable in 'state' for a correct result. To speed things up this is not checked again!
     */
    void apply(State &state) const {
        state.add(this->effects);
    }
};

/*
 * Operator costs map each allowed operator to a finite cost and all forbidden operators to infinity.
 */
typedef std::vector<UIntEx> OperatorCosts;

#endif
