#include "Landmark.h"
#include "foreach.h"


using namespace std;


UnitCostLandmarkCollection::UnitCostLandmarkCollection(const std::vector<RelaxedOperator*> &operators):
                                                                     cost(0),
                                                                     landmarksDirty(false),
                                                                     singleOperatorLandmarksDirty(false) {
    this->operatorToLandmark.resize(operators.size(), -1);
}

UnitCostLandmarkCollection::UnitCostLandmarkCollection(const UnitCostLandmarkCollection &other):
                                                                     cost(other.cost),
                                                                     sizes(other.sizes),
                                                                     dirty(other.dirty),
                                                                     landmarksDirty(other.landmarksDirty),
                                                                     singleOperatorLandmarks(other.singleOperatorLandmarks),
                                                                     singleOperatorLandmarksDirty(other.singleOperatorLandmarksDirty),
                                                                     operatorToLandmark(other.operatorToLandmark) {
    this->landmarks.resize(other.landmarks.size());
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
    this->dirty.clear();
    this->landmarksDirty = false;
    this->singleOperatorLandmarks.clear();
    this->singleOperatorLandmarksDirty = false;
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
    this->sizes.push_back(landmark->size());
    this->dirty.push_back(0);
    ++(this->cost);
    foreach(RelaxedOperator *op, *landmark) {
        this->operatorToLandmark[op->id] = landmarkId;
    }
    if (landmark->size() == 1) {
        this->singleOperatorLandmarks.push_back(landmark->at(0));
    }
    return landmarkId;
}

LandmarkId UnitCostLandmarkCollection::containingLandmark(const RelaxedOperator *const op) const {
    LandmarkId landmarkId = this->operatorToLandmark[op->id];
    if (landmarkId != -1 && this->landmarks[landmarkId] != NULL) {
        return landmarkId;
    }
    return -1;
}

bool UnitCostLandmarkCollection::removeOperatorFromContainingLandmark(RelaxedOperator *const op) {
    LandmarkId landmarkId = this->operatorToLandmark[op->id];
    Landmark &containingLM = *this->landmarks[landmarkId];
    this->operatorToLandmark[op->id] = -1;
    --(this->sizes[landmarkId]);
    this->dirty[landmarkId] = 1;

    if (this->sizes[landmarkId] == 1) {
        this->singleOperatorLandmarks.push_back(containingLM[0]);
    }
    else if (this->sizes[landmarkId] == 0) {
        this->singleOperatorLandmarksDirty = true;
        this->cost = UIntEx::INF;
        return false;
    }
    return true;
}

void UnitCostLandmarkCollection::removeLandmark(const LandmarkId landmarkId) {
    Landmark &landmark = *(this->landmarks[landmarkId]);
    // TODO
    // should use loop over valid operators in landmark instead
    // maybe it is even enough to only update sizes
    foreach(RelaxedOperator *op, landmark) {
        this->operatorToLandmark[op->id] = -1;
    }
    this->sizes[landmarkId] = 0;
    this->dirty[landmarkId] = 0;
    this->landmarksDirty = true;
    this->singleOperatorLandmarksDirty = true;
    delete this->landmarks[landmarkId];
    this->landmarks[landmarkId] = NULL;
    --(this->cost);
}

Landmark &UnitCostLandmarkCollection::iterateLandmark(const LandmarkId landmarkId) const {
    Landmark &landmark = *this->landmarks[landmarkId];
    if (this->dirty[landmarkId]) {
        unsigned nValid = 0;
        for(unsigned current = 0; current < landmark.size(); ++current) {
            RelaxedOperator *op = landmark[current];
            if (this->operatorToLandmark[op->id] == landmarkId) {
                landmark[nValid] = landmark[current];
                ++nValid;
            }
        }
        // TODO right now add() is not possible after a delete(), if it is, there could be duplicates in the list
        // one way to deal with them is to set all operatorToLandmark[op->id] to -1 the first time they are encountered and reset them in a second run
        landmark.resize(nValid);
        this->dirty[landmarkId] = false;
    }
    return landmark;
}

int UnitCostLandmarkCollection::getValidLandmarkIds() const {
    if (this->landmarksDirty) {
        unsigned nValid = 0;
        for(unsigned current = 0; current < this->landmarks.size(); ++current) {
            if (this->landmarks[current] != NULL) {
                if (nValid != current) {
                    this->landmarks[nValid] = this->landmarks[current];
                    this->sizes[nValid] = this->sizes[current];
                    this->dirty[nValid] = this->dirty[current];
                    foreach(RelaxedOperator *op, *this->landmarks[nValid]) {
                        this->operatorToLandmark[op->id] = nValid;
                    }
                }
                ++nValid;
            }
        }
        this->landmarks.resize(nValid);
        this->sizes.resize(nValid);
        this->dirty.resize(nValid);
        this->landmarksDirty = false;
    }
    return this->landmarks.size();
}

std::vector<RelaxedOperator*> &UnitCostLandmarkCollection::getSingleOperatorLandmarks() const {
    if (this->singleOperatorLandmarksDirty) {
        unsigned nValid = 0;
        for(unsigned current = 0; current < this->singleOperatorLandmarks.size(); ++current) {
            RelaxedOperator *op = this->singleOperatorLandmarks[current];
            if (this->operatorToLandmark[op->id] != -1) {
                this->singleOperatorLandmarks[nValid] = this->singleOperatorLandmarks[current];
                ++nValid;
            }
        }
        this->singleOperatorLandmarks.resize(nValid);
        this->singleOperatorLandmarksDirty = false;
    }
    return this->singleOperatorLandmarks;
}
