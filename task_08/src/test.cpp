
#include <gtest/gtest.h>

#include "hash_table.hpp"

TEST(HashTable, Simple) {
  HashTable table;

  ASSERT_EQ(table.Find("adasdaw"), false);
  ASSERT_EQ(table.Find(""), false);

  ASSERT_EQ(table.Add("abcd"), true);
  ASSERT_EQ(table.Add("abcd"), false);
  ASSERT_EQ(table.Add("bcda"), true);
  ASSERT_EQ(table.Add("cdab"), true);
  ASSERT_EQ(table.Add("dabc"), true);

  ASSERT_EQ(table.Find("abcd"), true);
  ASSERT_EQ(table.Find("BCDA"), false);
  ASSERT_EQ(table.Remove("dabc"), true);
  ASSERT_EQ(table.Find("dabc"), false);
  ASSERT_EQ(table.Remove("DDDD"), false);
  ASSERT_EQ(table.Find("DDDD"), false);
  ASSERT_EQ(table.Add("abcd"), false);
  ASSERT_EQ(table.Find("abcd"), true);
}
