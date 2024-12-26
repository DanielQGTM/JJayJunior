#include "NodeDictionaryG.h"

template <typename K, typename V>
NodeDictionaryG<K, V>::NodeDictionaryG()
    : uKeys(0), n(0), header(new DNodeG<K, V>()), trailer(new DNodeG<K, V>()) {
    header->next = trailer;
    trailer->prev = header;
}

template <typename K, typename V>
NodeDictionaryG<K, V>::~NodeDictionaryG() {
    while (!empty()) erase(begin());
    delete header;
    delete trailer;
}

template <typename K, typename V>
int NodeDictionaryG<K, V>::size() const {
    return n;
}

template <typename K, typename V>
int NodeDictionaryG<K, V>::uniqueKeys() const {
    return uKeys;
}

template <typename K, typename V>
bool NodeDictionaryG<K, V>::empty() const {
    return n == 0;
}

template <typename K, typename V>
IteratorG<K, V> NodeDictionaryG<K, V>::begin() const {
    return IteratorG<K, V>(header->next);
}

template <typename K, typename V>
IteratorG<K, V> NodeDictionaryG<K, V>::end() const {
    return IteratorG<K, V>(trailer);
}

template <typename K, typename V>
IteratorG<K, V> NodeDictionaryG<K, V>::find(const K& k) const {
    auto current = header->next;
    while (current != trailer) {
        if (current->elm.getK() == k)
            return IteratorG<K, V>(current);
        current = current->next;
    }
    return end();
}

template <typename K, typename V>
IteratorG<K, V> NodeDictionaryG<K, V>::put(const K& k, const V& v) {
    auto current = header->next;
    bool isKeyUnique = true;

    while (current != trailer && current->elm.getK() <= k) {
        if (current->elm.getK() == k) {
            isKeyUnique = false;
        }
        current = current->next;
    }

    auto newNode = new DNodeG<K, V>(Entry<K, V>(k, v), current->prev, current);
    current->prev->next = newNode;
    current->prev = newNode;

    ++n; 
    if (isKeyUnique) {
        ++uKeys; 
    }

    return IteratorG<K, V>(newNode);
}

template <typename K, typename V>
void NodeDictionaryG<K, V>::erase(const K& k) {
    auto it = find(k); 
    if (it != end()) {
        erase(it); 
    }
}

template <typename K, typename V>
void NodeDictionaryG<K, V>::erase(const IteratorG<K, V>& p) {
    auto node = p.v;

    bool isLastOccurrence = (node->prev == header || node->prev->elm.getK() != node->elm.getK()) &&
                            (node->next == trailer || node->next->elm.getK() != node->elm.getK());

    node->prev->next = node->next;
    node->next->prev = node->prev;
    delete node;

    --n;
    if (isLastOccurrence) {
        --uKeys; 
    }
}

template <typename K, typename V>
void NodeDictionaryG<K, V>::erase(Range<K, V>& r) {
    auto it = r.getB();
    while (it != r.getE()) {
        auto toErase = it;
        ++it;
        erase(toErase); 
    }
}

template <typename K, typename V>
Range<K, V> NodeDictionaryG<K, V>::findAll(const K& k) const {
    auto start = find(k);
    auto end = start;
    while (end != this->end() && end.entry().getK() == k) {
        ++end;
    }
    return Range<K, V>(start, end);
}

template <typename K, typename V>
void NodeDictionaryG<K, V>::print() const {
    for (auto it = begin(); it != end(); ++it) {
        std::cout << it.entry().getK() << ": " << it.entry().getV() << std::endl;
    }
}

template <typename K, typename V>
void NodeDictionaryG<K, V>::print(const Range<K, V>& r) const {
    for (auto it = r.getB(); it != r.getE(); ++it) {
        std::cout << it.entry().getK() << ": " << it.entry().getV() << std::endl;
    }
}

template class NodeDictionaryG<std::string, std::string>;