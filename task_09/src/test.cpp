
#include <gtest/gtest.h>

#include "MinCoins.hpp"

TEST(MinCoins, 1) { ASSERT_EQ(MinCoins(std::vector<int>{1, 2, 5, 10}, 14), 3); }

TEST(MinCoins, 2) { ASSERT_EQ(MinCoins(std::vector<int>{1, 2, 5, 10}, 19), 4); }

TEST(MinCoins, 3) { ASSERT_EQ(MinCoins(std::vector<int>{2, 4, 6}, 13), -1); }

TEST(MinCoins, 4) { ASSERT_EQ(MinCoins(std::vector<int>{3, 4, 5, 10}, 17), 3); }