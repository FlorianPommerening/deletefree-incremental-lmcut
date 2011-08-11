#include "GabowSCC.h"

#include "foreach.h"

using namespace std;

void GabowSCC::findSourceConnectedComponents(vector<Variable *> &variables, OperatorCosts &operatorCosts) {
    this->inSourceComponent.clear();
    this->findConnectedComponents(variables, operatorCosts);
    // a variable is in a source component iff all its incoming edges come from the same component
    foreach(Variable *v, variables) {
        int componentId = this->componentId[v];
        bool inSourceComponent = true;
        foreach(RelaxedOperator *op, v->effect_of) {
            if (operatorCosts[op] == UIntEx::INF) {
                continue;
            }
            foreach(Variable *w, op->preconditions) {
                if (this->componentId[w] != componentId) {
                    inSourceComponent = false;
                    break;
                }
            }
            if (!inSourceComponent) {
                break;
            }
        }
        this->inSourceComponent[v] = inSourceComponent;
    }
}

void GabowSCC::findConnectedComponents(vector<Variable *> &variables, OperatorCosts &operatorCosts) {
    // reset everything
    this->componentId.clear();
    this->preorder.clear();
    this->maybeDifferent.clear();
    this->maybeDifferent.reserve(variables.size());
    this->notYetAssigned.clear();
    this->maybeDifferent.reserve(variables.size());
    this->pre = 0;
    this->count = 0;
    foreach(Variable *v, variables) {
        v->closed = false;
        this->componentId[v] = -1;
        this->preorder[v] = -1;
    }
    // Run DFS until all variables have been visited;
    // discovering all components on the way.
    foreach(Variable *v, variables) {
        if (!v->closed) {
            this->gabowDfs(v, operatorCosts);
        }
    }
}

void GabowSCC::gabowDfs(Variable *v, OperatorCosts &operatorCosts) {
    v->closed = true;
    this->preorder[v] = this->pre++;
    this->notYetAssigned.push_back(v);
    this->maybeDifferent.push_back(v);
    foreach(RelaxedOperator *op, v->precondition_of) {
        if (operatorCosts[op] == UIntEx::INF) {
            continue;
        }
        foreach(Variable *w, op->effects) {
            if (!w->closed) {
                gabowDfs(w, operatorCosts);
            }
            else if (this->componentId[w] == -1) {
                while (this->preorder[this->maybeDifferent.back()] > this->preorder[w]) {
                    this->maybeDifferent.pop_back();
                }
            }
        }
    }
    if (this->maybeDifferent.back() == v) {
        this->maybeDifferent.pop_back();
        Variable *w = NULL;
        do {
            w = this->notYetAssigned.back();
            this->notYetAssigned.pop_back();
            this->componentId[w] = this->count;
        } while (w != v);
        this->count++;
    }
}
