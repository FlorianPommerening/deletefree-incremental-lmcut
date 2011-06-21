#ifndef SEARCHNODE_H_
#define SEARCHNODE_H_

#include <map>
#include <list>

#include "Landmark.h"
#include "RelaxedTask.h"

class SearchNode {
public:
    SearchNode(RelaxedTask &task);
    SearchNode(const SearchNode &other);
    SearchNode& operator=(const SearchNode &rhs);

    SearchNode& applyOperator(RelaxedOperator *appliedOp);
    SearchNode& forbidOperator(RelaxedOperator *forbiddenOp);
    UIntEx getCostLowerBound() {
        return this->heuristicValue + this->currentCost;
    };

    UIntEx heuristicValue;
    unsigned int currentCost;
    VariableSet currentState;
    std::list<RelaxedOperator *> partialPlan;
    // has to be a list so pointers stay valid
    std::list<Landmark> landmarks;
    OperatorCosts operatorCost;
    RelaxedTask *task;

private:
    void applyOperatorWithoutUpdate(RelaxedOperator *appliedOp);
    void updateHeuristicValue();
    void unitPropagation();
    std::map<RelaxedOperator *, Landmark *> operatorToLandmark;
    std::list<Landmark *> singleOperatorLandmarks;
};

#endif /* SEARCHNODE_H_ */
