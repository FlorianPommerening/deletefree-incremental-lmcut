#ifndef HMAX_H_
#define HMAX_H_

#include "RelaxedTask.h"
#include "Variable.h"

int hmax(RelaxedTask &task);
int hmax(RelaxedTask &task, VariableSet &state);
int hmax(RelaxedTask &task, VariableSet &state, OperatorCosts &operatorCosts);

#endif
