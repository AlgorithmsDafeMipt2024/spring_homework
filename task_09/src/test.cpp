
#include <gtest/gtest.h>

#include <stdexcept>
#include <vector>

#include "money_to_coins.hpp"

TEST(MoneyToCoins, Simple) {
  ASSERT_EQ(MoneyToCoins(14, std::vector<size_t>{1, 2, 5, 10}), 3);
  ASSERT_EQ(MoneyToCoins(19, std::vector<size_t>{1, 2, 5, 10}), 4);
  ASSERT_EQ(MoneyToCoins(15, std::vector<size_t>{1, 7, 10}), 3);
  ASSERT_EQ(MoneyToCoins(14, std::vector<size_t>{1, 7, 10}), 2);
  ASSERT_EQ(MoneyToCoins(21, std::vector<size_t>{1, 7, 10}), 3);
  ASSERT_EQ(MoneyToCoins(34, std::vector<size_t>{1, 7, 10}), 4);
}

TEST(MoneyToCoins, Empty) {
  ASSERT_THROW(MoneyToCoins(14, std::vector<size_t>{}), std::runtime_error);
  ASSERT_EQ(MoneyToCoins(0, std::vector<size_t>{1, 2, 5, 10}), 0);
}