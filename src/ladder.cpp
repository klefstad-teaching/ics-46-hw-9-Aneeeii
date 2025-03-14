#include "../src/ladder.h"
#include <string>

void error(std::string word1, std::string word2, std::string msg) {
    std::cout << word1 << " " << word2 << msg << std::endl;
}

bool is_adjacent(const std::string& word1, const std::string& word2) {
    // what to print if they are the same word?
    bool one_different = false;

    if (abs(word1.length() - word2.length()) > 1)
        return one_different;

    std::string shorter = word1.length() > word2.length() ? word2.length() : word1.length();

    for (int i = 0; i < shorter; ++i) {
        if (word1[i] != word2[i] && !one_different)
            one_different = true;
        else if (word1[i] != word2[i] && one_different)
            return false;
    }

    return true;
}