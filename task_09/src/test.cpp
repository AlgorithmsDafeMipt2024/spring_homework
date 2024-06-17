
#include <gtest/gtest.h>

#include <vector>
#include <stdexcept>

#include "min_amount_of_coins.hpp"

using namespace std;

TEST(MinAmountOfCoins, Test_1) {
  vector<unsigned> coins{1, 2, 5, 10};
  ASSERT_EQ(MinAmountOfCoins(coins, 20), 2);
}

TEST(MinAmountOfCoins, Test_2) {
  vector<unsigned> coins{1, 2, 5, 10};
  ASSERT_EQ(MinAmountOfCoins(coins, 21), 3);
}

TEST(MinAmountOfCoins, Test_3) {
  vector<unsigned> coins{1, 3, 5, 7};
  ASSERT_EQ(MinAmountOfCoins(coins, 18), 4);
}

TEST(MinAmountOfCoins, Test_4) {
  vector<unsigned> coins{3, 5, 7};
  EXPECT_THROW(MinAmountOfCoins(coins, 2), std::logic_error);
}

TEST(MinAmountOfCoins, Test_5) {
  vector<unsigned> coins{1, 2, 4, 5};
  ASSERT_EQ(MinAmountOfCoins(coins, 8), 2);
}

TEST(MinAmountOfCoins, Test_6) {
  vector<unsigned> coins{1, 2, 5, 10};
  ASSERT_EQ(MinAmountOfCoins(coins, 28), 5);
}