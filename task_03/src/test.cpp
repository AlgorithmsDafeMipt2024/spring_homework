
#include <gtest/gtest.h>

#include "WeatherReport.h"

TEST(findNextGreater, Simple) {
  ASSERT_EQ(findNextGreater(std::vector<int>{1}), (std::vector<int>{-1}));
  ASSERT_EQ(findNextGreater(std::vector<int>{}), (std::vector<int>{}));
  ASSERT_EQ(findNextGreater(std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}),
            (std::vector<int>{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, -1}));
  ASSERT_EQ(
      findNextGreater(std::vector<int>{16, 19, 10, 14, 22, 27, 12, 10, 16, 24}),
      (std::vector<int>{{1, 3, 1, 1, 1, -1, 2, 1, 1, -1}}));
  ASSERT_EQ(findNextGreater(
                std::vector<int>{-29, 0, -7, -14, 0, -11, -13, -3, -27, -25}),
            (std::vector<int>{{1, -1, 2, 1, -1, 2, 1, -1, 1, -1}}));
}