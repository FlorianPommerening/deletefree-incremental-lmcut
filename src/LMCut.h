#ifndef LMCUT_H_
#define LMCUT_H_

#include "Landmark.h"
#include "RelaxedTask.h"

int lmCut(RelaxedTask &task);
int lmCut(RelaxedTask &task, VariableSet &state, OperatorCosts &operatorCosts,
          std::list<Landmark> &landmarks, std::map<RelaxedOperator *, Landmark *> &operatorToLandmark);
void findCut(RelaxedTask &task, VariableSet &state, OperatorCosts &operatorCosts, Landmark &cut);

#endif /* LMCUT_H_ */
