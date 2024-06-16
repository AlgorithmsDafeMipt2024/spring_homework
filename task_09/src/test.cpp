
#include <gtest/gtest.h>

#include "MinimumCoinsAmount.hpp"

TEST(ChangeCoinsTest, Simple1) {
  std::vector<int> coins = {1, 2, 5};
  EXPECT_EQ(MinimumCoinsAmount(11, coins), 3);
}

TEST(ChangeCoinsTest, Simple2) {
  std::vector<int> coins = {1, 2, 5, 7, 10};
  EXPECT_EQ(MinimumCoinsAmount(15, coins), 2);
  EXPECT_EQ(MinimumCoinsAmount(14, coins), 2);
  EXPECT_EQ(MinimumCoinsAmount(13, coins), 3);
  EXPECT_EQ(MinimumCoinsAmount(114, coins), 12);
  EXPECT_EQ(MinimumCoinsAmount(11, coins), 2);
  EXPECT_EQ(MinimumCoinsAmount(5, coins), 1);
}

TEST(ChangeCoinsTest, ImpossibleTest) {
  std::vector<int> coins = {2, 3};
  EXPECT_EQ(MinimumCoinsAmount(1, coins), -1);
}

TEST(ChangeCoinsTest, ZeroTest) {
  std::vector<int> coins = {1, 2, 5};
  EXPECT_EQ(MinimumCoinsAmount(0, coins), 0);
}

TEST(ChangeCoinsTest, LargeSumTest) {
  std::vector<int> coins = {1, 2, 5, 10, 20, 50, 100};
  EXPECT_EQ(MinimumCoinsAmount(35891468, coins), 358919);
}

TEST(ChangeCoinsTest, SingleCoinTest) {
  std::vector<int> coins = {1};
  EXPECT_EQ(MinimumCoinsAmount(5, coins), 5);
}

TEST(ChangeCoinsTest, NoCoinsTest) {
  std::vector<int> coins = {};
  EXPECT_EQ(MinimumCoinsAmount(10, coins), -1);
}

TEST(ChangeCoinsTest, LargeCoinsTest) {
  std::vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000};
  EXPECT_EQ(MinimumCoinsAmount(1279, coins), 7);
}