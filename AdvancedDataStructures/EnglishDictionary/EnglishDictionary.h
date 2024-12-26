#ifndef ENGLISHDICTIONARY_H
#define ENGLISHDICTIONARY_H

#include "NodeDictionaryG.h"
#include <string>

class EnglishDictionary {
private:
    std::string name;
    NodeDictionaryG<std::string, std::string> dictionary;

public:
    EnglishDictionary(const std::string& dictName);
    ~EnglishDictionary();

    int words() const;
    int uniqueWords() const;
    bool empty() const;

    void add(const Entry<std::string, std::string>& entry);
    void deleteFirst(const std::string& word);
    void deleteWord(const std::string& word);
    void printDictionary(bool forward) const;
    void printDictionary(const std::string& word) const;
    Entry<std::string, std::string> find(const std::string& word) const;
    Range<std::string, std::string> findAll(const std::string& word) const;
};

#endif