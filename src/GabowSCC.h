#ifndef GABOWSCC_H
#define GABOWSCC_H

/*
 * Cheriyan–Mehlhorn/Gabow algorithm
 * see http://en.wikipedia.org/wiki/Cheriyan%E2%80%93Mehlhorn/Gabow_algorithm
 * Uses temporary field ("closed") in Variable class.
 */

#include "Variable.h"
#include "RelaxedOperator.h"
#include "PointerMap.h"

#include <list>


class GabowSCC {
public:
    // Singleton
    static GabowSCC& Instance() {
      static GabowSCC instance;
      return instance;
    }

    void findSourceConnectedComponents(std::vector<Variable *> &variables, OperatorCosts &operatorCosts);
    int getComponent(Variable *v) {
        return this->componentId[v];
    }
    bool isInSourceComponent(Variable *v) {
        return this->inSourceComponent[v];
    }
private:
    GabowSCC() {}
    GabowSCC(GabowSCC const&);       // Don't Implement! Singleton shouldn't be copied
    void operator=(GabowSCC const&); // Don't implement! Singleton shouldn't be copied

    PointerMap<Variable, int> preorder;
    PointerMap<Variable, int> componentId;
    PointerMap<Variable, bool> inSourceComponent;
    int pre;
    int count;
    // should be stacks but those have no clear() and no peek()
    std::list<Variable *> notYetAssigned;
    std::list<Variable *> maybeDifferent;
    void findConnectedComponents(std::vector<Variable *> &variables, OperatorCosts &operatorCosts);
    void gabowDfs(Variable *v, OperatorCosts &operatorCosts);
};

#endif
