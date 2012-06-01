#include "Landmark.h"
#include "foreach.h"

using namespace std;

/*
 *  ARBITRARY COST IMPLEMENTATION
 */

ArbitraryCostLandmarkCollection::ArbitraryCostLandmarkCollection(const std::vector<RelaxedOperator*> &operators):
        cost(0) {
    this->operatorToLandmark.resize(operators.size());
}

ArbitraryCostLandmarkCollection::ArbitraryCostLandmarkCollection(const ArbitraryCostLandmarkCollection &other):
        cost(other.cost),
        landmarkCosts(other.landmarkCosts),
        singleOperatorLandmarks(other.singleOperatorLandmarks),
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

ArbitraryCostLandmarkCollection::~ArbitraryCostLandmarkCollection() {
    for(unsigned i=0; i != this->landmarks.size(); ++i) {
        delete this->landmarks[i];
    }
}

void ArbitraryCostLandmarkCollection::clear(){
    this->cost = 0;
    this->landmarkCosts.clear();
    for(unsigned i=0; i != this->landmarks.size(); ++i) {
        delete this->landmarks[i];
    }
    this->singleOperatorLandmarks.clear();
    int nOperators = this->operatorToLandmark.size();
    this->operatorToLandmark.clear();
    this->operatorToLandmark.resize(nOperators);
}

LandmarkId ArbitraryCostLandmarkCollection::addLandmark(Landmark &landmarkIn, const OperatorCosts &operatorCosts) {
    Landmark *landmark = new Landmark();
    swap(*landmark, landmarkIn);
    LandmarkId landmarkId = this->landmarks.size();
    this->landmarks.push_back(landmark);
    UIntEx landmarkCost = operatorCosts[landmark->at(0)->id];
    foreach(RelaxedOperator *op, *landmark) {
        landmarkCost = min(landmarkCost, operatorCosts[op->id]);
        this->operatorToLandmark[op->id].push_back(landmarkId);
    }

    this->cost += landmarkCost;
    this->landmarkCosts.push_back(landmarkCost);

    if (landmark->size() == 1) {
        this->singleOperatorLandmarks.push_back(landmark->at(0));
    }
    return landmarkId;
}

bool ArbitraryCostLandmarkCollection::removeOperatorFromContainingLandmarks(RelaxedOperator *const op, OperatorCosts &operatorCosts) {
    foreach(LandmarkId landmarkId, this->operatorToLandmark[op->id]) {
        Landmark *landmark = this->landmarks[landmarkId];
        landmark->erase(std::remove(landmark->begin(), landmark->end(), op), landmark->end());

        if (landmark->size() == 1) {
            this->singleOperatorLandmarks.push_back(op);
        }
        else if (landmark->size() == 0) {
            this->cost = UIntEx::INF;
            this->operatorToLandmark[op->id].clear();
            return false;
        }
        // try to increase the cost of the landmark by further reducing the cost of all operators it contains
        UIntEx possibleIncrease = operatorCosts[landmark->at(0)->id];
        foreach(RelaxedOperator *iterOp, *landmark) {
            possibleIncrease = min(operatorCosts[iterOp->id], possibleIncrease);
            if (possibleIncrease == 0) {
                break;
            }
        }
        if (possibleIncrease > 0) {
            foreach(RelaxedOperator *iterOp, *landmark) {
                operatorCosts[iterOp->id] -= possibleIncrease;
            }
            this->landmarkCosts[landmarkId] += possibleIncrease;
            this->cost += possibleIncrease;
        }
    }
    this->operatorToLandmark[op->id].clear();
    return true;
}

