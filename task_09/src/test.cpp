#include <gtest/gtest.h>

#include "min_amount_of_coins.h"

TEST(MinAmountOfCoins, Simple) {
  std::vector<size_t> coins_1{1, 2, 5, 10};
  std::vector<size_t> coins_2{1, 7, 10};
  ASSERT_EQ(MinAmountOfCoins(14, coins_1), 3);
  ASSERT_EQ(MinAmountOfCoins(19, coins_1), 4);
  ASSERT_EQ(MinAmountOfCoins(15, coins_2), 3);
  ASSERT_EQ(MinAmountOfCoins(14, coins_2), 2);
  ASSERT_EQ(MinAmountOfCoins(21, coins_2), 3);
  ASSERT_EQ(MinAmountOfCoins(34, coins_2), 4);
  ASSERT_THROW(MinAmountOfCoins(14, std::vector<size_t>{}), std::runtime_error);
  ASSERT_EQ(MinAmountOfCoins(0, coins_1), 0);
}