#include "Entry.h"
#include <string>

template <typename K, typename V>
Entry<K, V>::Entry(K key, V value) : _key(key), _value(value) {}

template <typename K, typename V>
Entry<K, V>::~Entry() {}

template <typename K, typename V>
K Entry<K, V>::getK() const
{
    return _key;
}

template <typename K, typename V>
V Entry<K, V>::getV() const
{
    return _value;
}

template <typename K, typename V>
void Entry<K, V>::setK(K key)
{
    _key = key;
}

template <typename K, typename V>
void Entry<K, V>::setV(V value)
{
    _value = value;
}

template class Entry<std::string, std::string>;