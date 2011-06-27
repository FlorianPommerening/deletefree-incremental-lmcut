#ifndef VARIABLE_H
#define VARIABLE_H

#include <google/dense_hash_set>
#include <boost/functional/hash.hpp>
#include <string>
#include <vector>
#include <map>

#include "UIntEx.h"

class RelaxedOperator;

struct Variable {
public:
    Variable(std::string name);
    std::string name;
    UIntEx hmax;
    bool closed;
    std::vector<RelaxedOperator *> precondition_of;
    std::vector<RelaxedOperator *> effect_of;
};

class VariableSet {
public:
    typedef google::dense_hash_set<Variable*, boost::hash<Variable*> >::iterator iterator;
    typedef google::dense_hash_set<Variable*, boost::hash<Variable*> >::const_iterator const_iterator;

    VariableSet();
    VariableSet(const VariableSet &other);
    VariableSet& operator =(const VariableSet &other);

    void clear();
    void add(Variable *element);
    bool contains(Variable *element) const;
    void inplaceUnion(const VariableSet &other);
    bool isDisjointWith(const VariableSet &other) const;
    bool isSubsetOf(const VariableSet &other) const;
    int size() const;
    void removeIrrelevant(std::map<Variable *, bool> &relevant);

    // allow iteration over set
    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;
private:
    google::dense_hash_set<Variable*, boost::hash<Variable*> > variables;
    // special value symbolizing an entry in the map that was deleted
    static Variable DeletedKey;
    // special value symbolizing an entry in the map that is not assigned yet
    static Variable EmptyKey;
};

inline int VariableSet::size() const {
    return this->variables.size();
}

inline VariableSet::iterator VariableSet::begin() {
    return this->variables.begin();
}

inline VariableSet::iterator VariableSet::end() {
    return this->variables.end();
}

inline VariableSet::const_iterator VariableSet::begin() const {
    return this->variables.begin();
}

inline VariableSet::const_iterator VariableSet::end() const {
    return this->variables.end();
}

#endif
