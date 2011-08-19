#ifndef POINTERMAP_H_
#define POINTERMAP_H_

#include <google/dense_hash_map>
#include <google/dense_hash_set>
#include <boost/functional/hash.hpp>

/*
 * Special case of google's dense hash map where the key is a pointer type.
 * boost::hash is used as a hash function and the addresses of private static
 * variables are used as placeholders for deleted and empty values.
 */
template<class Key, typename Value>
class PointerMap: public google::dense_hash_map<Key*, Value, boost::hash<Key*> > {
public:
    PointerMap() {
        // see google's documentation for why these values are needed
        this->set_deleted_key(&(PointerMap<Key, Value>::DeletedKey));
        this->set_empty_key(&(PointerMap<Key, Value>::EmptyKey));
    }
private:
    // special value symbolizing an entry in the map that was deleted
    static Key DeletedKey;
    // special value symbolizing an entry in the map that is not assigned yet
    static Key EmptyKey;
};

template<class Key, typename Value> Key PointerMap<Key, Value>::DeletedKey;
template<class Key, typename Value> Key PointerMap<Key, Value>::EmptyKey;

/*
 * Special case of google's dense hash set where the value is a pointer type.
 * boost::hash is used as a hash function and the addresses of private static
 * variables are used as placeholders for deleted and empty values.
 */
template<typename Value>
class PointerSet: public google::dense_hash_set<Value*, boost::hash<Value*> > {
public:
    PointerSet() {
        // see google's documentation for why these values are needed
        this->set_deleted_key(&(PointerSet<Value>::DeletedKey));
        this->set_empty_key(&(PointerSet<Value>::EmptyKey));
    }
private:
    // special value symbolizing an entry in the set that was deleted
    static Value DeletedKey;
    // special value symbolizing an entry in the set that is not assigned yet
    static Value EmptyKey;
};

template<typename Value> Value PointerSet<Value>::DeletedKey;
template<typename Value> Value PointerSet<Value>::EmptyKey;

#endif /* POINTERMAP_H_ */