void ArbitraryCostLandmarkCollection::removeContainingLandmarks(const RelaxedOperator *const op) {
    int lastGoodIndex = this->landmarks.size();
    vector<LandmarkId> landmarksToDelete = this->operatorToLandmark[op->id];
    sort(landmarksToDelete.begin(), landmarksToDelete.end());
    foreach(LandmarkId landmarkId, landmarksToDelete) {
        Landmark *landmark = this->landmarks[landmarkId];
        this->cost -= this->landmarkCosts[landmarkId];
        if (landmark->size() == 1) {
            std::vector<RelaxedOperator*> &soLM = this->singleOperatorLandmarks;
            soLM.erase(std::remove(soLM.begin(), soLM.end(), landmark->at(0)), soLM.end());
        }
        // remove mapping for deleted landmark
        foreach(RelaxedOperator *op, *landmark) {
            std::vector<LandmarkId> &opToLM = operatorToLandmark[op->id];
            opToLM.erase(std::remove(opToLM.begin(), opToLM.end(), landmarkId), opToLM.end());
        }

        // find the highest index of a landmark that will not be removed and swap this landmark
        // this way all landmarks to be removed will end up at the end of the vector
        // if the highest index is lower then the current index of the landmark we can leave it where it is
        bool willBeRemoved = true;
        while (willBeRemoved && lastGoodIndex > landmarkId) {
            --lastGoodIndex;
            willBeRemoved = (find(landmarksToDelete.begin(), landmarksToDelete.end(), lastGoodIndex) != landmarksToDelete.end());
        }
        if (lastGoodIndex > landmarkId) {
            this->swapLandmarksForErase(landmarkId, lastGoodIndex);
        }
        // clean up the landmark
        delete landmark;
    }
    int newSize = this->landmarks.size() - landmarksToDelete.size();
    this->landmarks.resize(newSize);
    this->landmarkCosts.resize(newSize);
}

void ArbitraryCostLandmarkCollection::swapLandmarksForErase(LandmarkId landmarkIdToKeep, LandmarkId landmarkIdToBeErased) {
    if (landmarkIdToBeErased != landmarkIdToKeep) {
        std::swap(this->landmarks[landmarkIdToKeep], this->landmarks[landmarkIdToBeErased]);
        std::swap(this->landmarkCosts[landmarkIdToKeep], this->landmarkCosts[landmarkIdToBeErased]);
        // correct mapping for swapped landmark which was at landmarkIdToBeErased and is now at landmarkIdToKeep
        // no need to correct for the other landmark because it will be deleted anyway
        foreach(RelaxedOperator *op, *this->landmarks[landmarkIdToKeep]) {
            std::vector<LandmarkId> &opToLM = operatorToLandmark[op->id];
            opToLM.erase(std::remove(opToLM.begin(), opToLM.end(), landmarkIdToBeErased), opToLM.end());
            opToLM.push_back(landmarkIdToKeep);
        }
    }
}




/*
 *  BINARY COST SPECIFIC OPTIMIZATIONS
 */

BinaryCostLandmarkCollection::BinaryCostLandmarkCollection(const std::vector<RelaxedOperator*> &operators):
                                                                     cost(0),
                                                                     landmarksDirty(false),
                                                                     singleOperatorLandmarksDirty(false) {
    this->operatorToLandmark.resize(operators.size(), -1);
}

BinaryCostLandmarkCollection::BinaryCostLandmarkCollection(const BinaryCostLandmarkCollection &other):
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

BinaryCostLandmarkCollection::~BinaryCostLandmarkCollection() {
    for(unsigned i=0; i != this->landmarks.size(); ++i) {
        delete this->landmarks[i];
    }
}

void BinaryCostLandmarkCollection::clear() {
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

LandmarkId BinaryCostLandmarkCollection::addLandmark(Landmark &landmarkIn, const OperatorCosts &/*operatorCosts*/) {
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

std::vector<LandmarkId> BinaryCostLandmarkCollection::containingLandmarks(const RelaxedOperator *const op) const {
    LandmarkId landmarkId = this->operatorToLandmark[op->id];
    if (landmarkId != -1 && this->landmarks[landmarkId] != NULL) {
        // vector of size 1 (in binary cost tasks an operator can only be in one LM at one time)
        return vector<LandmarkId>(1, landmarkId);
    }
    return vector<LandmarkId>(0);
}

bool BinaryCostLandmarkCollection::removeOperatorFromContainingLandmarks(RelaxedOperator *const op, OperatorCosts &/*operatorCosts*/) {
    // there is only one containing landmark in the binary cost setting
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

void BinaryCostLandmarkCollection::removeContainingLandmarks(const RelaxedOperator *const op) {
    // only one landmark to remove here
    LandmarkId landmarkId = this->operatorToLandmark[op->id];
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

Landmark &BinaryCostLandmarkCollection::iterateLandmark(const LandmarkId landmarkId) const {
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

int BinaryCostLandmarkCollection::getValidLandmarkIds() const {
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

std::vector<RelaxedOperator*> BinaryCostLandmarkCollection::getSingleOperatorLandmarks() const {
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
