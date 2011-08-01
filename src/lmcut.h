#ifndef LMCUT_H_
#define LMCUT_H_

#include "Landmark.h"
#include "RelaxedTask.h"
#include "UIntEx.h"

/*
 * Calculates h^LM-cut for the initial state of 'task'.
 * This will recreate the operator cost function (defined by the operator's
 * base costs) in memory, so if it is called more often the other overload should be used.
 */
UIntEx lmCut(RelaxedTask &task);
/*
 * Calculates h^LM-cut for 'state' in 'task'.
 * This will recreate the operator cost function (defined by the operator's
 * base costs) in memory, so if it is called more often the other overload should be used.
 */
UIntEx lmCut(RelaxedTask &task, VariableSet &state);
/*
 * Calculates h^LM-cut for 'state' in 'task' using the operator cost mapping 'operatorCosts'
 * newly discovered landmarks will be added to 'landmarks'. This list can already contain some landmarks,
 * which are left untouched. To distinguish the newly added landmarks the pointer 'firstAdded' will be
 * set to an iterator marking the first landmark that was added or landmarks.end() if no landmarks were added.
 * The cost function 'operatorCosts' will be adjusted for each discovered landmark, by decreasing the cost
 * of each operator in the landmark by the cost of the landmark
 */
UIntEx lmCut(RelaxedTask &task, VariableSet &state, OperatorCosts &operatorCosts,
             std::list<Landmark> &landmarks, std::list<Landmark>::iterator *firstAdded=NULL);
/*
 * Discovers a cut in the justification graph, i.e. a set of operators, whose precondition choice can be reached
 * from the initial state without reaching a variable in the goal zone, and whose effects contain a variable in the goal zone.
 * This assumes that hmax costs are set for each variable and preconditionChoice is set for each operator in 'task'.
 * The operators defining the cut are added to the landmark 'cut'.
 */
void findCut(RelaxedTask &task, VariableSet &state, OperatorCosts &operatorCosts, Landmark &cut);

#endif /* LMCUT_H_ */
