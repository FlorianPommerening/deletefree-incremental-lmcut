#include <algorithm>
#include <iostream>

#include "Variable.h"

using namespace std;

Variable::Variable(string name, int id): name(name), hmax(0), closed(false), id(id) {
}

Variable::Variable(): name("@@DUMMY"), hmax(0), closed(false), id(-1) {
}
void Effects::inplaceIntersection(const Effects &other) {
    const vector<Variable *> *smaller = &this->entries;
    const vector<Variable *> *larger = &other.entries;
    if (larger->size() < smaller->size()) {
        swap(smaller, larger);
    }
    vector<Variable *> intersection;
    vector<Variable *>::const_iterator largerBegin = larger->begin();
    vector<Variable *>::const_iterator largerEnd = larger->end();
    foreach(Variable *v, *smaller) {
        if (find(largerBegin, largerEnd, v) != largerEnd) {
            intersection.push_back(v);
        }
    }
    swap(this->entries, intersection);
}

void Effects::removeUnnecessary(const vector<bool> &variableNecessary) {
    vector<Variable *> relevantSubset;
    relevantSubset.reserve(this->entries.size());
    foreach(Variable *v, this->entries) {
        if (variableNecessary[v->id]) {
            relevantSubset.push_back(v);
        }
    }
    swap(this->entries, relevantSubset);
}



int State::nVariables = 0;
vector<Variable *> *State::variables;
