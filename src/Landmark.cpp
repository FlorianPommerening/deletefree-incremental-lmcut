#include "Landmark.h"
#include "foreach.h"

#include <limits.h>

using namespace std;

void Landmark::add(RelaxedOperator *op, int opCost) {
    if (this->operatorEntries.size() == 0 || opCost < this->cost) {
        this->cost = opCost;
    }
    this->operatorEntries[op] = opCost;
}

void Landmark::remove(RelaxedOperator *op) {
    iterator it = this->operatorEntries.find(op);
    if (it != this->operatorEntries.end()) {
        int removedOpCost = it->second;
        this->operatorEntries.erase(it);
        //recalculate cost if necessary
        if (this->cost == removedOpCost) {
            int minCost = INT_MAX;
            foreach(Landmark::value_type &entry, this->operatorEntries) {
                int opCost = entry.second;
                if (opCost < minCost) {
                    minCost = opCost;
                }
            }
            this->cost = minCost;
        }
    }
}
