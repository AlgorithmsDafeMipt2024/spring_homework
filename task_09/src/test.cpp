
#include <gtest/gtest.h>

#include "MinCoins.hpp"

TEST(Coins, Simple) {
  ASSERT_EQ(3, minCoins(14, (std::vector<int>{1, 2, 5, 10})));
  ASSERT_EQ(4, minCoins(19, (std::vector<int>{1, 2, 5, 10})));
  ASSERT_EQ(4, minCoins(100, std::vector<int>{1, 5, 10, 25}));
  ASSERT_EQ(10, minCoins(500, std::vector<int>{1, 5, 10, 25, 50}));
  ASSERT_EQ(-1, minCoins(3, std::vector<int>{5, 7, 9}));
  ASSERT_EQ(3, minCoins(11, std::vector<int>{2, 5, 7}));
  ASSERT_EQ(0, minCoins(0, std::vector<int>{1, 2, 5, 10}));
  ASSERT_EQ(1, minCoins(14, std::vector<int>{14}));
  ASSERT_EQ(1, minCoins(1, std::vector<int>{1}));
  ASSERT_EQ(2, minCoins(12, std::vector<int>{2, 2, 5, 10}));
  ASSERT_EQ(3, minCoins(16, std::vector<int>{1, 5, 5, 10}));
}
