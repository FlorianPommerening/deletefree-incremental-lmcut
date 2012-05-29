#include <iostream>
#include <iomanip>
#include <vector>
#include <ostream>
#include <sstream>
#include <map>
#include <boost/version.hpp>
#include <boost/filesystem.hpp>
#include <boost/lexical_cast.hpp>
#include <stdlib.h>
#include <time.h>

#include "Options.h"
#include "Variable.h"
#include "RelaxedOperator.h"
#include "RelaxedTask.h"
#include "hmax.h"
#include "lmcut.h"
#include "SASTask.h"
#include "foreach.h"
#include "Timer.h"
#include "BranchAndBoundSearch.h"
#include "IDAStarSearch.h"

using namespace std;
using namespace boost::filesystem;

// needed for boost_foreach
typedef map<string, string> Results;

// TODO: stop hard coding directory names
const string OPTIONS_FILE = "options";

template<class SearchClass, class OperatorSelectorClass>
SearchClass runSearch(RelaxedTask &task, Results &results, OptimizationOptions &options);

int main(int argc, char *argv[]) {
    // Parse command line arguments.
    if (argc > 4) {
        cout << "Only 2 arguments expected: problemfile domainfile [out_file]" << endl;
        return 1;
    }
    if (argc == 2) {
        cout << "Infering the domain name is not implemented yet" << endl;
        return 1;
    }
    string problemFilename = argv[1];
    string domainFilename = argv[2];
    string problemName = basename(problemFilename);

#if BOOST_VERSION < 104400 || BOOST_FILESYSTEM_VERSION == 2
    string domainName = path(domainFilename).parent_path().leaf();
#else
    string domainName = path(domainFilename).parent_path().leaf().string();
#endif
    // TODO use command line options to set options or at least use them to point to the options file
    OptimizationOptions options = OptimizationOptions(OPTIONS_FILE);
    path translationPath = path(options.translationsCacheDirectory) / domainName / problemName;
    path taskTranslationPath = translationPath / "output.sas";
    path translationKeyPath = translationPath / "test.groups";
    path resultsFilePath = path(options.resultDirectory) / (domainName + "_" + problemName + ".result");
    if (argc == 4) {
        resultsFilePath = argv[3];
    }
    // do not use time(NULL) here, to avoid getting the same seeds on the grid
    srand (options.randomSeed);
    cout << "Random seed: " << options.randomSeed << endl << flush;

    // results will contain all properties recorded in the result file
    Results results;
    results["random_seed"] = boost::lexical_cast<string>(options.randomSeed);
    Timer cpuTimer(CPU_TIME);
    Timer wallClockTimer(WALLCLOCK_TIME);
    cout.setf(ios::fixed, ios::floatfield);
    cout.setf(ios::showpoint);
    cout << setprecision(3);

    try {
        // Translation from pddl to sas
        cout << "Translating problem file ... " << flush;
        // check if cached translations already exist
        if (!exists(taskTranslationPath) || !exists(translationKeyPath)) {
            // call python translate-relaxed.py to translate file
            string command = options.translateRelaxedCommand + " " + problemFilename + " " + domainFilename + " " + translationPath.string();
            wallClockTimer.restart();
            if (system(command.c_str()) != 0) {
                cout << "Error while translating the problem into SAS." << endl;
                return 1;
            }
            results["translation_time"] = boost::lexical_cast<string>(wallClockTimer.elapsed());
            cout << "done " << results["translation_time"] << endl;
            if (!exists(taskTranslationPath) || !exists(translationKeyPath)) {
                cout << "Translating the problem into SAS did not produce the expected output files." << endl;
                return 1;
            }
        } else {
            cout << "translation already exists" << endl;
        }

        // Parsing the sas translation into a SASTask
        cout << "Parsing translated file ... " << flush;
        SASTask sasTask;
        SASParser parser;
        cpuTimer.restart();
        bool parseOK = parser.parseTask(taskTranslationPath.string(), translationKeyPath.string(), sasTask);
        results["parse_time"] = boost::lexical_cast<string>(cpuTimer.elapsed());
        if (!parseOK) {
            cout << endl << parser.getLastError() << endl;
            return 1;
        }
        cout << "done " << results["parse_time"] << endl;

        // Generating the delete relaxation of the SASTask
        cout << "Relaxing task ... " << flush;
        RelaxedTask translatedTask;
        DeleteRelaxer relaxer;
        cpuTimer.restart();
        bool relaxationOK = relaxer.deleteRelaxation(sasTask, translatedTask);
        results["relaxation_time"] = boost::lexical_cast<string>(cpuTimer.elapsed());
        if (!relaxationOK) {
            cout << relaxer.getLastError() << endl;
            return 1;
        }
        cout << "done " << results["relaxation_time"] << endl;

        // Relevance analysis
        int oldVariableCount = translatedTask.variables.size();
        int oldOperatorCount = translatedTask.operators.size();
        vector<pair<pair<string, float>, pair<int, int> > > filteredElements;
        cout << "Removing irrelevant variables ... " << flush;
        cpuTimer.restart();
        // if the task is trivially unsolvable, this can be discovered here
        bool solvable = translatedTask.removeUnnecessaryParts(filteredElements);
        results["relevance_analysis_time"] = boost::lexical_cast<string>(cpuTimer.elapsed());
        typedef pair<pair<string, float>, pair<int, int> > ElementType;
        int i = 0;
        foreach (ElementType e, filteredElements) {
            i++;
            results["filter_" + boost::lexical_cast<string>(i) + "_name"] = e.first.first;
            results["filter_" + boost::lexical_cast<string>(i) + "_time"] = boost::lexical_cast<string>(e.first.second);
            results["filter_" + boost::lexical_cast<string>(i) + "_filtered_variables"] = boost::lexical_cast<string>(e.second.first);
            results["filter_" + boost::lexical_cast<string>(i) + "_filtered_operators"] = boost::lexical_cast<string>(e.second.second);
        }
        cout << "done " << results["relevance_analysis_time"] << endl;
        cout << "  Removed " << oldVariableCount - translatedTask.variables.size() << " of " << oldVariableCount <<
                " variables (" << translatedTask.variables.size() << " variables left)" << endl;
        cout << "  Removed " << oldOperatorCount - translatedTask.operators.size() << " of " << oldOperatorCount <<
                " operators (" << translatedTask.operators.size() << " operators left)" << endl;
        results["variable_count_original"] = boost::lexical_cast<string>(oldVariableCount);
        results["operator_count_original"] = boost::lexical_cast<string>(oldOperatorCount);
        results["variable_count_relevant"] = boost::lexical_cast<string>(translatedTask.variables.size());
        results["operator_count_relevant"] = boost::lexical_cast<string>(translatedTask.operators.size());

        /*
        // calculate some statistics on the inital node
        if (solvable) {
            // Previous tests to compute h^max and h^LM-cut values used to validate their implementations.
            cout << "Calculating h^max ... " << flush;
            cpuTimer.restart();
            UIntEx hmax_value = hmax(translatedTask);
            results["h_max_time"] = boost::lexical_cast<string>(cpuTimer.elapsed());
            results["h_max"] = hmax_value.toString();
            cout << "done (" << hmax_value << ") " << results["h_max_time"] << endl;

            cout << "Calculating h^lmcut ... " << flush;
            cpuTimer.restart();
            UIntEx h_lmcut_value = lmCut(translatedTask);
            results["h_lmcut_time"] = boost::lexical_cast<string>(cpuTimer.elapsed());
            results["h_lmcut"] = h_lmcut_value.toString();
            cout << "done (" << h_lmcut_value << ") " << results["h_lmcut_time"] << endl;

            SearchNode initialNode = SearchNode(translatedTask, options);
            results["landmarks_count"] = boost::lexical_cast<string>(initialNode.landmarks.size());
            results["unit_landmarks_count"] = boost::lexical_cast<string>(initialNode.getSingleOperatorLandmarks().size());
            int maxSize = 0;
            foreach(Landmark &landmark, initialNode.landmarks) {
                if (landmark.size() > maxSize) {
                    maxSize = landmark.size();
                }
            }
            results["landmarks_max_size"] = boost::lexical_cast<string>(maxSize);

            // find effect landmarks in some primitive way
            foreach(Variable *v, translatedTask.variables) {
                v->closed = false;
            }
            vector<Variable *> effectLandmarks;
            effectLandmarks.reserve(translatedTask.variables.size());
            stack<Variable *> effectLandmarkStack;
            effectLandmarkStack.push(translatedTask.goal);
            effectLandmarkStack.push(translatedTask.init);
            foreach(Landmark &landmark, initialNode.landmarks) {
                RelaxedOperator *firstOp = landmark.begin()->first;
                Effects effectLandmark = firstOp->effects;
                Preconditions preconditionLandmark = firstOp->preconditions;
                foreach(Landmark::value_type &entry, landmark) {
                    RelaxedOperator *op = entry.first;
                    effectLandmark.inplaceIntersection(op->effects);
                    preconditionLandmark.inplaceIntersection(op->preconditions);
                }
                foreach(Variable *v, effectLandmark) {
                    effectLandmarkStack.push(v);
                }
                foreach(Variable *v, preconditionLandmark) {
                    effectLandmarkStack.push(v);
                }
            }
            while (!effectLandmarkStack.empty()) {
                Variable *v = effectLandmarkStack.top();
                effectLandmarkStack.pop();
                if (v->closed) {
                    continue;
                }
                v->closed = true;
                effectLandmarks.push_back(v);
                if (v->effect_of.size() == 0) {
                    continue;
                }
                RelaxedOperator *firstOp = *(v->effect_of.begin());
                Effects effectLandmark = firstOp->effects;
                Preconditions preconditionLandmark = firstOp->preconditions;
                foreach(RelaxedOperator *op, v->effect_of) {
                    effectLandmark.inplaceIntersection(op->effects);
                    preconditionLandmark.inplaceIntersection(op->preconditions);
                }
                foreach(Variable *v, effectLandmark) {
                    effectLandmarkStack.push(v);
                }
                foreach(Variable *v, preconditionLandmark) {
                    effectLandmarkStack.push(v);
                }
            }
            ostringstream effectLandmarkString;
            foreach(Variable *v, effectLandmarks) {
                effectLandmarkString << v->name << ", ";
            }

            results["effect_landmarks_count"] = boost::lexical_cast<string>(effectLandmarks.size());
            results["effect_landmarks"] = effectLandmarkString.str();
            results["variables_count"] = boost::lexical_cast<string>(translatedTask.variables.size());

            cout << "Calculating h^+ until first solution... " << endl << flush;
            AchieveLandmarksTryGoalOperatorSelector opSelector(options);
            BranchAndBoundSearch search = BranchAndBoundSearch(translatedTask, opSelector, options);
            search.run();
            results["h_plus_upper_bound"] = search.getCostUpperBound().toString();

        } else
        /**/

        if (solvable) {
            if (options.idaStarSearch) {
                IDAStarSearch search = runSearch<IDAStarSearch, AchieveLandmarksTryGoalOperatorSelector>(translatedTask, results, options);
                results["bnb_expansions_last_layer"] = boost::lexical_cast<string>(search.getExpansionCountLastLayer());
                results["bnb_expansions_second_to_last_layer"] = boost::lexical_cast<string>(search.getExpansionCountSecondToLastLayer());
                results["bnb_time_last_layer"] = boost::lexical_cast<string>(search.getTimeLastLayer());
                results["bnb_time_second_to_last_layer"] = boost::lexical_cast<string>(search.getTimeSecondToLastLayer());
            } else {
                BranchAndBoundSearch search = runSearch<BranchAndBoundSearch, AchieveLandmarksTryGoalOperatorSelector>(translatedTask, results, options);
                if (options.initialUpperBound) {
                    if (search.getInitialPlanCost() != 0) {
                        results["initial_plan_cost"] = boost::lexical_cast<string>(search.getInitialPlanCost());
                        results["initial_plan_time"] = boost::lexical_cast<string>(search.getInitialPlanTime());
                    }
                    if (search.getOptimizedInitialPlanCost() != 0) {
                        results["optimized_initial_plan_cost"] = boost::lexical_cast<string>(search.getOptimizedInitialPlanCost());
                        results["optimized_initial_plan_time"] = boost::lexical_cast<string>(search.getOptimizedInitialPlanTime());
                    }
                }
            }
        } else {
            cout << "Unsolvable task." << endl;
            results["h_max_time"] = "0";
            results["h_max"] = "inf";
            results["h_lmcut_time"] = "0";
            results["h_lmcut"] = "inf";
            results["h_plus_time"] = "0";
            results["h_plus"] = "inf";
        }
    } catch (bad_alloc &ex) {
        cout << "Out of memory" << endl;
        results["error"] = "Out of memory";
        // do not return: write out results to get OutOfMemory in result file
    } catch (exception &ex) {
        cout << "Caught exception: " << ex.what();
        return 1;
    } catch (...) {
        cout << "Caught unknown exception";
        return 1;
    }

    cout << "Writing results ... " << flush;
    ofstream resultsFile(resultsFilePath.string().c_str());
    resultsFile << "domain: " << domainName << endl;
    resultsFile << "problem: " << problemName << endl;
    foreach(const Results::value_type &resultsPair, results){
        resultsFile << resultsPair.first << " " << resultsPair.second << endl;
    }
    resultsFile.close();
    cout << "done" << endl;

    return 0;
}

