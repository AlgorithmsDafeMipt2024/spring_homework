#include <gtest/gtest.h>

#include "topology_sort.hpp"

TEST(MySearch, Simple) {
  std::vector<int> list = {2, 4, 7, 9, 12, 16, 19, 23, 27};
  ASSERT_EQ(MySearch(list, 50), std::tuple(23, 27));
  ASSERT_EQ(MySearch(list, 43), std::tuple(16, 27));
  ASSERT_EQ(MySearch(list, 47), std::tuple(-1, -1));
  ASSERT_EQ(MySearch(list, 24), std::tuple(-1, -1));
  ASSERT_EQ(MySearch(list, 21), std::tuple(2, 19));
  ASSERT_EQ(MySearch(list, 18), std::tuple(2, 16));
  ASSERT_EQ(MySearch(list, 11), std::tuple(2, 9));
  ASSERT_EQ(MySearch(list, 2), std::tuple(-1, -1));
}