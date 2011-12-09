/*
 * UniversalRestartSequence.h
 *
 *  Created on: Dec 9, 2011
 *      Author: flogo
 */

#ifndef UNIVERSALRESTARTSEQUENCE_H_
#define UNIVERSALRESTARTSEQUENCE_H_

/*
 * Lazily generates the universal restart strategy mentioned in (Luby et al. 1993)
 */
class UniversalRestartSequence {
public:
    UniversalRestartSequence(): currentIndex(0), nextPower(0) {
    }

    int getNext() {
        if (this->sequence.size() <= this->currentIndex) {
            int oldSize = this->sequence.size();
            for (int i = 0; i < oldSize; ++i) {
                this->sequence.push_back(this->sequence[i]);
            }
            this->sequence.push_back(1 << this->nextPower++);
        }
        return this->sequence[this->currentIndex++];
    }
private:
    std::vector<int> sequence;
    int currentIndex;
    int nextPower;
};


#endif /* UNIVERSALRESTARTSEQUENCE_H_ */
