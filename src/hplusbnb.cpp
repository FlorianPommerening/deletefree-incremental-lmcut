#include <iostream>
#include <iomanip>
#include <vector>
#include <ostream>
#include <sstream>
#include <boost/filesystem.hpp>
#include <boost/lexical_cast.hpp>

#include "Variable.h"
#include "RelaxedOperator.h"
#include "RelaxedTask.h"
#include "hmax.h"
#include "lmcut.h"
#include "SASTask.h"
#include "foreach.h"
#include "Timer.h"
#include "BranchAndBoundSearch.h"

using namespace std;
using namespace boost::filesystem;

// needed for boost_foreach
typedef map<string, string> Results;

const string RESULTS_DIR = "../../results/";
const string TRANSLATIONS_DIR = "../../translations/";
const string TRANSLATE_CMD = "../translate/translate.py";

int main(int argc, char *argv[]) {
    // reserve some backup memory to write out error message, if program runs out of memory
    int *pbackupMemory = new int [100];
    if (argc > 3) {
        cout << "Only 2 arguments expected: problemfile, domainfile" << endl;
        return 1;
    }
    if (argc == 2) {
        cout << "Infering the domain name is not implemented yet" << endl;
        return 1;
    }
    string problemFilename = argv[1];
    string domainFilename = argv[2];
    string problemName = basename(problemFilename);
    string domainName = path(domainFilename).parent_path().leaf();
    path translationPath = path(TRANSLATIONS_DIR) / domainName / problemName;
    path taskTranslationPath = translationPath / "output.sas";
    path translationKeyPath = translationPath / "test.groups";
    path resultsFilePath = path(RESULTS_DIR) / (domainName + "_" + problemName + ".result");

    Results results;
    Timer cpuTimer(CPU_TIME);
    Timer wallClockTimer(WALLCLOCK_TIME);
    cout.setf(ios::fixed, ios::floatfield);
    cout.setf(ios::showpoint);
    cout << setprecision(3);

    try {
        cout << "Translating problem file ... " << flush;
        // check if cached translations already exist
        if (!exists(taskTranslationPath) || !exists(translationKeyPath)) {
            // call python translate.py to translate file
            string command = TRANSLATE_CMD + " " + problemFilename + " " + domainFilename + " " + translationPath.string();
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

        cout << "Removing irrelevant variables ... " << flush;
        cpuTimer.restart();
        bool solvable = translatedTask.removeIrrelevantVariables();
        results["relevance_analysis_time"] = boost::lexical_cast<string>(cpuTimer.elapsed());
        cout << "done " << results["relevance_analysis_time"] << endl;

        if (solvable) {
    /*
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
    */
            cout << "Calculating h^+ ... " << flush;
            cpuTimer.restart();
            AchieveLandmarksOperatorSelector opSelector;
            BranchAndBoundSearch search = BranchAndBoundSearch(translatedTask, opSelector);
            UIntEx h_plus_value = search.run();
            results["h_plus_time"] = boost::lexical_cast<string>(cpuTimer.elapsed());
            results["h_plus"] = h_plus_value.toString();
            cout << "done (" << h_plus_value << ") " << results["h_plus_time"] << endl;
        } else {
            cout << "Unsolvable task." << endl;
            results["h_max_time"] = "0";
            results["h_max"] = "inf";
            results["h_lmcut_time"] = "0";
            results["h_lmcut"] = "inf";
            results["h_plus_time"] = "0";
            results["h_plus"] = "inf";
        }
    } catch (bad_alloc e) {
        delete [] pbackupMemory; pbackupMemory = NULL;
        cout << "Out of Memory" << endl;
        results["error"] = " Out of memory";
        // do not return: freed backup memory should be enough to write out result file
    } catch (exception e) {
        printf("%s", e.what());
        return 1;
    } catch (...) {
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

    delete [] pbackupMemory;
    return 0;
}
