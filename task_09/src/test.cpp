#include <gtest/gtest.h>

#include "min_amount_of_coins.h"

TEST(MinAmountOfCoins, Simple) {
  ASSERT_EQ(MinAmountOfCoins(14, std::vector<size_t>{1, 2, 5, 10}), 3);
  ASSERT_EQ(MinAmountOfCoins(19, std::vector<size_t>{1, 2, 5, 10}), 4);
  ASSERT_EQ(MinAmountOfCoins(15, std::vector<size_t>{1, 7, 10}), 3);
  ASSERT_EQ(MinAmountOfCoins(14, std::vector<size_t>{1, 7, 10}), 2);
  ASSERT_EQ(MinAmountOfCoins(21, std::vector<size_t>{1, 7, 10}), 3);
  ASSERT_EQ(MinAmountOfCoins(34, std::vector<size_t>{1, 7, 10}), 4);
  ASSERT_THROW(MinAmountOfCoins(14, std::vector<size_t>{}), std::runtime_error);
  ASSERT_EQ(MinAmountOfCoins(0, std::vector<size_t>{1, 2, 5, 10}), 0);
}