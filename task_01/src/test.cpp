#include <gtest/gtest.h>

#include "utils.hpp"

TEST(MySearch, Simple) {
  std::vector<LL> list = {2, 4, 7, 9, 12, 16, 19, 23, 27};
  ASSERT_EQ(MySearch(list, 50), std::pair(23LL, 27LL));
  ASSERT_EQ(MySearch(list, 43), std::pair(16LL, 27LL));
  ASSERT_EQ(MySearch(list, 21), std::pair(2LL, 19LL));
  ASSERT_EQ(MySearch(list, 18), std::pair(2LL, 16LL));
  ASSERT_EQ(MySearch(list, 11), std::pair(2LL, 9LL));
  ASSERT_EQ(MySearch(list, 47), std::nullopt);
  ASSERT_EQ(MySearch(list, 24), std::nullopt);
  ASSERT_EQ(MySearch(list, 2), std::nullopt);
  ASSERT_EQ(MySearch(list, 1), std::nullopt);
  ASSERT_EQ(MySearch(list, -1421532541), std::nullopt);
  list = {};
  ASSERT_EQ(MySearch(list, 10), std::nullopt);
}