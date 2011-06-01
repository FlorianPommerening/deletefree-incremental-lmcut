#include <algorithm>
#include <iostream>

#include "Variable.h"

Variable::Variable(std::string name): name(name) {
}

VariableSet::VariableSet() {
}

void VariableSet::add(Variable *element) {
    this->variables.insert(element);
}

void VariableSet::setToUnion(const VariableSet &set1, const VariableSet &set2) {
    this->variables.clear();
    std::set_union(set1.variables.begin(), set1.variables.end(),
                   set2.variables.begin(), set2.variables.end(),
                   std::inserter(this->variables, this->variables.begin()));
}

bool VariableSet::isDisjointWith(const VariableSet &other) const {
    if (this->variables.empty() || other.variables.empty()) {
        return true;
    }
    std::set<Variable *>::iterator it1 = this->variables.begin();
    std::set<Variable *>::iterator last1 = this->variables.end();
    std::set<Variable *>::iterator it2 = other.variables.begin();
    std::set<Variable *>::iterator last2 = other.variables.end();
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
    return std::includes(other.variables.begin(), other.variables.end(),
                         this->variables.begin(), this->variables.end());
}
