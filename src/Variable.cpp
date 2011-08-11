#include <algorithm>
#include <iostream>

#include "Variable.h"

using namespace std;

Variable::Variable(string name, int id): name(name), id(id) {
}

Variable::Variable(): name("@@DUMMY"), id(-1) {
}

int VariableSet::nVariables;
vector<Variable *> *VariableSet::variables;
