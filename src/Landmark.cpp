#include "Landmark.h"
#include "foreach.h"

using namespace std;

void Landmark::add(RelaxedOperator *op, int opCost) {
    if (opCost > this->cost) {
        this->cost = opCost;
    }
    this->operatorEntries[op] = opCost;
}

void Landmark::remove(RelaxedOperator *op) {
    map<RelaxedOperator *, int>::iterator it = this->operatorEntries.find(op);
    if (it != this->operatorEntries.end() && this->operatorEntries[op] == this->cost) {
        foreach(Landmark::value_type &entry, this->operatorEntries) {
            int opCost = entry.second;
            if (this->cost < opCost) {
                this->cost = opCost;
            }
        }
    }
    this->remove(op);
}
