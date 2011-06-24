#ifndef POINTERMAP_H_
#define POINTERMAP_H_

#include <google/dense_hash_map>
#include <boost/functional/hash.hpp>

template<class Key, typename Value>
class PointerMap: public google::dense_hash_map<Key*, Value, boost::hash<Key*> > {
public:
    PointerMap() {
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

#endif /* POINTERMAP_H_ */
