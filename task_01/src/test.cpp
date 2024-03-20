#include <gtest/gtest.h>

#include <vector>

#include "utils.hpp"

TEST(main, Simple) {
  ASSERT_EQ(Task1(9, std::vector<int>{1, 2, 4, 5, 6, 8, 10, 12}),
            (std::pair<int, int>{1, 8}));

  ASSERT_EQ(Task1(39, std::vector<int>{1, 2, 4, 5, 6, 9, 10, 35}),
            (std::pair<int, int>{4, 35}));
}