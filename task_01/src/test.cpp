
#include "utils.hpp"
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(utils, Simple) {
  ASSERT_EQ(Func(10, std::vector<int>{2, 3, 4, 7, 12}), (std::pair<int, int>{1,3}));
  ASSERT_EQ(Func(27,std::vector<int>{1,2,4,5,8,10, 13,17, 20, 21, 22, 25}), (std::pair<int, int>{1, 11}));
  ASSERT_EQ(Func(6, std::vector<int>{1, 5, 13, 21, 22}), (std::pair<int, int>{0, 1}));
  EXPECT_THROW(Func(7, std::vector<int>{1, 5, 13, 21, 22}), std::logic_error);
  EXPECT_THROW(Func(57, std::vector<int>{2, 3, 4, 7, 12}), std::logic_error);
  EXPECT_THROW(Func(-3,std::vector<int>{1,2,4,5,8,10, 13,17, 20, 21, 22, 25}), std::logic_error);
}
