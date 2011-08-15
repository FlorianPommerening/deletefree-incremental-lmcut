#include "Landmark.h"
#include "foreach.h"


using namespace std;


UnitCostLandmarkCollection::UnitCostLandmarkCollection(std::vector<RelaxedOperator*> &operators) {
    this->operatorToLandmark.resize(operators.size(), -1);
}

UnitCostLandmarkCollection::UnitCostLandmarkCollection(const UnitCostLandmarkCollection &other): cost(other.cost),
                                                                     landmarksDirty(other.landmarksDirty),
                                                                     sizes(other.sizes),
                                                                     dirty(other.dirty),
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
    this->landmarksDirty = false;
    this->sizes.clear();
    this->dirty.clear();
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
    this->cost++;
    int landmarkSize = landmark->size();
    for(int i=0; i != landmarkSize; ++i) {
        this->operatorToLandmark[((*landmark)[i])->id] = landmarkId;
    }
    this->sizes.push_back(landmarkSize);
    this->dirty.push_back(false);
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
    this->dirty[landmarkId] = true;
    if (this->sizes[landmarkId] == 1) {
        this->singleOperatorLandmarks.push_back((*this->landmarks[landmarkId])[0]);
    }
    else if (this->sizes[landmarkId] == 0) {
        this->landmarksDirty = true;
        this->singleOperatorLandmarksDirty = true;
        this->dirty[landmarkId] = false;
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
    this->dirty[landmarkId] = false;
    this->landmarksDirty = true;
    this->singleOperatorLandmarksDirty = true;
    delete this->landmarks[landmarkId];
    this->landmarks[landmarkId] = NULL;
    this->cost--;
}

Landmark &UnitCostLandmarkCollection::iterateLandmark(LandmarkId landmarkId) {
    Landmark &landmark = *this->landmarks[landmarkId];
    if (this->dirty[landmarkId]) {
        unsigned lastValid = -1;
        for(unsigned current = 0; current < landmark.size(); ++current) {
            RelaxedOperator *op = landmark[current];
            if (this->operatorToLandmark[op->id] == landmarkId) {
                ++lastValid;
                if (current != lastValid) {
                    swap(landmark[current], landmark[lastValid]);
                }
            }
        }
        // TODO right now add() is not possible after a delete(), if it is, there could be duplicates in the list
        // one way to deal with them is to set all operatorToLandmark[op->id] to -1 the first time they are encountered and reset them in a second run
        landmark.resize(lastValid + 1);
        this->dirty[landmarkId] = false;
    }
    return landmark;
}

int UnitCostLandmarkCollection::getValidLandmarkIds() {
    if (this->landmarksDirty) {
        unsigned lastValid = -1;
        for(unsigned current = 0; current < this->landmarks.size(); ++current) {
            if (this->landmarks[current] != NULL) {
                ++lastValid;
                if (current != lastValid) {
                    swap(this->landmarks[current], this->landmarks[lastValid]);
                }
            }
        }
        this->landmarks.resize(lastValid + 1);
        this->landmarksDirty = false;
    }
    return this->landmarks.size();
}

std::vector<RelaxedOperator*> &UnitCostLandmarkCollection::getSingleOperatorLandmarks() {
    if (this->singleOperatorLandmarksDirty) {
        unsigned lastValid = -1;
        for(unsigned current = 0; current < this->landmarks.size(); ++current) {
            RelaxedOperator *op = this->singleOperatorLandmarks[current];
            if (this->operatorToLandmark[op->id] != -1) {
                ++lastValid;
                if (current != lastValid) {
                    swap(this->singleOperatorLandmarks[current], this->singleOperatorLandmarks[lastValid]);
                }
            }
        }
        this->singleOperatorLandmarks.resize(lastValid + 1);
        this->singleOperatorLandmarksDirty = false;
    }
    return this->singleOperatorLandmarks;
}
