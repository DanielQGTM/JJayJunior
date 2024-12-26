#include "EnglishDictionary.h"
#include <iostream>

EnglishDictionary::EnglishDictionary(const std::string& dictName)
    : name(dictName) {}

EnglishDictionary::~EnglishDictionary() {}

int EnglishDictionary::words() const {
    return dictionary.size();
}

int EnglishDictionary::uniqueWords() const {
    return dictionary.uniqueKeys();
}

bool EnglishDictionary::empty() const {
    return dictionary.empty();
}

void EnglishDictionary::add(const Entry<std::string, std::string>& entry) {
    dictionary.put(entry.getK(), entry.getV());
}

void EnglishDictionary::deleteFirst(const std::string& word) {
    auto it = dictionary.find(word);
    if (it != dictionary.end()) {
        dictionary.erase(it);
    }
}

void EnglishDictionary::deleteWord(const std::string& word) {
    auto range = dictionary.findAll(word);
    dictionary.erase(range);
}

void EnglishDictionary::printDictionary(bool forward) const {
    if (forward) {
        dictionary.print();
    } else {
        for (auto it = dictionary.end(); it != dictionary.begin(); --it) {
            std::cout << it.entry().getK() << ": " << it.entry().getV() << std::endl;
        }
    }
}

void EnglishDictionary::printDictionary(const std::string& word) const {
    auto range = dictionary.findAll(word);
    dictionary.print(range);
}

Entry<std::string, std::string> EnglishDictionary::find(const std::string& word) const {
    auto it = dictionary.find(word);
    if (it != dictionary.end()) {
        return it.entry();
    }
    throw std::runtime_error("Word not found.");
}

Range<std::string, std::string> EnglishDictionary::findAll(const std::string& word) const {
    return dictionary.findAll(word);
}