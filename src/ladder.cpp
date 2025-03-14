#include "../src/ladder.h"
#include <string>
#include <vector>
#include <algorithm>

void error(std::string word1, std::string word2, std::string msg) {
    std::cout << word1 << " " << word2 << msg << std::endl;
}

int difference(std::string word1, std::string word2) {
    return abs(static_cast<int>(word1.length()) - static_cast<int>(word2.length()));
}

bool is_adjacent(const std::string& word1, const std::string& word2) {
    bool one_different = false;
    if (difference(word1, word2) == 0) {
        for (size_t i = 0; i < word1.length(); ++i) {
            if (word1[i] != word2[i] && !one_different)
                one_different = true;
            else if (word1[i] != word2[i] && one_different)
                return false;
        }
        if (one_different)
            return true;
    }
    else if (difference(word1, word2) == 1) {
        std::string longer = word1.length() > word2.length()? word1 : word2;
        std::string shorter = word1 == longer ? word2 : word1;
        std::vector<char> check;
        for (char c : longer)
            check.push_back(c);

        for (char ch : shorter) {
            auto found = std::find(check.begin(), check.end(), ch);
            if (found != check.end())
                check.erase(found);
        }
        if (check.size() > 1)
            return false;
        return true;
    }
    return false;
}