#ifndef HMAX_H_
#define HMAX_H_

#include "RelaxedTask.h"
#include "Variable.h"
#include "UIntEx.h"

UIntEx hmax(RelaxedTask &task);
UIntEx hmax(RelaxedTask &task, VariableSet &state);
UIntEx hmax(RelaxedTask &task, VariableSet &state, OperatorCosts &operatorCosts);

#endif
