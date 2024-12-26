#include "DNodeG.h"
#include <string>

template <typename K, typename V>
int DNodeG<K, V>::activeNodes = 0;

template <typename K, typename V>
DNodeG<K, V>::DNodeG(const Entry<K, V>& e, DNodeG<K, V>* p, DNodeG<K, V>* n)
    : elm(e), next(n), prev(p) { 
    ++activeNodes;
}

template <typename K, typename V>
DNodeG<K, V>::~DNodeG() {
    --activeNodes;
}

template class DNodeG<std::string, std::string>;