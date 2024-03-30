#include "utils.hpp"
#include <gtest/gtest.h>
#include <stdexcept>
#include <vector>

TEST(utils, Simple) {
  ASSERT_EQ(Sum_Of_Elements(9, std::vector<int>{1, 2, 4, 5, 6, 8, 10, 12}),
            (std::pair<int, int>{1, 8}));
  ASSERT_EQ(Sum_Of_Elements(39, std::vector<int>{1, 2, 4, 5, 6, 9, 10, 35}),
            (std::pair<int, int>{4, 35}));
  ASSERT_EQ(Sum_Of_Elements(14, std::vector<int>{1, 2, 4, 5, 6, 8, 10, 12}),
            (std::pair<int, int>{2, 12}));
  EXPECT_THROW(
      Sum_Of_Elements(187, std::vector<int>{1, 2, 4, 6, 8, 10, 12, 15}),
      std::logic_error);
  EXPECT_THROW(Sum_Of_Elements(12, std::vector<int>{0, 1, 1, 2, 2}),
               std::logic_error);
  ASSERT_EQ(Sum_Of_Elements(
                1338, std::vector<int>{10, 20, 40, 50, 60, 87, 100, 1278}),
            (std::pair<int, int>{60, 1278}));
  ASSERT_EQ(Sum_Of_Elements(22, std::vector<int>{10, 10, 11, 11, 12, 15}),
            (std::pair<int, int>{10, 12}));
  EXPECT_THROW(Sum_Of_Elements(22, std::vector<int>{11}), WrongVector);
  EXPECT_THROW(Sum_Of_Elements(1233, std::vector<int>{}), WrongVector);
}
