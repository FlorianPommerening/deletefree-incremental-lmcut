#ifndef LANDMARK_H_
#define LANDMARK_H_

#include "RelaxedOperator.h"
#include <boost/iterator/iterator_facade.hpp>

typedef std::vector<RelaxedOperator *> Landmark;
typedef int LandmarkId;

class AbstractLandmarkCollection {
public:
    AbstractLandmarkCollection();
    AbstractLandmarkCollection(const AbstractLandmarkCollection &other);
    virtual ~AbstractLandmarkCollection();
    virtual void clear();
    /*
     * The landmark given as the parameter will be emptied by this function.
     * Returns a landmarkId for the newly added landmark.
     */
    LandmarkId addLandmark(Landmark &landmarkIn, OperatorCosts &operatorCosts);
    /*
     * Returns the landmarkIds of all landmarks containing op
     */
    virtual std::vector<LandmarkId> containingLandmarks(const RelaxedOperator *const op) const = 0;
    /*
     * lazy remove (will not update actual landmarks, unless they are removed)
     * Returns true if no landmark became empty by removing op
     * and false if op was the last operator in at least one landmark.
     */
    bool removeOperatorFromContainingLandmarks(RelaxedOperator *const op, OperatorCosts &operatorCosts);
    /*
     * lazy remove (will not update singleOperatorLandmarks)
     */
    void removeLandmark(const LandmarkId landmarkId);

    int getLandmarkSize(const LandmarkId landmarkId) const {
        return this->landmarkSizes[landmarkId];
    }

    UIntEx getCost() const {
        return cost;
    }

    UIntEx getLandmarkCost(const LandmarkId landmarkId) const {
        return this->landmarkCosts[landmarkId];
    }

    /*
     * this will ensure that the landmark with id landmarkId is up to date
     * and return it for iteration. Do not change the landmark or reuse the reference
     * as it will become invalid once the landmark is changed or removed
     */
    Landmark &iterateLandmark(LandmarkId landmarkId) const;
    /*
     * Returns the number of valid landmarks n and guarantees that these landmarks have the LandmarkIds 0 .. (n-1)
     */
    int getValidLandmarkIds() const;
    /*
     * This will ensure that the operators in singleOperatorLandmarks are still valid, and return the list
     */
    std::vector<RelaxedOperator*> &getSingleOperatorLandmarks() const;
protected:
    UIntEx cost;
    // making everything mutable kind of destroys the effect of const, but in this class
    // everything can be moved during iteration and the collection is still logically unchanged
    mutable std::vector<Landmark*> landmarks;
    mutable std::vector<int> landmarkSizes;
    mutable std::vector<UIntEx> landmarkCosts;
    mutable std::vector<int> dirty;
    mutable bool landmarksDirty;
    mutable std::vector<RelaxedOperator*> singleOperatorLandmarks;
    mutable bool singleOperatorLandmarksDirty;

    virtual int calculateLandmarkCost(const Landmark *landmark, const OperatorCosts& operatorCosts) const = 0;
    virtual void addOperatorToLandmarkMapping(const RelaxedOperator *op, const LandmarkId landmarkId) const = 0;
    virtual bool removeOperatorToLandmarkMapping(const RelaxedOperator *op, const LandmarkId landmarkId) const = 0;
    virtual bool hasOperatorToLandmarkMapping(const RelaxedOperator *op, const LandmarkId landmarkId) const = 0;
};


class ArbitraryCostLandmarkCollection: public AbstractLandmarkCollection {
public:
    ArbitraryCostLandmarkCollection(const std::vector<RelaxedOperator*> &operators);
    ArbitraryCostLandmarkCollection(const ArbitraryCostLandmarkCollection &other);
    virtual void clear();

    virtual std::vector<LandmarkId> containingLandmarks(const RelaxedOperator *const op) const{
        return this->operatorToLandmark[op->id];
    }
protected:
    mutable std::vector<std::vector<int> > operatorToLandmark;

    virtual void addOperatorToLandmarkMapping(const RelaxedOperator *op, const LandmarkId landmarkId) const {
        this->operatorToLandmark[op->id].push_back(landmarkId);
    }

    virtual bool removeOperatorToLandmarkMapping(const RelaxedOperator *op, const LandmarkId landmarkId) const {
        std::vector<LandmarkId> &containingLandmarks = this->operatorToLandmark[op->id];
        std::vector<LandmarkId>::iterator itNewEnd = std::remove(containingLandmarks.begin(), containingLandmarks.end(), landmarkId);
        if (itNewEnd == containingLandmarks.end()) {
            return false;
        } // else
        containingLandmarks.erase(itNewEnd, containingLandmarks.end());
        return true;
    }

    virtual bool hasOperatorToLandmarkMapping(const RelaxedOperator *op, const LandmarkId landmarkId) const {
        std::vector<LandmarkId> &containingLandmarks = this->operatorToLandmark[op->id];
        return (std::find(containingLandmarks.begin(), containingLandmarks.end(), landmarkId) != containingLandmarks.end());
    }

    virtual int calculateLandmarkCost(const Landmark *landmark, const OperatorCosts& operatorCosts) const {
        const RelaxedOperator *firstOp = (*landmark)[0];
        UIntEx landmarkCost = operatorCosts[firstOp->id];
        foreach(RelaxedOperator *op, *landmark) {
            if (landmarkCost > operatorCosts[op->id]) {
                landmarkCost = operatorCosts[op->id];
            }
        }
        unsigned int intValue = 0;
        landmarkCost.hasFiniteValue(intValue);
        return intValue;
    }
};


class BinaryCostLandmarkCollection: public AbstractLandmarkCollection {
public:
    BinaryCostLandmarkCollection(const std::vector<RelaxedOperator*> &operators);
    BinaryCostLandmarkCollection(const BinaryCostLandmarkCollection &other);
    virtual void clear();
    virtual std::vector<LandmarkId> containingLandmarks(const RelaxedOperator *const op) const ;
protected:
    mutable std::vector<int> operatorToLandmark;

    virtual void addOperatorToLandmarkMapping(const RelaxedOperator *op, const LandmarkId landmarkId) const {
        this->operatorToLandmark[op->id] = landmarkId;
    }

    virtual bool removeOperatorToLandmarkMapping(const RelaxedOperator *op, const LandmarkId /*landmarkId*/) const {
        bool wasSet = (this->operatorToLandmark[op->id] != -1);
        this->operatorToLandmark[op->id] = -1;
        return wasSet;
    }

    virtual bool hasOperatorToLandmarkMapping(const RelaxedOperator *op, const LandmarkId landmarkId) const {
        return this->operatorToLandmark[op->id] == landmarkId;
    }

    virtual int calculateLandmarkCost(const Landmark */*landmark*/, const OperatorCosts& /*operatorCosts*/) const {
        return 1;
    }

};

#endif /* LANDMARK_H_ */
