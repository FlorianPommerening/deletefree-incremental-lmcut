#ifndef STEINERTREEIMPROVE_H_
#define STEINERTREEIMPROVE_H_

#include "Variable.h"
#include "RelaxedOperator.h"
#include "RelaxedTask.h"

#include <vector>

typedef std::pair<RelaxedOperator *, Variable *> PlanSetEntry;
typedef std::vector<PlanSetEntry> PlanSet;
typedef std::vector<RelaxedOperator *> Plan;

/*
 * Finds a plan with cost h^set-additive
 * TODO: is this really set-additive? or what is the difference to h^add
 * and returns it as a set of variables together with their h^add achievers
 * use planCost() to determine its cost and serializePlan() to get a serialized version of it.
 */
PlanSet discoverPlan(const RelaxedTask &task, std::vector<RelaxedOperator *> &hAddAchiever,
                     const State *initialState=NULL, Variable *goalVariable=NULL, const State *ignoredAddEffects=NULL);

/*
 * Given an existing plan in set form, this will return a plan that results from the given plan by continuously applying the Steiner tree improvement procedure
 * until it can no longer be optimized
 */
PlanSet optimizePlan(const RelaxedTask &task, PlanSet &planSet, std::vector<RelaxedOperator *> &hAddAchiever);

/*
 * Given an existing serialized plan, this will return a plan that results from the given plan by continuously applying the Steiner tree improvement procedure
 * until it can no longer be optimized
 */
PlanSet optimizePlan(const RelaxedTask &task, Plan &plan);

/*
 * The cost of an unserialized plan is the sum of the base cost of all actions occurring in it (each action only counted once)
 */
int planCost(PlanSet &planSet);

/*
 * returns a serialized version of the plan. I.e. an ordered list containing the actions in the plan that is applicable in the initial state
 */
std::vector<RelaxedOperator *> serializePlan(const PlanSet &planSet, const State &initialState);


#endif /* STEINERTREEIMPROVE_H_ */
