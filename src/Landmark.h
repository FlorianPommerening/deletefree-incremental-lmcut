#ifndef LANDMARK_H_
#define LANDMARK_H_

#include "PointerMap.h"
#include "RelaxedOperator.h"
#include <boost/iterator/iterator_facade.hpp>

typedef std::vector<RelaxedOperator *> Landmark;
typedef unsigned LandmarkId;

template<class OwnerType, class CollectionType, class ValueType>
class SkipInvalidRepairingIterator: public boost::iterator_facade<SkipInvalidRepairingIterator<OwnerType, CollectionType, ValueType>,
                                                                  ValueType,
                                                                  boost::forward_traversal_tag> {
public:
    SkipInvalidRepairingIterator(): owner(NULL), collection(NULL), index(0) {
    }
    SkipInvalidRepairingIterator(OwnerType *const owner, CollectionType *collection, int index): owner(owner), collection(collection), index(index) {
        if (!this->valid()) {
            this->increment();
        }
    }
protected:
    virtual bool valid() = 0;
    virtual ValueType &dereference() = 0;
    OwnerType *const owner;
    CollectionType *collection;
    unsigned index;
private:
    friend class boost::iterator_core_access;
    bool equal(const SkipInvalidRepairingIterator<OwnerType, CollectionType, ValueType>& other) const {
        return (this->index == other.index && this->collection == other.collection);
    }
    void increment() {
        do {
            this->index++;
            if (this->index >= this->collection->size()) {
                this->index = this->collection->size();
                break;
            }
        } while(!this->valid());
    }

};

class UnitCostLandmarkCollection {
    template<class OwnerType, class CollectionType, class ValueType>
    class LandmarkIdIterator: public SkipInvalidRepairingIterator<OwnerType, CollectionType, ValueType> {
    public:
        LandmarkIdIterator(OwnerType *owner, CollectionType *collection, int index):
                                        SkipInvalidRepairingIterator<OwnerType, CollectionType, ValueType>(owner, collection, index) {
        }
    protected:
        bool valid() {
            return ((*this->collection)[this->index] == NULL);
        }
        ValueType &dereference() {
            return this->index;
        }
    };

    template<class OwnerType, class CollectionType, class ValueType>
    class LandmarkOperatorIterator: public SkipInvalidRepairingIterator<OwnerType, CollectionType, ValueType> {
    public:
        LandmarkOperatorIterator(OwnerType *owner, CollectionType *collection, LandmarkId landmarkId, int index):
                                        SkipInvalidRepairingIterator<OwnerType, CollectionType, ValueType>(owner, collection, index),
                                        landmarkId(landmarkId) {
        }
    protected:
        bool valid() {
            const RelaxedOperator *op = (*this->collection)[this->index];
            return this->owner->operatorToLandmark[op->id] == this->landmarkId;
        }
        ValueType &dereference() {
            return (*this->collection)[this->index];
        }
        LandmarkId landmarkId;
    };

    template<class OwnerType, class CollectionType, class ValueType>
    class SingleOperatorLandmarkIterator: public SkipInvalidRepairingIterator<OwnerType, CollectionType, ValueType> {
    protected:
        bool valid() {
            const RelaxedOperator *op = (*this->collection)[this->index];
            return this->owner->operatorToLandmark[op->id] != -1;
        }
        ValueType &dereference() {
            return (*this->collection)[this->index];
        }
    };

public:
    typedef LandmarkId value_type;
    typedef LandmarkIdIterator<UnitCostLandmarkCollection, std::vector<Landmark *>, LandmarkId> iterator;
    typedef LandmarkIdIterator<UnitCostLandmarkCollection, const std::vector<Landmark *>, const LandmarkId> const_iterator;

    UnitCostLandmarkCollection(std::vector<RelaxedOperator*> &operators);
    UnitCostLandmarkCollection(const UnitCostLandmarkCollection &other);
    ~UnitCostLandmarkCollection();
    void clear();
    /*
     * The landmark given as the parameter will be emptied by this function.
     * Returns a landmarkId for the newly added landmark.
     */
    LandmarkId addLandmark(Landmark &landmarkIn);
    /*
     * Returns the landmarkId for the landmark containing op
     * or -1 if op is not in any landmark.
     */
    LandmarkId containingLandmark(RelaxedOperator *op);
    /*
     * lazy remove (will not update actual landmark, unless it is removed)
     * Returns true if the landmark didn't become empty by removing op
     * and false if op was the last operator.
     */
    bool removeOperatorFromContainingLandmark(RelaxedOperator *op);
    /*
     * lazy remove (will not update singleOperatorLandmarks)
     */
    void removeLandmark(LandmarkId landmarkId);

    int getSize(LandmarkId LandmarkId) {
        return this->sizes[LandmarkId];
    }

    // iterators
    iterator begin() {
        return iterator(this, &this->landmarks, 0);
    }
    iterator end() {
        return iterator(this, &this->landmarks, this->landmarks.size());
    }
    const_iterator begin() const {
        return const_iterator(this, &this->landmarks, 0);
    }
    const_iterator end() const {
        return const_iterator(this, &this->landmarks, this->landmarks.size());
    }

    void iterateLandmark(LandmarkId landmarkId);
private:
    int cost;
    std::vector<Landmark*> landmarks;
    std::vector<LandmarkId> sizes;
    std::vector<RelaxedOperator*> singleOperatorLandmarks;
    std::vector<int> operatorToLandmark;
};

#endif /* LANDMARK_H_ */
