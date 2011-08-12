#include "lm_cut_flo_heuristic.h"

#include "../globals.h"
#include "../operator.h"
#include "../option_parser.h"
#include "../plugin.h"
#include "../state.h"

#include "foreach.h"
#include "Landmark.h"
#include "lmcut.h"
#include "UIntEx.h"

#include <string>

#include <cassert>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;


static ScalarEvaluatorPlugin landmark_cut_flo_heuristic_plugin(
    "lmcutflo", LandmarkCutFloHeuristic::create);


// construction and destruction
LandmarkCutFloHeuristic::LandmarkCutFloHeuristic(const HeuristicOptions &options)
    : Heuristic(options) {
}

LandmarkCutFloHeuristic::~LandmarkCutFloHeuristic() {
    for (int var = 0; var < g_variable_domain.size(); var++) {
        for (int value = 0; value < g_variable_domain[var]; value++) {
            delete propositions[var][value];
        }
    }
    delete this->dummyPrecondition;
    delete this->relaxedTask.goal;
    for (int opId = 0; opId < g_operators.size(); opId++) {
        delete this->relaxedTask.operators[opId];
    }
}

// initialization
void LandmarkCutFloHeuristic::initialize() {
    cout << "Initializing landmark cut (flo) heuristic..." << endl;

    if (!g_axioms.empty()) {
        cerr << "error: LM-cut heuristic implementation does not "
             << "support axioms" << endl;
        ::exit(1);
    }


    propositions.resize(g_variable_domain.size());
    for (int var = 0; var < g_variable_domain.size(); var++) {
        for (int value = 0; value < g_variable_domain[var]; value++) {
            char buf[20];
            sprintf(buf, "var%d#%d", var, value);
            string varname = buf;
            Variable *newVar = new Variable(varname);
            this->relaxedTask.variables.push_back(newVar);
            propositions[var].push_back(newVar);
        }
    }

    // canonicalization (if @@precond is not needed it will be removed by the relevance analysis)
    this->dummyPrecondition = new Variable("@@precond");
    this->relaxedTask.variables.push_back(this->dummyPrecondition);
    this->relaxedTask.goal = new Variable("@@goal");
    this->relaxedTask.variables.push_back(this->relaxedTask.goal);

    // initial state is not used/needed as every call to calculate heuristic brings its own state
    // so we can leave out the init operator. This makes the delete relaxation unsolvable, when solved from initial state (which is never done)
    this->relaxedTask.init = NULL;
//    this->relaxedTask.variables.push_back(Variable("@@init"));
//    this->relaxedTask.init = &(this->relaxedTask.variables.back());
//    RelaxedOperator initOperator;
//    initOperator.name = "@@init-operator";
//    initOperator.baseCost = 0;
//    initOperator.preconditions.add(this->relaxedTask.init);
//    for (int i = 0; i < g_init.size(); i++) {
//        int var = g_init[i].first, val = g_init[i].second;
//        Variable *initVar = propositions[var][val];
//        initOperator.effects.add(initVar);
//    }
//    initOperator.effects.add(this->dummyPrecondition);
//    this->relaxedTask.operators.push_back(initOperator);

    RelaxedOperator *goalOperator = new RelaxedOperator();
    goalOperator->name = "@@goal-operator";
    goalOperator->baseCost = 0;
    for (int i = 0; i < g_goal.size(); i++) {
        int var = g_goal[i].first, val = g_goal[i].second;
        Variable *goalVar = propositions[var][val];
        goalOperator->preconditions.add(goalVar);
    }
    goalOperator->effects.add(this->relaxedTask.goal);
    this->relaxedTask.operators.push_back(goalOperator);

    // Build relaxed operators for operators and axioms.
    for (int opId = 0; opId < g_operators.size(); opId++) {
        const Operator &op  = g_operators[opId];
        const vector<Prevail> &prevail = op.get_prevail();
        const vector<PrePost> &pre_post = op.get_pre_post();
        RelaxedOperator *relaxedOp = new RelaxedOperator();
        relaxedOp->baseCost = get_adjusted_cost(op);
        relaxedOp->name = op.get_name();

        for (int i = 0; i < prevail.size(); i++) {
            relaxedOp->preconditions.add(propositions[prevail[i].var][prevail[i].prev]);
        }

        for (int i = 0; i < pre_post.size(); i++) {
            const vector<Prevail> &cond = pre_post[i].cond;
            if (!cond.empty()) {
                // Accept conditions that are redundant, but nothing else.
                // In a better world, these would never be included in the
                // input in the first place.
                int var = pre_post[i].var;
                int post = pre_post[i].post;
                if (cond.size() != 1 || cond[0].var != var ||
                    g_variable_domain[var] != 2 || cond[0].prev == post) {
                    cerr << "Heuristic does not support conditional effects "
                         << "(operator " << op.get_name() << ")"
                         << endl << "Terminating." << endl;
                    exit(1);
                }
            }

            if (pre_post[i].pre != -1) {
                relaxedOp->preconditions.add(propositions[pre_post[i].var][pre_post[i].pre]);
            }
            relaxedOp->effects.add(propositions[pre_post[i].var][pre_post[i].post]);
        }

        if (relaxedOp->preconditions.size() == 0) {
            relaxedOp->preconditions.add(this->dummyPrecondition);
        }
        this->relaxedTask.operators.push_back(relaxedOp);
        this->operatorCosts[relaxedOp] = relaxedOp->baseCost;
    }
    this->relaxedTask.crossreference();
}

int LandmarkCutFloHeuristic::compute_heuristic(const State &state) {
    // need to copy this, so LM-cut can change the values
    OperatorCosts operatorCostCopy = this->operatorCosts;
    vector<Landmark> landmarks;
    VariableSet convertedState;
    for (int var = 0; var < propositions.size(); var++) {
        Variable *relaxedVar = propositions[var][state[var]];
        convertedState.add(relaxedVar);
    }
    convertedState.add(this->dummyPrecondition);
    UIntEx heuristic = lmCut(this->relaxedTask, convertedState, operatorCostCopy, landmarks);
    for (int i= 0; i < landmarks.size(); ++i) {
        delete landmarks[i];
    }
    unsigned int heuristicValue;
    if (!heuristic.hasFiniteValue(heuristicValue)) {
        return DEAD_END;
    }
    return heuristicValue;
}

ScalarEvaluator *LandmarkCutFloHeuristic::create(const std::vector<string> &config,
                                                 int start, int &end,
                                                 bool dry_run) {
    HeuristicOptions common_options;

    if (config.size() <= start) {
        throw ParseError(start);
    }

    // "<name>()" or "<name>(<options>)"
    if (config.size() > start + 2 && config[start + 1] == "(") {
        end = start + 2;

        if (config[end] != ")") {
            NamedOptionParser option_parser;
            common_options.add_option_to_parser(option_parser);
            option_parser.parse_options(config, end, end, dry_run);
            end++;
        }
        if (config[end] != ")") {
            throw ParseError(end);
        }
    } else {
        throw ParseError(start + 1);
    }

    if (dry_run) {
        return 0;
    } else {
        return new LandmarkCutFloHeuristic(common_options);
    }
}

