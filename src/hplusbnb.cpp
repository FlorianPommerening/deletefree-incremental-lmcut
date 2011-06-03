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
    SASTask sasTask;
    SASParser parser;
    bool parseOK = parser.parseTask("../output.sas", "../test.groups", sasTask);
    if (!parseOK) {
        cout << parser.getLastError() << endl;
        return 1;
    }
    cout << "parse ok" << endl;
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
