#include <iostream>
#include <vector>
#include <ostream>
#include <sstream>
#include <boost/filesystem.hpp>

#include "Variable.h"
#include "RelaxedOperator.h"
#include "RelaxedTask.h"
#include "hmax.h"
#include "SASTask.h"

using namespace std;
using namespace boost::filesystem;

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
    // check if cached translations already exist
    if (!exists(taskTranslationPath) || !exists(translationKeyPath)) {
        // call python translate.py to translate file
        string command = TRANSLATE_CMD + " " + problemFilename + " " + domainFilename + " " + translationPath.string();
        if (system(command.c_str()) != 0) {
            cout << "Error while translating the problem into SAS." << endl;
            return 1;
        }
        if (!exists(taskTranslationPath) || !exists(translationKeyPath)) {
            cout << "Translating the problem into SAS did not produce the expected output files." << endl;
            return 1;
        }
    }

    SASTask sasTask;
    SASParser parser;
    bool parseOK = parser.parseTask(taskTranslationPath.string(), translationKeyPath.string(), sasTask);
    if (!parseOK) {
        cout << parser.getLastError() << endl;
        return 1;
    }
    cout << "parse ok" << endl;

    RelaxedTask translatedTask;
    DeleteRelaxer relaxer;
    bool relaxationOK = relaxer.deleteRelaxation(sasTask, translatedTask);
    if (!relaxationOK) {
        cout << relaxer.getLastError() << endl;
        return 1;
    }
    cout << "relax ok" << endl;
    if (!translatedTask.removeIrrelevantVariables()) {
        cout << "Unsolvable task." << endl;
        return 1;
    }
    cout << hmax(translatedTask) << endl;



    RelaxedTask parsedTask;
    try {
        parsedTask.parseFile("test.task");
    } catch (const char *e) {
        cout << e << endl;
        return 1;
    }

    parsedTask.crossreference();
    cout << hmax(parsedTask) << endl;

    cout << "done" << endl;
    return 0;
}
