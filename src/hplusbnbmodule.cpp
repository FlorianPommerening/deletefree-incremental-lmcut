#include <boost/python/module.hpp>
#include <boost/python/def.hpp>
#include <boost/python/class.hpp>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>
#include <string>

#include "RelaxedTask.h"
#include "hmax.h"

using namespace std;

class AdapterOperator;

// allows exported interface of C++ to python module without changing the C++ program
class AdapterTask {
public:
    string init;
    string goal;
    vector<string> variables;
    vector<AdapterOperator> operators;

    RelaxedTask toRelaxedTask();
};

struct AdapterOperator {
public:
    string name;
    int cost;
    vector<string> preconditions;
    vector<string> effects;
    bool operator==(AdapterOperator const& other) const {
        return this->name == other.name &&
               this->cost == other.cost &&
               this->preconditions == other.preconditions &&
               this->effects == other.effects;
    }
    bool operator!=(AdapterOperator const& other) const { return !(*this == other); }
};


RelaxedTask AdapterTask::toRelaxedTask() {
    RelaxedTask task;
    for (unsigned int i = 0; i < this->variables.size(); ++i) {
        task.variables.push_back(Variable(this->variables[i]));
    }
    task.init = task.getVariable(this->init);
    task.goal = task.getVariable(this->goal);
    for (unsigned int i = 0; i < this->operators.size(); ++i) {
        RelaxedOperator op = RelaxedOperator();
        op.name = this->operators[i].name;
        op.cost = this->operators[i].cost;
        for (unsigned int p = 0; p < this->operators[i].preconditions.size(); ++p) {
            op.preconditions.add(task.getVariable(this->operators[i].preconditions[p]));
        }
        for (unsigned int p = 0; p < this->operators[i].effects.size(); ++p) {
            op.effects.add(task.getVariable(this->operators[i].effects[p]));
        }
        task.operators.push_back(op);
    }
    return task;
}

int calculate_hmax(AdapterTask aTask) {
    RelaxedTask task = aTask.toRelaxedTask();
    task.crossreference();
    return hmax(task);
}

BOOST_PYTHON_MODULE(hplusbnb) {
    using namespace boost::python;
    class_<vector<string> >("Variables")
                .def(vector_indexing_suite<vector<string> >());
    class_<AdapterOperator>("Operator")
                .def_readwrite("name", &AdapterOperator::name, "Name of the operator")
                .def_readwrite("cost", &AdapterOperator::cost, "Cost of the operator")
                .def_readwrite("preconditions", &AdapterOperator::preconditions, "Preconditions of the operator")
                .def_readwrite("effects", &AdapterOperator::effects, "Effects of the operator");
    class_<vector<AdapterOperator> >("Operators")
                .def(vector_indexing_suite<vector<AdapterOperator> >());
    class_<AdapterTask>("Task")
                .def_readwrite("init", &AdapterTask::init, "Initial state variable of the task")
                .def_readwrite("goal", &AdapterTask::goal, "Goal state variable of the task")
                .def_readwrite("variables", &AdapterTask::variables, "Variables of the task")
                .def_readwrite("operators", &AdapterTask::operators, "Operators of the task");
    def("hmax", calculate_hmax);
}
