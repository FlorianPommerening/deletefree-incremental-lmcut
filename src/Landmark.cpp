#include "Landmark.h"
#include "foreach.h"


using namespace std;

/*
 *  COMMON IMPLEMENTATION
 */

AbstractLandmarkCollection::AbstractLandmarkCollection():
        cost(0),
        landmarksDirty(false),
        singleOperatorLandmarksDirty(false) {
}

AbstractLandmarkCollection::AbstractLandmarkCollection(const AbstractLandmarkCollection &other):
        cost(other.cost),
        landmarkSizes(other.landmarkSizes),
        landmarkCosts(other.landmarkCosts),
        dirty(other.dirty),
        landmarksDirty(other.landmarksDirty),
        singleOperatorLandmarks(other.singleOperatorLandmarks),
        singleOperatorLandmarksDirty(other.singleOperatorLandmarksDirty) {
    this->landmarks.resize(other.landmarks.size());
    for(unsigned i=0; i != other.landmarks.size(); ++i) {
        if (other.landmarks[i] != NULL) {
            this->landmarks[i] = new Landmark(*(other.landmarks[i]));
        } else {
            this->landmarks[i] = NULL;
        }
    }
}

AbstractLandmarkCollection::~AbstractLandmarkCollection(){
    for(unsigned i=0; i != this->landmarks.size(); ++i) {
        delete this->landmarks[i];
    }
}

void AbstractLandmarkCollection::clear() {
    for(unsigned i=0; i != this->landmarks.size(); ++i) {
        delete this->landmarks[i];
    }
    this->landmarks.clear();
    this->landmarkSizes.clear();
    this->landmarkCosts.clear();
    this->dirty.clear();
    this->landmarksDirty = false;
    this->singleOperatorLandmarks.clear();
    this->singleOperatorLandmarksDirty = false;
    this->cost = 0;
}

LandmarkId AbstractLandmarkCollection::addLandmark(Landmark &landmarkIn, OperatorCosts &operatorCosts) {
    Landmark *landmark = new Landmark();
    swap(*landmark, landmarkIn);
    LandmarkId landmarkId = this->landmarks.size();
    this->landmarks.push_back(landmark);
    this->landmarkSizes.push_back(landmark->size());
    int landmarkCost = this->calculateLandmarkCost(landmark, operatorCosts);
    this->landmarkCosts.push_back(landmarkCost);
    this->dirty.push_back(0);
    this->cost += landmarkCost;
    foreach(RelaxedOperator *op, *landmark) {
        this->addOperatorToLandmarkMapping(op, landmarkId);
    }
    if (landmark->size() == 1) {
        this->singleOperatorLandmarks.push_back(landmark->at(0));
    }
    return landmarkId;
}

bool AbstractLandmarkCollection::removeOperatorFromContainingLandmarks(RelaxedOperator *const op, OperatorCosts &operatorCosts) {
    vector<LandmarkId> containingLandmarks = this->containingLandmarks(op);
    foreach(LandmarkId landmarkId, containingLandmarks) {
        Landmark &containingLM = *this->landmarks[landmarkId];
        this->removeOperatorToLandmarkMapping(op, landmarkId);
        --(this->landmarkSizes[landmarkId]);
        // try to increase the cost of the landmark by further reducing the cost of all operators it contains
        UIntEx possibleIncrease = -1;
        foreach(RelaxedOperator *op, containingLM) {
            if (!this->hasOperatorToLandmarkMapping(op, landmarkId)) {
                continue;
            }
            if (possibleIncrease == -1) {
                possibleIncrease = operatorCosts[op->id];
            }
            else {
                possibleIncrease = min(operatorCosts[op->id], possibleIncrease);
            }
            if (possibleIncrease == 0) {
                break;
            }
        }
        if (possibleIncrease > 0) {
            foreach(RelaxedOperator *op, containingLM) {
                if (!this->hasOperatorToLandmarkMapping(op, landmarkId)) {
                    continue;
                }
                operatorCosts[op->id] -= possibleIncrease;
            }
            this->landmarkCosts[landmarkId] += possibleIncrease;
            this->cost += possibleIncrease;
        }
        this->dirty[landmarkId] = 1;

        if (this->landmarkSizes[landmarkId] == 1) {
            this->singleOperatorLandmarks.push_back(containingLM[0]);
        }
        else if (this->landmarkSizes[landmarkId] == 0) {
            this->singleOperatorLandmarksDirty = true;
            this->cost = UIntEx::INF;
            return false;
        }
    }
    return true;
}


