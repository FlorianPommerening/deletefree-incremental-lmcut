#ifndef VARIABLE_H
#define VARIABLE_H

#include <google/dense_hash_set>
#include <boost/functional/hash.hpp>
#include <boost/iterator/iterator_facade.hpp>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <boost/dynamic_bitset.hpp>

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
 * Wraps vector<bool> with true at position i iff variable with id == i is in the set
 * (this will take up less space than vector<int> but requires bit magic)
 * TODO: compare performance with boost::dynamic_bitset
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
            if (!this->set->containsIndex[this->index]) {
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
            } while(!this->set->containsIndex[this->index]);
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
        this->containsIndex = boost::dynamic_bitset<>(VariableSet::nVariables);
    }
    VariableSet(const VariableSet &other): containsIndex(other.containsIndex),
                                           nEntries(other.nEntries) {
    }

    VariableSet& operator =(const VariableSet &other);

    void clear() {
        this->containsIndex.reset();
    }

    void add(Variable *element) {
        if (this->contains(element)) {
            return;
        }
        this->nEntries++;
        this->containsIndex.set(element->id);
    }

    bool contains(Variable *element) const {
        return this->containsIndex.test(element->id);
    }

    void inplaceUnion(const VariableSet &other) {
        this->containsIndex |= other.containsIndex;
        this->nEntries = this->containsIndex.count();
    }

    void inplaceIntersection(const VariableSet &other) {
        this->containsIndex &= other.containsIndex;
        this->nEntries = this->containsIndex.count();
    }

    bool isDisjointWith(const VariableSet &other) const {
        return (this->containsIndex & other.containsIndex).empty();
    }

    bool isSubsetOf(const VariableSet &other) const {
        return this->containsIndex.is_subset_of(other.containsIndex);
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
        boost::dynamic_bitset<> containsRelevantIndex = boost::dynamic_bitset<>(newSize);
        this->nEntries = 0;
        int relevantIndex = 0;
        for (unsigned index=0; index < this->containsIndex.size(); ++index) {
            if (relevant[(*VariableSet::variables)[index]]) {
                containsRelevantIndex[relevantIndex++] = this->containsIndex[index];
            }
        }
        std::swap(this->containsIndex, containsRelevantIndex);
        this->nEntries = this->containsIndex.count();
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
    boost::dynamic_bitset<> containsIndex;
    int nEntries;
    static int nVariables;
    static std::vector<Variable *> *variables;
};

#endif
