#ifndef LANDMARK_H_
#define LANDMARK_H_

#include "PointerMap.h"

#include "RelaxedOperator.h"

/*
 * Represents a disjunctive action landmark and its corresponding cost partitioning
 * This is represented as a mapping from operators to cost s.t. the domain of this mapping
 * is the set of operators in the landmark.
 * The cost function maps each operator to the cost it had during the creation of the landmark.
 * This is used to adjust the cost of the landmark when its most expensive operator is removed.
 */
class Landmark {
public:
    // TODO introduce iterator over operators only (python "map.keys()")
    typedef PointerMap<RelaxedOperator, int>::value_type value_type;
    typedef PointerMap<RelaxedOperator, int>::iterator iterator;
    typedef PointerMap<RelaxedOperator, int>::const_iterator const_iterator;
    // The cost of the operator is updated on each change to the landmark, which is cheaper than recomputing it each time
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
    PointerMap<RelaxedOperator, int> operatorEntries;
};

#endif /* LANDMARK_H_ */
