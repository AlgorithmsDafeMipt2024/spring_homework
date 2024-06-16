#include <gtest/gtest.h>

#include <optional>

#include "search_task.hpp"

TEST(SearchInList, Simple) {
  std::vector<LL> list = {2, 4, 7, 9, 12, 16, 19, 23, 27};
  ASSERT_EQ(SearchInList(list, 50), std::pair(23LL, 27LL));
  ASSERT_EQ(SearchInList(list, 43), std::pair(16LL, 27LL));
  ASSERT_EQ(SearchInList(list, 21), std::pair(2LL, 19LL));
  ASSERT_EQ(SearchInList(list, 18), std::pair(2LL, 16LL));
  ASSERT_EQ(SearchInList(list, 11), std::pair(2LL, 9LL));
  ASSERT_EQ(SearchInList(list, 47), std::nullopt);
  ASSERT_EQ(SearchInList(list, 24), std::nullopt);
  ASSERT_EQ(SearchInList(list, 2), std::nullopt);
  ASSERT_EQ(SearchInList(list, 1), std::nullopt);
  ASSERT_EQ(SearchInList(list, -1421532541), std::nullopt);
  list = {};
  ASSERT_EQ(SearchInList(list, 10), std::nullopt);
  list = {1};
  ASSERT_EQ(SearchInList(list, 100), std::nullopt);
  list = {0};
  ASSERT_EQ(SearchInList(list, -142), std::nullopt);
  list = {};
  ASSERT_EQ(SearchInList(list, 0), std::nullopt);
}