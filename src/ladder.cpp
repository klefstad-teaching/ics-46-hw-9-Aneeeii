#include "../src/ladder.h"
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <set>
#include <fstream>

#define my_assert(e) {std::cout << #e << ((e) ? " passed" : " failed") << std::endl;}

void error(std::string word1, std::string word2, std::string msg) {
    std::cout << word1 << " " << word2 << msg << std::endl;
}

int difference(std::string word1, std::string word2) {
    return abs(static_cast<int>(word1.length()) - static_cast<int>(word2.length()));
}

bool edit_distance_within(const std::string& str1, const std::string& str2, int d) {
    if (difference(str1, str2) > d) return false;
    
    int m = str1.length();
    int n = str2.length();
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

    for (int i = 0; i <= m; i++) dp[i][0] = i;
    for (int j = 0; j <= n; j++) dp[0][j] = j;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + std::min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
        }
    }
    return dp[m][n] <= d;
}

bool is_adjacent(const std::string& word1, const std::string& word2) {
    return edit_distance_within(word1, word2, 1);
}

std::vector<std::string> generate_word_ladder(const std::string& begin_word,
const std::string& end_word, const std::set<std::string>& word_list) {
    if (end_word == begin_word) {
        error(begin_word, end_word, "are the same word");
        return {};
    }
    std::queue<std::vector<std::string>> ladder_queue;
    std::set<std::string> visited;
    std::vector<std::string> first = {begin_word};

    ladder_queue.push(first);
    visited.insert(begin_word);

    while (!ladder_queue.empty()) {
        std::vector<std::string> ladder = ladder_queue.front();
        ladder_queue.pop();
        std::string last_word = ladder.back();
        for (std::string word : word_list) {
            if (is_adjacent(last_word, word)) {
                if (visited.find(word) == visited.end()) {
                    visited.insert(word);
                    std::vector<std::string> new_ladder = ladder;
                    new_ladder.push_back(word);
                    if (word == end_word)   
                        return new_ladder;
                    ladder_queue.push(new_ladder);
                }
            }
        }
    }

    return {};
}

void load_words(std::set<std::string>& word_list, const std::string& file_name) {
    word_list.clear();
    std::ifstream in(file_name);
    for (std::string word; (in >> word);)
        word_list.insert(word);
}

void print_word_ladder(const std::vector<std::string>& ladder) {
    if (ladder.empty())
        std::cout << "No word ladder found.\n";
    else {
        std::cout << "Word ladder found: ";
        for (std::string word : ladder)
            std::cout << word << " ";
        std::cout << std::endl;
    }
}

void verify_word_ladder() {
    std::set<std::string> word_list;
    load_words(word_list, "src/words.txt");
    my_assert(generate_word_ladder("cat", "dog", word_list).size() == 4);
    my_assert(generate_word_ladder("marty", "curls", word_list).size() == 6);
    my_assert(generate_word_ladder("code", "data", word_list).size() == 6);
    my_assert(generate_word_ladder("work", "play", word_list).size() == 6);
    my_assert(generate_word_ladder("sleep", "awake", word_list).size() == 8);
    my_assert(generate_word_ladder("car", "cheat", word_list).size() == 4);
}