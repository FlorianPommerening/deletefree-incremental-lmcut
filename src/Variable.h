#ifndef VARIABLE_H
#define VARIABLE_H

#include <google/dense_hash_set>
#include <boost/functional/hash.hpp>
#include <boost/iterator/iterator_facade.hpp>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>

#include "UIntEx.h"
#include "PointerMap.h"
#include "foreach.h"

// forward declaration
class RelaxedOperator;

/*
 * A variable in a delete-free planning task with some temporary variables for
 * cross-referencing, h^max and h^LM-cut calculation.
 */
struct Variable {
public:
    Variable();
    Variable(std::string name, int id);
    std::string name;
    UIntEx hmax;
    bool closed;
    // values filled by cross-referencing the task
    int id;
    std::vector<RelaxedOperator *> precondition_of;
    std::vector<RelaxedOperator *> effect_of;
};


/*
 * A set of variables.
 * Wraps vector<int> with 1 at position i iff variable with id == i is in the set
 * (this will take up more space than vector<bool> but requires no bit magic)
 * TODO: compare performance with vector<bool> and boost::dynamic_bitset
 */
class VariableSet {
public:
    template <class Value, class VariableSetClass>
    class VariableSetIterator: public boost::iterator_facade<VariableSetIterator<Value, VariableSetClass>,
                                                             Value,
                                                             boost::forward_traversal_tag> {
    public:
        VariableSetIterator(): set(NULL), index(0) {}
        VariableSetIterator(VariableSetClass *set, int index): set(set), index(index) {
            if (this->set->containsIndex[this->index] == 0) {
                this->increment();
            }
        }
    private:
        friend class boost::iterator_core_access;

        bool equal(const VariableSet::VariableSetIterator<Value, VariableSetClass>& other) const {
            return (this->index == other.index && this->set == other.set);
        }

        void increment() {
            do {
                this->index++;
                if (this->index >= VariableSet::nVariables) {
                    this->index = VariableSet::nVariables;
                    break;
                }
            } while(this->set->containsIndex[this->index] == 0);
        }

        Value&dereference() const {
            return (*VariableSet::variables)[this->index];
        }

    private:
        VariableSetClass *set;
        int index;
    };
public:
    typedef Variable* value_type;
    typedef VariableSetIterator<Variable *, VariableSet> iterator;
    typedef VariableSetIterator<Variable *const, const VariableSet> const_iterator;

    VariableSet() {
        this->containsIndex.resize(VariableSet::nVariables);
    }
    VariableSet(const VariableSet &other): containsIndex(other.containsIndex),
                                           nEntries(other.nEntries) {
    }

    VariableSet& operator =(const VariableSet &other);

    void clear() {
        memset(&(this->containsIndex[0]), 0, sizeof(int) * this->containsIndex.size());
    }

    void add(Variable *element) {
        if (this->contains(element)) {
            return;
        }
        this->nEntries++;
        this->containsIndex[element->id] = 1;
    }

    bool contains(Variable *element) const {
        return (this->containsIndex[element->id] != 0);
    }

    void inplaceUnion(const VariableSet &other) {
        assert(this->containsIndex.size() == other.containsIndex.size());
        std::vector<int>::iterator end = this->containsIndex.end();
        std::vector<int>::iterator itThis = this->containsIndex.begin();
        std::vector<int>::const_iterator itOther = other.containsIndex.begin();
        while (itThis != end) {
            if (*itOther != 0 && *itThis == 0) {
                this->nEntries++;
                *itThis = 1;
            }
            ++itThis;
            ++itOther;
        }
    }

    void inplaceIntersection(const VariableSet &other) {
        assert(this->containsIndex.size() == other.containsIndex.size());
        std::vector<int>::iterator end = this->containsIndex.end();
        std::vector<int>::iterator itThis = this->containsIndex.begin();
        std::vector<int>::const_iterator itOther = other.containsIndex.begin();
        while (itThis != end) {
            if (*itOther == 0 && *itThis != 0) {
                this->nEntries--;
                *itThis = 0;
            }
            ++itThis;
            ++itOther;
        }
    }

    bool isSubsetOf(const VariableSet &other) const {
        if (this->nEntries > other.nEntries) {
            return false;
        }
        if (this->nEntries == 0) {
            return true;
        }
        assert(this->containsIndex.size() == other.containsIndex.size());
        std::vector<int>::const_iterator end = this->containsIndex.end();
        std::vector<int>::const_iterator itThis = this->containsIndex.begin();
        std::vector<int>::const_iterator itOther = other.containsIndex.begin();
        while (itThis != end) {
            if (*itOther == 0 && *itThis != 0) {
                return false;
            }
            ++itThis;
            ++itOther;
        }
        return true;
    }

    int size() const {
        return this->nEntries;
    }

    void removeIrrelevant(PointerMap<Variable, bool> &relevant) {
        // TODO this could be more elegant
        int newSize = 0;
        typedef PointerMap<Variable, bool>::value_type entry_value_type;
        foreach(entry_value_type &entry, relevant) {
            if (entry.second) {
                newSize++;
            }
        }
        std::vector<int> containsRelevantIndex;
        containsRelevantIndex.resize(newSize);
        this->nEntries = 0;
        int relevantIndex = 0;
        for (unsigned index=0; index < this->containsIndex.size(); ++index) {
            if (relevant[(*VariableSet::variables)[index]]) {
                containsRelevantIndex[relevantIndex++] = this->containsIndex[index];
                if (this->containsIndex[index]) {
                    this->nEntries++;
                }
            }
        }
        std::swap(this->containsIndex, containsRelevantIndex);
    }

    // allow iteration over set
    iterator begin() {
        return iterator(this, 0);
    }
    iterator end() {
        return iterator(this, VariableSet::nVariables);
    }
    const_iterator begin() const {
        return const_iterator(this, 0);
    }
    const_iterator end() const {
        return const_iterator(this, VariableSet::nVariables);
    }

    static void setFullVariableSet(std::vector<Variable *> *variables) {
        VariableSet::variables = variables;
        VariableSet::nVariables = variables->size();
    }
private:
    std::vector<int> containsIndex;
    int nEntries;
    static int nVariables;
    static std::vector<Variable *> *variables;
};

#endif
