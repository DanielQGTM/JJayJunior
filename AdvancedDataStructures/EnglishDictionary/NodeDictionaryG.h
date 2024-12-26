#ifndef NODEDICTIONARYG_H
#define NODEDICTIONARYG_H

#include "DNodeG.h"
#include "IteratorG.h"
#include "Range.h"
#include <iostream>

template <typename K, typename V>
class NodeDictionaryG {
private:
    int uKeys;
    int n;
    DNodeG<K, V>* header;
    DNodeG<K, V>* trailer;

public:
    NodeDictionaryG();
    ~NodeDictionaryG();

    int size() const;
    int uniqueKeys() const;
    bool empty() const;

    IteratorG<K, V> begin() const;
    IteratorG<K, V> end() const;
    IteratorG<K, V> find(const K& k) const;
    IteratorG<K, V> put(const K& k, const V& v);

    void erase(const K& k);              
    void erase(const IteratorG<K, V>& p); 
    void erase(Range<K, V>& r);

    Range<K, V> findAll(const K& k) const;
    void print() const;
    void print(const Range<K, V>& r) const;
};

#endif