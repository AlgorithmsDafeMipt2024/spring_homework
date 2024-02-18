
#include <gtest/gtest.h>

#include <stdexcept>
#include <vector>

#include "utils.hpp"
TEST(utils, Simple) {
  ASSERT_EQ(FindSummands(std::vector<int>{1, 2, 3, 4, 5, 7, 8, 12}, 7),
            (std::pair<int, int>{2, 5}));
  ASSERT_EQ(FindSummands(std::vector<int>{1, 2, 3, 4, 5, 7, 8, 12}, 13),
            (std::pair<int, int>{1, 12}));
  EXPECT_THROW(FindSummands(std::vector<int>{1, 2, 3, 4, 5, 7, 8, 12}, 21),
               std::logic_error);
  EXPECT_THROW(FindSummands(std::vector<int>{1, 2, 3, 4, 5, 7, 8, 12}, -1),
               std::logic_error);
  EXPECT_THROW(FindSummands(std::vector<int>{1, 1, 1, 1}, 3), std::logic_error);
  ASSERT_EQ(FindSummands(std::vector<int>{1, 1, 1, 1}, 2),
            (std::pair<int, int>{1, 1}));
  EXPECT_THROW(FindSummands(std::vector<int>{}, 0), std::logic_error);
}
