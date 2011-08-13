#include "Landmark.h"
#include "foreach.h"


using namespace std;


UnitCostLandmarkCollection::UnitCostLandmarkCollection(std::vector<RelaxedOperator*> &operators) {
    this->operatorToLandmark.resize(operators.size(), -1);
}

UnitCostLandmarkCollection::UnitCostLandmarkCollection(const UnitCostLandmarkCollection &other): cost(other.cost),
                                                                     sizes(other.sizes),
                                                                     singleOperatorLandmarks(other.singleOperatorLandmarks),
                                                                     operatorToLandmark(other.operatorToLandmark) {
    for(unsigned i=0; i != other.landmarks.size(); ++i) {
        if (other.landmarks[i] != NULL) {
            this->landmarks[i] = new Landmark(*(other.landmarks[i]));
        } else {
            this->landmarks[i] = NULL;
        }
    }
}

UnitCostLandmarkCollection::~UnitCostLandmarkCollection() {
    for(unsigned i=0; i != this->landmarks.size(); ++i) {
        delete this->landmarks[i];
    }
}

void UnitCostLandmarkCollection::clear() {
    for(unsigned i=0; i != this->landmarks.size(); ++i) {
        delete this->landmarks[i];
    }
    this->landmarks.clear();
    this->sizes.clear();
    this->singleOperatorLandmarks.clear();
    this->cost = 0;
    int nOperators = this->operatorToLandmark.size();
    this->operatorToLandmark.clear();
    this->operatorToLandmark.resize(nOperators, -1);
}

LandmarkId UnitCostLandmarkCollection::addLandmark(Landmark &landmarkIn) {
    Landmark *landmark = new Landmark();
    swap(*landmark, landmarkIn);
    LandmarkId landmarkId = this->landmarks.size();
    this->landmarks.push_back(landmark);
    this->cost++;
    int landmarkSize = landmark->size();
    for(int i=0; i != landmarkSize; ++i) {
        this->operatorToLandmark[((*landmark)[i])->id] = landmarkId;
    }
    this->sizes[landmarkId] = landmarkSize;
    if (landmarkSize == 1) {
        this->singleOperatorLandmarks.push_back((*landmark)[0]);
    }
    return landmarkId;
}

LandmarkId UnitCostLandmarkCollection::containingLandmark(RelaxedOperator *op) {
    LandmarkId landmarkId = this->operatorToLandmark[op->id];
    if (landmarkId != -1 && this->landmarks[landmarkId] != NULL) {
        return landmarkId;
    }
    return -1;
}

bool UnitCostLandmarkCollection::removeOperatorFromContainingLandmark(RelaxedOperator *op) {
    LandmarkId landmarkId = this->operatorToLandmark[op->id];
    this->operatorToLandmark[op->id] = -1;
    this->sizes[landmarkId]--;
    if (this->sizes[landmarkId] == 0) {
        delete this->landmarks[landmarkId];
        this->landmarks[landmarkId] = NULL;
        this->cost--;
        return false;
    }
    return true;
}

void UnitCostLandmarkCollection::removeLandmark(LandmarkId landmarkId) {
    Landmark &landmark = *(this->landmarks[landmarkId]);
    // TODO
    // should use loop over valid operators in landmark instead
    // maybe it is even enough to only update sizes
    for (unsigned i=0; i != landmark.size(); ++i) {
        this->operatorToLandmark[landmark[i]->id] = -1;
    }
    this->sizes[landmarkId] = 0;
    delete this->landmarks[landmarkId];
    this->landmarks[landmarkId] = NULL;
    this->cost--;
}
