
#include <gtest/gtest.h>

#include <vector>

#include "quickSort.hpp"

TEST(quickSort, Simple) {
  std::vector<int> data = {1, 2, 3, 4, 5};
  quickSort<int>(data);
  for (auto curr : data) std::cout << curr << " ";
  ASSERT_EQ(data, (std::vector<int>{1, 2, 3, 4, 5}));
  data = (std::vector<int>{5, 4, 3, 2, 1});
  quickSort<int>(data);
  ASSERT_EQ(data, (std::vector<int>{1, 2, 3, 4, 5}));
  data = (std::vector<int>{3, 4, 2, 1, 5});
  quickSort<int>(data);
  ASSERT_EQ(data, (std::vector<int>{1, 2, 3, 4, 5}));
  data = (std::vector<int>{1, 1, 8, 1, 2, 2, 9, 6, 4, 3});
  quickSort<int>(data);
  ASSERT_EQ(data, (std::vector<int>{1, 1, 1, 2, 2, 3, 4, 6, 8, 9}));
}
