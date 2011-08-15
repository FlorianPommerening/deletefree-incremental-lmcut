#ifndef GABOWSCC_H
#define GABOWSCC_H

/*
 * Cheriyan–Mehlhorn/Gabow algorithm
 * see http://en.wikipedia.org/wiki/Cheriyan%E2%80%93Mehlhorn/Gabow_algorithm
 * Uses temporary field ("closed") in Variable class.
 */

#include "Variable.h"
#include "RelaxedOperator.h"


class GabowSCC {
public:
    // Singleton
    static GabowSCC& Instance() {
      static GabowSCC instance;
      return instance;
    }

    void findSourceConnectedComponents(std::vector<Variable *> &variables, OperatorCosts &operatorCosts);
    int getComponent(Variable *v) {
        return this->componentId[v->id];
    }
    bool isInSourceComponent(Variable *v) {
        return this->inSourceComponent[v->id];
    }
private:
    GabowSCC(): pre(0), count(0) {}
    GabowSCC(GabowSCC const&);       // Don't Implement! Singleton shouldn't be copied
    void operator=(GabowSCC const&); // Don't implement! Singleton shouldn't be copied

    std::vector<int> preorder;
    std::vector<int> componentId;
    std::vector<bool> inSourceComponent;
    int pre;
    int count;
    // should be stacks but those have no clear()
    std::vector<Variable *> notYetAssigned;
    std::vector<Variable *> maybeDifferent;
    void findConnectedComponents(std::vector<Variable *> &variables, OperatorCosts &operatorCosts);
    void gabowDfs(Variable *v, OperatorCosts &operatorCosts);
};

#endif
