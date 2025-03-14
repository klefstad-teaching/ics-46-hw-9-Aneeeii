#include "../src/ladder.h"
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <set>

void error(std::string word1, std::string word2, std::string msg) {
    std::cout << word1 << " " << word2 << msg << std::endl;
}

int difference(std::string word1, std::string word2) {
    return abs(static_cast<int>(word1.length()) - static_cast<int>(word2.length()));
}

bool is_adjacent(const std::string& word1, const std::string& word2) {
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

std::vector<std::string> generate_word_ladder(const std::string& begin_word,
const std::string& end_word, std::set<std::string>& word_list) {
    std::queue<std::string> ladder_queue;
    ladder_queue.push(begin_word);
    std::set<std::string> visited;
    visited.insert(begin_word);
    for (std::string word : word_list) {
        std::string last_word = ladder_queue.back();
        if (is_adjacent(word, last_word)) {
            if (visited.find(word) == visited.end()) {
                visited.insert(word);
                ladder_queue.push(word);
            }
        }
        if (ladder_queue.back() == end_word)
            break;
    }
    return ladder_queue;
}