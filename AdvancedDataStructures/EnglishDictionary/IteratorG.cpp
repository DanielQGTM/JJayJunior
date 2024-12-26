#include "IteratorG.h"
#include <string> 

template <typename K, typename V>
IteratorG<K, V>::IteratorG(DNodeG<K, V>* u) : v(u) {}

template <typename K, typename V>
const V IteratorG<K, V>::operator*() const {
    return v->elm.getV(); 
}

template <typename K, typename V>
bool IteratorG<K, V>::operator==(const IteratorG& p) const {
    return v == p.v;
}

template <typename K, typename V>
bool IteratorG<K, V>::operator!=(const IteratorG& p) const {
    return v != p.v;
}

template <typename K, typename V>
IteratorG<K, V>& IteratorG<K, V>::operator++() {
    v = v->next;
    return *this; 
}

template <typename K, typename V>
IteratorG<K, V>& IteratorG<K, V>::operator--() {
    v = v->prev;
    return *this; 
}

template <typename K, typename V>
const Entry<K, V>& IteratorG<K, V>::entry() const {
    return v->elm;
}

template class IteratorG<std::string, std::string>;