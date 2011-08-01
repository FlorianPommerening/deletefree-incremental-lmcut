#ifndef HMAX_H_
#define HMAX_H_

#include "RelaxedTask.h"
#include "Variable.h"
#include "UIntEx.h"

/*
 * Calculates the h^max value of the initial state of 'task'.
 * The task has to be a cross-referenced relaxed task in canonical form.
 * The calculation will also set the property 'hmax' of each variable in the task
 * to the hmax cost of this variable and the property 'preconditionChoice' of each operator to
 * one variable with maximal hmax cost among the preconditions of this operator.
 * This will recreate the operator cost function (defined by the operator's
 * base costs) in memory, so if it is called more often the other overload should be used.
 */
UIntEx hmax(RelaxedTask &task);
/*
 * Calculates the h^max value of 'state' in 'task'.
 * The task has to be a cross-referenced relaxed task in canonical form.
 * The calculation will also set the property 'hmax' of each variable in the task
 * to the hmax cost of this variable and the property 'preconditionChoice' of each operator to
 * one variable with maximal hmax cost among the preconditions of this operator.
 * This will recreate the operator cost function (defined by the operator's
 * base costs) in memory, so if it is called more often the other overload should be used.
 */
UIntEx hmax(RelaxedTask &task, VariableSet &state);
/*
 * Calculates the h^max value of 'state' in 'task' using the cost function defined by 'operatorCosts'.
 * The task has to be a cross-referenced relaxed task in canonical form.
 * The calculation will also set the property 'hmax' of each variable in the task
 * to the hmax cost of this variable and the property 'preconditionChoice' of each operator to
 * one variable with maximal hmax cost among the preconditions of this operator.
 */
UIntEx hmax(RelaxedTask &task, VariableSet &state, OperatorCosts &operatorCosts);

#endif
