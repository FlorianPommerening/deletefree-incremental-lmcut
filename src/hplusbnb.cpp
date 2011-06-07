#include <iostream>
#include <vector>
#include <ostream>
#include <sstream>

#include "Variable.h"
#include "RelaxedOperator.h"
#include "RelaxedTask.h"
#include "hmax.h"
#include "SASTask.h"

using namespace std;

void intToString(int i, string& res) {
    ostringstream temp;
    temp << i;
    temp.str(res);
}

int main() {
    // call python translate.py to translate file. Pass last two arguments to translator

    SASTask sasTask;
    SASParser parser;
    bool parseOK = parser.parseTask("../output.sas", "../test.groups", sasTask);
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
