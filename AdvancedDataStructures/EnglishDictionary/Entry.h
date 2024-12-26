#ifndef ENTRY_H
#define ENTRY_H

template <typename K, typename V>
class Entry {
private:
    K _key;
    V _value;

public:
    Entry(K key = K(), V value = V());
    ~Entry();

    K getK() const;
    V getV() const;
    
    void setK(K key); 
    void setV(V value); 
};

#endif