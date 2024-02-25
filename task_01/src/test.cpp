
#include "utils.hpp"
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(utils, Simple) {
  ASSERT_EQ(FindSum(10, std::vector<int>{2, 3, 4, 7, 12}), (std::pair<int, int>{3,7}));
  ASSERT_EQ(FindSum(27,std::vector<int>{1,2,4,5,8,10, 13,17, 20, 21, 22, 25}), (std::pair<int, int>{2, 25}));
  ASSERT_EQ(FindSum(6, std::vector<int>{1, 5, 13, 21, 22}), (std::pair<int, int>{1, 5}));
  EXPECT_THROW(FindSum(7, std::vector<int>{1, 5, 13, 21, 22}), std::logic_error);
  EXPECT_THROW(FindSum(57, std::vector<int>{2, 3, 4, 7, 12}), std::logic_error);
  EXPECT_THROW(FindSum(-3,std::vector<int>{1,2,4,5,8,10, 13,17, 20, 21, 22, 25}), std::logic_error);
  EXPECT_THROW(FindSum(120,std::vector<int>{}),SmallVector);
  EXPECT_THROW(FindSum(47,std::vector<int>{1}),SmallVector);
}
