
#include <gtest/gtest.h>

#include <vector>

#include "QuickSort.hpp"

TEST(QuickSort, Simple) {
  std::vector<int> empty;
  QuickSort<int>(empty);
  ASSERT_EQ(empty, std::vector<int>{});
  std::vector<int> data = {1, 2, 3, 4, 5};
  QuickSort<int>(data);
  ASSERT_EQ(data, (std::vector<int>{1, 2, 3, 4, 5}));
  data = (std::vector<int>{5, 4, 3, 2, 1});
  QuickSort<int>(data);
  ASSERT_EQ(data, (std::vector<int>{1, 2, 3, 4, 5}));
  data = (std::vector<int>{3, 4, 2, 1, 5});
  QuickSort<int>(data);
  ASSERT_EQ(data, (std::vector<int>{1, 2, 3, 4, 5}));
  data = (std::vector<int>{1, 1, 8, 1, 2, 2, 9, 6, 4, 3});
  QuickSort<int>(data);
  ASSERT_EQ(data, (std::vector<int>{1, 1, 1, 2, 2, 3, 4, 6, 8, 9}));
}
