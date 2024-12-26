#ifndef ITERATORG_H
#define ITERATORG_H

#include "DNodeG.h"

template <typename K, typename V>
class NodeDictionaryG; 

template <typename K, typename V>
class IteratorG {
private:
    DNodeG<K, V>* v;

public:
    IteratorG(DNodeG<K, V>* u);
    const V operator*() const;
    bool operator==(const IteratorG& p) const;
    bool operator!=(const IteratorG& p) const;
    IteratorG& operator++();    
    IteratorG& operator--();   
    const Entry<K, V>& entry() const;

    friend class NodeDictionaryG<K, V>; 
};

#endif