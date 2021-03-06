#include "Options.h"
#include "lmcut.h"
#include "foreach.h"
#include "hmax.h"
#include "SearchNode.h"

#include <stack>

using namespace std;

UIntEx lmCut(const RelaxedTask &task) {
    State initialState;
    initialState.add(task.init);
    return lmCut(task, initialState);
}

UIntEx lmCut(const RelaxedTask &task, const State &state) {
    // use default operator cost mapping
    OperatorCosts operatorCosts = OperatorCosts(task.operators.size());
    foreach(RelaxedOperator *op, task.operators) {
        operatorCosts[op->id] = op->baseCost;
    }
    // dummy list to contain the discovered landmark
    AbstractLandmarkCollection *landmarkCollection = NULL;
    if (task.isBinaryCostTask) {
        landmarkCollection = new BinaryCostLandmarkCollection(task.operators);
    }
    else {
        landmarkCollection = new ArbitraryCostLandmarkCollection(task.operators);
    }
    UIntEx result = lmCut(task, state, operatorCosts, landmarkCollection);
    delete landmarkCollection;
    return result;
}

UIntEx lmCut(const RelaxedTask &task, const State &state, OperatorCosts &operatorCosts, AbstractLandmarkCollection *landmarkCollection) {
    // calculating h^max also sets all hmax costs of variables and preconditionChoice values of operators
    UIntEx hmax_value = hmax(task, state, operatorCosts);
    if (!hmax_value.hasFiniteValue()) {
        // unsolvable problem
        return UIntEx::INF;
    }
    UIntEx lmcutValue = 0;
    // One new landmark is discovered in each iteration until h^max is 0
    Landmark cut;
    while (hmax_value != 0) {
        cut.clear();
        findCut(task, state, operatorCosts, &cut);
        LandmarkId landmarkId = landmarkCollection->addLandmark(cut, operatorCosts);
        const UIntEx landmarkCost = landmarkCollection->getLandmarkCost(landmarkId);
        lmcutValue += landmarkCost;
        // adjust cost function
        foreach(RelaxedOperator *op, landmarkCollection->iterateLandmark(landmarkId)) {
            operatorCosts[op->id] -= landmarkCost;
        }
        // recalculate hmax to check if we can discover another landmark
        hmax_value = hmax(task, state, operatorCosts);
    }
    return lmcutValue;
}

void findCut(const RelaxedTask &task, const State &state, const OperatorCosts &operatorCosts, Landmark *cut) {
    // First discover the goal zone by enumerating all variables that allow the goal to be reached with 0-cost.
    // That is, moving backwards from the goal along 0-cost operators from effect to preconditionChoice until no more
    // variables are discovered.
    State goalZone;
    vector<Variable *> goalStack;
    foreach(Variable *var, task.variables) {
        var->closed = false;
    }
    goalStack.push_back(task.goal);
    while (!goalStack.empty()) {
        Variable *var = goalStack.back();
        goalStack.pop_back();
        var->closed = true;
        goalZone.add(var);
        foreach(RelaxedOperator *op, var->effect_of) {
            if (operatorCosts[op->id] != 0 || op->preconditionChoice == NULL) {
                // avoid non-zero-cost operator, forbidden operator or unreachable operator
                // TODO: if there are operators with operatorCosts[op] != UIntEx::INF && op->preconditionChoice == NULL
                // they could probably be removed
                continue;
            }
            if (!op->preconditionChoice->closed) {
                goalStack.push_back(op->preconditionChoice);
            }
        }
    }

    // forward search starting from state (similar to hmax calculation)
    // reset temporary variables.
    foreach(RelaxedOperator *op, task.operators) {
        op->unsatisfiedPreconditions = op->preconditions.size();
    }
    foreach(Variable *var, task.variables) {
        var->closed = false;
    }

    stack<Variable *> reachedStack;
    foreach(Variable *var, state) {
        reachedStack.push(var);
    }
    while (!reachedStack.empty()) {
        Variable *var = reachedStack.top();
        reachedStack.pop();
        if (var->closed) {
            // already discovered this variable
            continue;
        }
        var->closed = true;
        foreach(RelaxedOperator *op, var->precondition_of) {
            unsigned int operatorCost;
            if (!operatorCosts[op->id].hasFiniteValue(operatorCost)) {
                // if the operator cost is not finite, the operator was previously forbidden
                continue;
            }
            op->unsatisfiedPreconditions--;
            if (op->unsatisfiedPreconditions == 0) {
                // add the effects of an operator to the stack if and only if the operator wasn't added to the cut
                bool addedToCut = false;
                foreach(Variable *effect, op->effects) {
                    // add op to cut if it contains an effect that is in the goal zone
                    if (goalZone.contains(effect)){
                        cut->push_back(op);
                        addedToCut = true;
                        break;
                    }
                }
                if (!addedToCut) {
                    foreach(Variable *effect, op->effects) {
                        reachedStack.push(effect);
                    }
                }
            }
        }
    }
}
