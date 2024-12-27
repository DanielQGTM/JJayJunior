#include "EnglishDictionary.h"
#include "Entry.h"
#include <iostream>

int main()
{

    EnglishDictionary dict("My English Dictionary");

    dict.add(Entry<std::string, std::string>("word1", "Definition 1a"));
    dict.add(Entry<std::string, std::string>("word1", "Definition 1b"));
    dict.add(Entry<std::string, std::string>("word1", "Definition 1c"));

    dict.add(Entry<std::string, std::string>("word2", "Definition 2a"));
    dict.add(Entry<std::string, std::string>("word2", "Definition 2b"));
    dict.add(Entry<std::string, std::string>("word2", "Definition 2c"));
    dict.add(Entry<std::string, std::string>("word2", "Definition 2d"));

    dict.add(Entry<std::string, std::string>("word3", "Definition 3"));

    dict.add(Entry<std::string, std::string>("word4", "Definition 4a"));
    dict.add(Entry<std::string, std::string>("word4", "Definition 4b"));

    // Print the list of all words and definitions starting from the beginning
    std::cout << "Dictionary (Forward):\n";
    dict.printDictionary(true);

    // Print the list of all words and definitions starting from the end
    std::cout << "\nDictionary (Backward):\n";
    dict.printDictionary(false);

    // Print the definitions for a word with 2 definitions (word4)
    std::cout << "\nDefinitions for word4 (Forward):\n";
    dict.printDictionary("word4");

    // Print the definitions for a word with 2 definitions (word4, reverse order)
    std::cout << "\nDefinitions for word4 (Backward):\n";
    Range<std::string, std::string> range4 = dict.findAll("word4");
    auto it = range4.getE();
    while (it != range4.getB())
    {
        --it;
        std::cout << it.entry().getK() << ": " << it.entry().getV() << std::endl;
    }

    // Remove the first definition of the word with 3 definitions (word1)
    std::cout << "\nRemoving the first definition of word1...\n";
    dict.deleteFirst("word1");
    dict.printDictionary(true);

    // Search for the word with 4 definitions (word2) and print them all
    std::cout << "\nDefinitions for word2:\n";
    dict.printDictionary("word2");

    // Remove the first definition of the word with 4 definitions (word2)
    std::cout << "\nRemoving the first definition of word2...\n";
    dict.deleteFirst("word2");
    dict.printDictionary("word2");

    // Remove all definitions for the word with 2 definitions (word4)
    std::cout << "\nRemoving all definitions of word4...\n";
    dict.deleteWord("word4");
    dict.printDictionary(true);

    // Print the list of all words and definitions starting from the beginning
    std::cout << "\nDictionary (Forward):\n";
    dict.printDictionary(true);

    // Print the list of all words and definitions starting from the end
    std::cout << "\nDictionary (Backward):\n";
    dict.printDictionary(false);

    return 0;
}