void AbstractLandmarkCollection::removeLandmark(const LandmarkId landmarkId) {
    Landmark &landmark = *(this->landmarks[landmarkId]);
    // TODO
    // should use loop over valid operators in landmark instead
    // maybe it is even enough to only update sizes
    foreach(RelaxedOperator *op, landmark) {
        this->removeOperatorToLandmarkMapping(op, landmarkId);
    }
    this->landmarkSizes[landmarkId] = 0;
    this->cost -= this->landmarkCosts[landmarkId];
    this->landmarkCosts[landmarkId] = 0;
    this->dirty[landmarkId] = 0;
    this->landmarksDirty = true;
    this->singleOperatorLandmarksDirty = true;
    delete this->landmarks[landmarkId];
    this->landmarks[landmarkId] = NULL;
}

Landmark &AbstractLandmarkCollection::iterateLandmark(LandmarkId landmarkId) const {
    Landmark &landmark = *this->landmarks[landmarkId];
    if (this->dirty[landmarkId]) {
        unsigned nValid = 0;
        for(unsigned current = 0; current < landmark.size(); ++current) {
            RelaxedOperator *op = landmark[current];
            if (this->hasOperatorToLandmarkMapping(op, landmarkId)) {
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

int AbstractLandmarkCollection::getValidLandmarkIds() const {
    if (this->landmarksDirty) {
        unsigned nValid = 0;
        for(unsigned current = 0; current < this->landmarks.size(); ++current) {
            if (this->landmarks[current] != NULL) {
                if (nValid != current) {
                    this->landmarks[nValid] = this->landmarks[current];
                    this->landmarkSizes[nValid] = this->landmarkSizes[current];
                    this->landmarkCosts[nValid] = this->landmarkCosts[current];
                    this->dirty[nValid] = this->dirty[current];
                    foreach(RelaxedOperator *op, *this->landmarks[nValid]) {
                        this->removeOperatorToLandmarkMapping(op, current);
                        this->addOperatorToLandmarkMapping(op, nValid);
                    }
                }
                ++nValid;
            }
        }
        this->landmarks.resize(nValid);
        this->landmarkSizes.resize(nValid);
        this->landmarkCosts.resize(nValid);
        this->dirty.resize(nValid);
        this->landmarksDirty = false;
    }
    return this->landmarks.size();
}

std::vector<RelaxedOperator*> &AbstractLandmarkCollection::getSingleOperatorLandmarks() const {
    if (this->singleOperatorLandmarksDirty) {
        unsigned nValid = 0;
        for(unsigned current = 0; current < this->singleOperatorLandmarks.size(); ++current) {
            RelaxedOperator *op = this->singleOperatorLandmarks[current];
            foreach(LandmarkId landmarkId, this->containingLandmarks(op)) {
                if (this->landmarkSizes[landmarkId] == 1) {
                    this->singleOperatorLandmarks[nValid] = this->singleOperatorLandmarks[current];
                    ++nValid;
                    break;
                }
            }
        }
        this->singleOperatorLandmarks.resize(nValid);
        this->singleOperatorLandmarksDirty = false;
    }
    return this->singleOperatorLandmarks;
}


/*
 *  ARBITRARY COST IMPLEMENTATION
 */
ArbitraryCostLandmarkCollection::ArbitraryCostLandmarkCollection(const std::vector<RelaxedOperator*> &operators) {
    this->operatorToLandmark.resize(operators.size());
}

ArbitraryCostLandmarkCollection::ArbitraryCostLandmarkCollection(const ArbitraryCostLandmarkCollection &other):
       AbstractLandmarkCollection(other),
       operatorToLandmark(other.operatorToLandmark) {
}

void ArbitraryCostLandmarkCollection::clear() {
    AbstractLandmarkCollection::clear();
    int nOperators = this->operatorToLandmark.size();
    this->operatorToLandmark.clear();
    this->operatorToLandmark.resize(nOperators);
}


/*
 *  BINARY COST SPECIFIC OPTIMIZATIONS
 */


BinaryCostLandmarkCollection::BinaryCostLandmarkCollection(const std::vector<RelaxedOperator*> &operators) {
    this->operatorToLandmark.resize(operators.size(), -1);
}

BinaryCostLandmarkCollection::BinaryCostLandmarkCollection(const BinaryCostLandmarkCollection &other):
        AbstractLandmarkCollection(other),
        operatorToLandmark(other.operatorToLandmark) {
}

void BinaryCostLandmarkCollection::clear() {
    AbstractLandmarkCollection::clear();
    int nOperators = this->operatorToLandmark.size();
    this->operatorToLandmark.clear();
    this->operatorToLandmark.resize(nOperators, -1);
}

std::vector<LandmarkId> BinaryCostLandmarkCollection::containingLandmarks(const RelaxedOperator *const op) const {
    LandmarkId landmarkId = this->operatorToLandmark[op->id];
    if (landmarkId != -1 && this->landmarks[landmarkId] != NULL) {
        // vector of size 1 (in binary cost tasks an operator can only be in one LM at one time)
        return vector<LandmarkId>(1, landmarkId);
    }
    return vector<LandmarkId>(0);
}
