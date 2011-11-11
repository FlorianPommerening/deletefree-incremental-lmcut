#ifndef LM_CUT_HEURISTIC_H
#define LM_CUT_HEURISTIC_H

#include "../heuristic.h"

#include "RelaxedTask.h"
#include "RelaxedOperator.h"
#include "Variable.h"
#include "Landmark.h"

#include <vector>


class Operator;
class State;

class LandmarkCutFloHeuristic : public Heuristic {
    RelaxedTask relaxedTask;
    UnitCostLandmarkCollection *landmarkCollection;
    Variable *dummyPrecondition;
    OperatorCosts operatorCosts;
    std::vector<std::vector<Variable *> > propositions;

    virtual void initialize();
    virtual int compute_heuristic(const State &state);
public:
    LandmarkCutFloHeuristic(const Options &options);
    virtual ~LandmarkCutFloHeuristic();
    static ScalarEvaluator *create(const std::vector<std::string> &config,
                                   int start, int &end, bool dry_run);
};

#endif
