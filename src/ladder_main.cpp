#include <fstream>
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include "../src/ladder.h"

int main() {
    std::cout << "Please input 2 words separated by a space:" << std::endl;
    std::string word1;
    std::string word2;
    std::cin >> word1;
    std::cin >> word2;

    std::set<std::string> word_list;
    std::vector<std::string> ladder;
    load_words(word_list, "src/words.txt");
    ladder = generate_word_ladder(word1, word2, word_list);
    print_word_ladder(ladder);

    return 0;
}