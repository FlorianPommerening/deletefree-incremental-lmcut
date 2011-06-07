#include <algorithm>
#include <iostream>

#include "Variable.h"

using namespace std;

Variable::Variable(string name): name(name) {
}

VariableSet::VariableSet() {
}

void VariableSet::add(Variable *element) {
    this->variables.insert(element);
}

void VariableSet::setToUnion(const VariableSet &set1, const VariableSet &set2) {
    this->variables.clear();
    set_union(set1.variables.begin(), set1.variables.end(),
              set2.variables.begin(), set2.variables.end(),
              inserter(this->variables, this->variables.begin()));
}

bool VariableSet::isDisjointWith(const VariableSet &other) const {
    if (this->variables.empty() || other.variables.empty()) {
        return true;
    }
    set<Variable *>::iterator it1 = this->variables.begin();
    set<Variable *>::iterator last1 = this->variables.end();
    set<Variable *>::iterator it2 = other.variables.begin();
    set<Variable *>::iterator last2 = other.variables.end();
    if (*it1 > *(other.variables.rbegin()) || *it2 > *(this->variables.rbegin())) {
        return true;
    }
    while (it1!=last1 && it2!=last2)
    {
      if (*it1 == *it2) return false;
      else if (*it1 < *it2) ++it1;
      else ++it2;
    }
    return true;
}

bool VariableSet::isSubsetOf(const VariableSet &other) const {
    return includes(other.variables.begin(), other.variables.end(),
                    this->variables.begin(), this->variables.end());
}

void VariableSet::removeIrrelevant(map<Variable *, bool> &relevant) {
    set<Variable *>::iterator it = this->variables.begin();
    while (it != this->variables.end()) {
        // copy iterator so it can be used for erase without breaking the loop
        set<Variable *>::iterator current = it;
        if (!relevant[*current])
            this->variables.erase(current);
        ++it;
    }
}