template<class SearchClass, class OperatorSelectorClass>
SearchClass runSearch(RelaxedTask &task, Results &results, OptimizationOptions &options) {
    Timer cpuTimer(CPU_TIME);
    cout << "Calculating h^+ ... " << endl << flush;
    cpuTimer.restart();
    OperatorSelectorClass opSelector = OperatorSelectorClass(options);
    SearchClass search = SearchClass(task, opSelector, options);
    UIntEx h_plus_value = search.run();
    if (options.expansionLimit != 0 && search.getExpansionCount() >= options.expansionLimit) {
        results["error"] = "Exceeded expansion limit of " + boost::lexical_cast<string>(options.expansionLimit);
        results["h_plus_guess_time"] = boost::lexical_cast<string>(cpuTimer.elapsed());
        results["h_plus_guess"] = h_plus_value.toString();
        results["bnb_expansions"] = boost::lexical_cast<string>(search.getExpansionCount());
        results["bnb_unit_propagations"] = boost::lexical_cast<string>(search.getUnitPropagationCount());
        cout << "exceeded expansion bound (" << options.expansionLimit << ") " << results["bnb_unit_propagations"] << " unit propagations " << results["h_plus_guess_time"] << endl;
    } else {
        results["h_plus_time"] = boost::lexical_cast<string>(cpuTimer.elapsed());
        results["h_plus"] = h_plus_value.toString();
        results["bnb_expansions"] = boost::lexical_cast<string>(search.getExpansionCount());
        results["bnb_unit_propagations"] = boost::lexical_cast<string>(search.getUnitPropagationCount());
        ostringstream planstring;
        foreach(const RelaxedOperator *op, search.getPlan()) {
            planstring << op->name << ", ";
        }
        results["plan"] = planstring.str();
        cout << "done (" << h_plus_value << ") " << results["bnb_expansions"] << " expansions " << results["bnb_unit_propagations"] << " unit propagations " << results["h_plus_time"] << endl;
        cout << "    With plan: " << results["plan"] << endl;
    }
    return search;
}

