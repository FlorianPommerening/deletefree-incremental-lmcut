#ifndef LANDMARK_H_
#define LANDMARK_H_

#include "RelaxedOperator.h"
#include <boost/iterator/iterator_facade.hpp>

typedef std::vector<RelaxedOperator *> Landmark;
typedef int LandmarkId;

class ILandmarkCollection {
public:
    virtual ~ILandmarkCollection() {
    }
    virtual void clear() = 0;
    /*
     * The landmark given as the parameter will be emptied by this function.
     * Returns a landmarkId for the newly added landmark.
     */
    virtual LandmarkId addLandmark(Landmark &landmarkIn, const OperatorCosts &operatorCosts) = 0;
    /*
     * Returns the landmarkIds of all landmarks containing op
     */
    virtual std::vector<LandmarkId> containingLandmarks(const RelaxedOperator *const op) const = 0;
    /*
     * Returns true if no landmark became empty by removing op
     * and false if op was the last operator in at least one landmark.
     */
    virtual bool removeOperatorFromContainingLandmarks(RelaxedOperator *const op, OperatorCosts &operatorCosts) = 0;
    virtual void removeContainingLandmarks(const RelaxedOperator *const op) = 0;
    virtual int getLandmarkSize(const LandmarkId landmarkId) const = 0;
    virtual UIntEx getCost() const = 0;
    virtual UIntEx getLandmarkCost(const LandmarkId landmarkId) const = 0;
    /*
     * this will ensure that the landmark with id landmarkId is up to date
     * and return it for iteration. Do not change the landmark or reuse the reference
     * as it will become invalid once the landmark is changed or removed
     */
    virtual Landmark &iterateLandmark(LandmarkId landmarkId) const = 0;
    /*
     * Returns the number of valid landmarks n and guarantees that these landmarks have the LandmarkIds 0 .. (n-1)
     */
    virtual int getValidLandmarkIds() const = 0;
    /*
     * This will ensure that the operators in singleOperatorLandmarks are still valid, and return the list
     */
    virtual std::vector<RelaxedOperator*> getSingleOperatorLandmarks() const = 0;
};

class ArbitraryCostLandmarkCollection: public ILandmarkCollection {
public:
    ArbitraryCostLandmarkCollection(const std::vector<RelaxedOperator*> &operators);
    ArbitraryCostLandmarkCollection(const ArbitraryCostLandmarkCollection &other);
    virtual ~ArbitraryCostLandmarkCollection();

    virtual void clear();
    virtual LandmarkId addLandmark(Landmark &landmarkIn, const OperatorCosts &operatorCosts);
    virtual std::vector<LandmarkId> containingLandmarks(const RelaxedOperator *const op) const {
        return this->operatorToLandmark[op->id];
    }

    virtual bool removeOperatorFromContainingLandmarks(RelaxedOperator *const op, OperatorCosts &operatorCosts);
    virtual void removeContainingLandmarks(const RelaxedOperator *const op);

    virtual int getLandmarkSize(const LandmarkId landmarkId) const {
        return this->landmarks[landmarkId]->size();
    }

    virtual UIntEx getCost() const {
        return this->cost;
    }

    virtual UIntEx getLandmarkCost(const LandmarkId landmarkId) const {
        return this->landmarkCosts[landmarkId];
    }

    virtual Landmark &iterateLandmark(LandmarkId landmarkId) const {
        return *(this->landmarks[landmarkId]);
    }

    virtual int getValidLandmarkIds() const {
        return this->landmarks.size();
    }

    virtual std::vector<RelaxedOperator*> getSingleOperatorLandmarks() const {
        // create a copy for iteration
        return std::vector<RelaxedOperator*>(this->singleOperatorLandmarks);
    }
private:
    /*
     * swaps landmarks and necessary meta information at the given indeces.
     * The index landmarkIdToBeErased is assumed to be a position that will be removed later
     * so the meta information for the landmark ending up there will not be updated
     */
    void swapLandmarksForErase(LandmarkId landmarkIdToKeep, LandmarkId landmarkIdToBeErased);
    UIntEx cost;
    std::vector<UIntEx> landmarkCosts;
    std::vector<Landmark*> landmarks;
    std::vector<RelaxedOperator*> singleOperatorLandmarks;
    std::vector<std::vector<LandmarkId> > operatorToLandmark;
};

class BinaryCostLandmarkCollection: public ILandmarkCollection {
public:
    BinaryCostLandmarkCollection(const std::vector<RelaxedOperator*> &operators);
    BinaryCostLandmarkCollection(const BinaryCostLandmarkCollection &other);
    ~BinaryCostLandmarkCollection();

    virtual void clear();
    virtual LandmarkId addLandmark(Landmark &landmarkIn, const OperatorCosts &operatorCosts);
    virtual std::vector<LandmarkId> containingLandmarks(const RelaxedOperator *const op) const ;
    /*
     * lazy remove (will not update actual landmarks, unless they are removed)
     */
    virtual bool removeOperatorFromContainingLandmarks(RelaxedOperator *const op, OperatorCosts &operatorCosts);
    /*
     * lazy remove (will not update singleOperatorLandmarks)
     */
    virtual void removeContainingLandmarks(const RelaxedOperator *const op);

    virtual int getLandmarkSize(const LandmarkId landmarkId) const {
        return this->sizes[landmarkId];
    }

    virtual UIntEx getCost() const {
        return cost;
    }

    virtual UIntEx getLandmarkCost(const LandmarkId /*landmarkId*/) const {
        return 1;
    }
    virtual Landmark &iterateLandmark(LandmarkId landmarkId) const;
    virtual int getValidLandmarkIds() const;
    virtual std::vector<RelaxedOperator*> getSingleOperatorLandmarks() const;
private:
    UIntEx cost;
    // making everything mutable kind of destroys the effect of const, but in this class
    // everything can be moved during iteration and the collection is still logically unchanged
    mutable std::vector<Landmark*> landmarks;
    mutable std::vector<int> sizes;
    mutable std::vector<int> dirty;
    mutable bool landmarksDirty;
    mutable std::vector<RelaxedOperator*> singleOperatorLandmarks;
    mutable bool singleOperatorLandmarksDirty;
    mutable std::vector<int> operatorToLandmark;
};

#endif /* LANDMARK_H_ */
