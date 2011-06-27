#include <algorithm>
#include <iostream>

#include "Variable.h"

using namespace std;

Variable::Variable(string name): name(name) {
}

Variable::Variable(): name("@@DUMMY") {
}

Variable VariableSet::EmptyKey = Variable("@@EMPTY_KEY");
Variable VariableSet::DeletedKey = Variable("@@DELETED_KEY");

VariableSet::VariableSet() {
    this->variables.set_empty_key(&(VariableSet::EmptyKey));
    this->variables.set_deleted_key(&(VariableSet::DeletedKey));
}

VariableSet::VariableSet(const VariableSet &other): variables(other.variables) {
}

VariableSet& VariableSet::operator =(const VariableSet &other) {
    this->variables = other.variables;
    return *this;
}

void VariableSet::add(Variable *element) {
    this->variables.insert(element);
}

void VariableSet::clear() {
    this->variables.clear();
}

bool VariableSet::contains(Variable *element) const {
    return (this->variables.find(element) != this->variables.end());
}

void VariableSet::inplaceUnion(const VariableSet &other) {
    this->variables.insert(other.begin(), other.end());
}

bool VariableSet::isDisjointWith(const VariableSet &other) const {
    if (this->variables.empty() || other.variables.empty()) {
        return true;
    }
    const_iterator it, last;
    const VariableSet *largerSet;
    if (this->size() < other.size()) {
        it = this->variables.begin();
        last = this->variables.end();
        largerSet = &other;
    } else {
        it = other.variables.begin();
        last = other.variables.end();
        largerSet = this;
    }
    for (; it != last; ++it) {
        if (largerSet->contains(*it))
            return false;
    }
    return true;
}

bool VariableSet::isSubsetOf(const VariableSet &other) const {
    // could do more checks with empty() but this will almost never happen,
    // so the additional test would probably make it slower instead of faster
    if (this->variables.size() > other.variables.size())
        return false;
    for (const_iterator it = this->variables.begin(); it != this->variables.end(); ++it) {
        if (!other.contains(*it))
            return false;
    }
    return true;
}

void VariableSet::removeIrrelevant(PointerMap<Variable, bool> &relevant) {
    // iterator in dense_hash_set stay valid during erase, so no need to copy it before
    for (iterator it = this->variables.begin(); it != this->variables.end(); ++it) {
        if (!relevant[*it])
            this->variables.erase(it);
    }
}
