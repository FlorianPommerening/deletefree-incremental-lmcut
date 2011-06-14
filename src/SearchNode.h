#ifndef SEARCHNODE_H_
#define SEARCHNODE_H_

#include <map>
#include <vector>

#include "Landmark.h"
#include "RelaxedTask.h"

class SearchNode {
public:
    SearchNode(RelaxedTask &task);
    SearchNode(const SearchNode &other);
    SearchNode& operator=(const SearchNode &rhs);

    SearchNode& initialNode();
    SearchNode& ApplyOperator(RelaxedOperator *appliedOp);
    SearchNode& ForbidOperator(RelaxedOperator *forbiddenOp);
    int heuristicValue;

    // TODO
    int currentCost;
    int costLowerBound;
    VariableSet currentState;
    std::vector<RelaxedOperator *> partialPlan;


private:
    void updateHeuristicValue();
    RelaxedTask *task;
    // has to be a list so pointers stay valid
    std::list<Landmark> landmarks;
    OperatorCosts operatorCost;
    std::map<RelaxedOperator *, Landmark *> operatorToLandmark;
};

#endif /* SEARCHNODE_H_ */
