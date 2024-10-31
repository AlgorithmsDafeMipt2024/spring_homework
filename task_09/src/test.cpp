#include <gtest/gtest.h>

#include "change_money.hpp"
TEST(ChangeCoinsTest, Simple) {
  std::vector<int> coins = {1, 2, 5};
  EXPECT_EQ(CoinExchange(11, coins), 3);
}

TEST(ChangeCoinsTest, Impossible) {
  std::vector<int> coins = {2, 3};
  EXPECT_EQ(CoinExchange(1, coins), -1);
}

TEST(ChangeCoinsTest, Zero) {
  std::vector<int> coins = {1, 2, 5};
  EXPECT_EQ(CoinExchange(0, coins), 0);
}

TEST(ChangeCoinsTest, LargeSum) {
  std::vector<int> coins = {1, 2, 5, 10, 20, 50, 100};
  EXPECT_EQ(CoinExchange(12321377, coins), 123217);
}

TEST(ChangeCoinsTest, SingleCoin) {
  std::vector<int> coins = {1};
  EXPECT_EQ(CoinExchange(5, coins), 5);
}

TEST(ChangeCoinsTest, NoCoins) {
  std::vector<int> coins = {};
  EXPECT_EQ(CoinExchange(10, coins), -1);
}

TEST(ChangeCoinsTest, LargeCoins) {
  std::vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000};
  EXPECT_EQ(CoinExchange(1279, coins), 7);
}