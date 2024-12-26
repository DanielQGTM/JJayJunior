#include "Range.h"
#include <string>

template <typename K, typename V>
Range<K, V>::Range(const IteratorG<K, V>& begin, const IteratorG<K, V>& end) : b(begin), e(end) {}

template <typename K, typename V>
const IteratorG<K, V>& Range<K, V>::getB() const {
    return b; 
}

template <typename K, typename V>
const IteratorG<K, V>& Range<K, V>::getE() const {
    return e; 
}

template class Range<std::string, std::string>;