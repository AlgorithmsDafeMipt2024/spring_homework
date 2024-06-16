
#include <gtest/gtest.h>

#include "MinCoins.hpp"

TEST(Coins, Simple) {
  ASSERT_EQ(3, MinCoins(14, (std::vector<int>{1, 2, 5, 10})));
  ASSERT_EQ(4, MinCoins(19, (std::vector<int>{1, 2, 5, 10})));
  ASSERT_EQ(4, MinCoins(100, std::vector<int>{1, 5, 10, 25}));
  ASSERT_EQ(10, MinCoins(500, std::vector<int>{1, 5, 10, 25, 50}));
  ASSERT_EQ(-1, MinCoins(3, std::vector<int>{5, 7, 9}));
  ASSERT_EQ(3, MinCoins(11, std::vector<int>{2, 5, 7}));
  ASSERT_EQ(0, MinCoins(0, std::vector<int>{1, 2, 5, 10}));
  ASSERT_EQ(1, MinCoins(14, std::vector<int>{14}));
  ASSERT_EQ(1, MinCoins(1, std::vector<int>{1}));
  ASSERT_EQ(2, MinCoins(12, std::vector<int>{2, 2, 5, 10}));
  ASSERT_EQ(3, MinCoins(16, std::vector<int>{1, 5, 5, 10}));
}
