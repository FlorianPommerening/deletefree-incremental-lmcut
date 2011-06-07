#include <iostream>
#include <iomanip>
#include <vector>
#include <ostream>
#include <sstream>
#include <boost/filesystem.hpp>

#include "Variable.h"
#include "RelaxedOperator.h"
#include "RelaxedTask.h"
#include "hmax.h"
#include "SASTask.h"
#include "foreach.h"
#include "Timer.h"

using namespace std;
using namespace boost::filesystem;

// needed for boost_foreach
typedef map<string, float> TimerResults;

const string RESULTS_DIR = "../../results/";
const string TRANSLATIONS_DIR = "../../translations/";
const string TRANSLATE_CMD = "../translate/translate.py";

int main(int argc, char *argv[]) {
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
    path translationPath = path(TRANSLATIONS_DIR + domainName + '/' + problemName);
    path taskTranslationPath = translationPath / "output.sas";
    path translationKeyPath = translationPath / "test.groups";

    TimerResults times;
    Timer cpuTimer(CPU_TIME);
    Timer wallClockTimer(WALLCLOCK_TIME);

    // check if cached translations already exist
    if (!exists(taskTranslationPath) || !exists(translationKeyPath)) {
        // call python translate.py to translate file
        string command = TRANSLATE_CMD + " " + problemFilename + " " + domainFilename + " " + translationPath.string();
        wallClockTimer.restart();
        if (system(command.c_str()) != 0) {
            cout << "Error while translating the problem into SAS." << endl;
            return 1;
        }
        times["translation"] = wallClockTimer.elapsed();
        if (!exists(taskTranslationPath) || !exists(translationKeyPath)) {
            cout << "Translating the problem into SAS did not produce the expected output files." << endl;
            return 1;
        }
    }

    SASTask sasTask;
    SASParser parser;
    cpuTimer.restart();
    bool parseOK = parser.parseTask(taskTranslationPath.string(), translationKeyPath.string(), sasTask);
    times["parse"] = cpuTimer.elapsed();
    if (!parseOK) {
        cout << parser.getLastError() << endl;
        return 1;
    }
    cout << "parse ok" << endl;

    RelaxedTask translatedTask;
    DeleteRelaxer relaxer;
    cpuTimer.restart();
    bool relaxationOK = relaxer.deleteRelaxation(sasTask, translatedTask);
    times["relaxation"] = cpuTimer.elapsed();
    if (!relaxationOK) {
        cout << relaxer.getLastError() << endl;
        return 1;
    }
    cout << "relax ok" << endl;
    cpuTimer.restart();
    if (!translatedTask.removeIrrelevantVariables()) {
        cout << "Unsolvable task." << endl;
        return 1;
    }
    times["relevance_analysis"] = cpuTimer.elapsed();

    cpuTimer.restart();
    cout << hmax(translatedTask) << endl;
    times["h_max"] = cpuTimer.elapsed();

    cout << endl << "Timing:" << endl;
    cout.setf(ios::fixed, ios::floatfield);
    cout.setf(ios::showpoint);
    cout << setprecision(3);
    foreach(const TimerResults::value_type &timerPair, times){
        cout << timerPair.first << "= " << timerPair.second << endl;
    }

    return 0;
}
