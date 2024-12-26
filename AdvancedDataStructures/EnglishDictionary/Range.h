#ifndef RANGE_H
#define RANGE_H

#include "IteratorG.h"

template <typename K, typename V>
class Range {
private:
    IteratorG<K, V> b;  
    IteratorG<K, V> e;  

public:
    Range(const IteratorG<K, V>& begin, const IteratorG<K, V>& end);

    const IteratorG<K, V>& getB() const; 
    const IteratorG<K, V>& getE() const;
};

#endif