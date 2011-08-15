#ifndef LANDMARK_H_
#define LANDMARK_H_

#include "PointerMap.h"
#include "RelaxedOperator.h"
#include <boost/iterator/iterator_facade.hpp>

typedef std::vector<RelaxedOperator *> Landmark;
typedef int LandmarkId;

class UnitCostLandmarkCollection {
public:
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

    /*
     * this will ensure that the landmark with id landmarkId is up to date
     * and return it for iteration. Do not change the landmark or reuse the reference
     * as it will become invalid once the landmark is changed or removed
     */
    Landmark &iterateLandmark(LandmarkId landmarkId);

    /*
     * Returns the number of valid landmarks n and guarantees that these landmarks have the LandmarkIds 0 .. (n-1)
     */
    int getValidLandmarkIds();

    /*
     * This will ensure that the operators in singleOperatorLandmarks are still valid, and return the list
     */
    std::vector<RelaxedOperator*> &getSingleOperatorLandmarks();
private:
    int cost;
    std::vector<Landmark*> landmarks;
    bool landmarksDirty;
    std::vector<int> sizes;
    std::vector<bool> dirty;
    std::vector<RelaxedOperator*> singleOperatorLandmarks;
    bool singleOperatorLandmarksDirty;
    std::vector<int> operatorToLandmark;
};

#endif /* LANDMARK_H_ */
