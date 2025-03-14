#include <gtest/gtest.h>
#include <string>

// #include "dijkstras.h"
#include "../src/ladder.h"

TEST(difference, helper) {
  std::string word1 = "car";
  std::string word2 = "cat";
  std::string word3 = "chat";

  EXPECT_EQ(difference(word1, word2), 0);
  EXPECT_EQ(difference(word2, word3), 1);
}

TEST(Is, Adjacent) {
  std::string word1 = "car";
  std::string word2 = "cat";
  std::string word3 = "chat";

  std::cout << "Testing is_adjacent" << std::endl;
  EXPECT_TRUE(is_adjacent(word1, word2));
  EXPECT_TRUE(is_adjacent(word2, word3));
  EXPECT_FALSE(is_adjacent(word1, word3));
}
