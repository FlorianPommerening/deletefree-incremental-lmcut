#ifndef VARIABLE_H
#define VARIABLE_H

#include <boost/iterator/iterator_facade.hpp>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>

#include "UIntEx.h"
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
 * A set of variables representing an effect.
 * Wraps vector<Variable *>. Adding and removing variables is slow (O(n))
 * but looping over all entries is faster than in the implementation of State.
 */
class Effects {
public:
    typedef std::vector<Variable *>::value_type value_type;
    typedef std::vector<Variable *>::iterator iterator;
    typedef std::vector<Variable *>::const_iterator const_iterator;

    void add(Variable *element) {
        foreach (std::vector<Variable *>::value_type it, this->entries) {
            if (&*it == element) {
                return;
            }
        }
        this->entries.push_back(element);
    }

    int size() const {
        return this->entries.size();
    }

    void inplaceIntersection(const Effects &other);

    void removeIrrelevant(const std::vector<bool> &relevant);

    iterator begin() {
        return this->entries.begin();
    }
    iterator end() {
        return this->entries.end();
    }
    const_iterator begin() const {
        return this->entries.begin();
    }
    const_iterator end() const {
        return this->entries.end();
    }
private:
    std::vector<Variable *> entries;
};

/*
 * Precondition sets can be represented in the same way as effects
 */
typedef Effects Preconditions;

/*
 * A set of variables representing a state.
 * Wraps vector<int> with 1 at position i iff variable with id == i is in the set
 * (this will take up more space than vector<bool> but requires no bit magic)
 * TODO: compare performance with vector<bool> and boost::dynamic_bitset
 */
class State {
public:
    template <class Value, class StateClass>
    class StateIterator: public boost::iterator_facade<StateIterator<Value, StateClass>,
                                                       Value,
                                                       boost::forward_traversal_tag> {
    public:
        StateIterator(): state(NULL), index(0) {}
        StateIterator(StateClass *state, int index): state(state), index(index) {
            if (this->index < this->state->containsIndex.size() &&
                this->state->containsIndex[this->index] == 0) {
                this->increment();
            }
        }
    private:
        friend class boost::iterator_core_access;

        bool equal(const State::StateIterator<Value, StateClass>& other) const {
            return (this->index == other.index && this->state == other.state);
        }

        void increment() {
            do {
                this->index++;
                if (this->index >= State::nVariables) {
                    this->index = State::nVariables;
                    break;
                }
            } while(this->state->containsIndex[this->index] == 0);
        }

        Value &dereference() const {
            return (*State::variables)[this->index];
        }

    private:
        StateClass *state;
        int index;
    };
public:
    typedef Variable* value_type;
    typedef StateIterator<Variable *, State> iterator;
    typedef StateIterator<Variable *const, const State> const_iterator;

    State(): nEntries(0) {
        this->containsIndex.resize(State::nVariables);
    }
    State(const State &other): containsIndex(other.containsIndex),
                               nEntries(other.nEntries) {
    }

    State& operator =(const State &other);

    void add(Variable *element) {
        if (this->contains(element)) {
            return;
        }
        this->nEntries++;
        this->containsIndex[element->id] = 1;
    }

    void add(const Effects &effects) {
        foreach(Variable* v, effects) {
            this->add(v);
        }
    }

    bool contains(Variable *element) const {
        return (this->containsIndex[element->id] != 0);
    }

    bool contains(const Preconditions &preconditions) const {
        foreach(Variable * v, preconditions) {
            if (!this->contains(v)) {
                return false;
            }
        }
        return true;
    }

    int size() const {
        return this->nEntries;
    }

    // allow iteration over set
    iterator begin() {
        return iterator(this, 0);
    }
    iterator end() {
        return iterator(this, State::nVariables);
    }
    const_iterator begin() const {
        return const_iterator(this, 0);
    }
    const_iterator end() const {
        return const_iterator(this, State::nVariables);
    }

    static void setFullVariableSet(std::vector<Variable *> *variables) {
        State::variables = variables;
        State::nVariables = variables->size();
    }
private:
    std::vector<int> containsIndex;
    int nEntries;
    static int nVariables;
    static std::vector<Variable *> *variables;
};

#endif
