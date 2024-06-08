
#include <gtest/gtest.h>

#include <string>

#include "hash_table.hpp"

TEST(HashTable, Simple) {
  HashTable<std::string> table;
  table.add("qwert");
  table.add("niyaz");
  ASSERT_EQ(table.find("niyaz"), true);
  ASSERT_EQ(table.find("qwert"), true);
  ASSERT_EQ(table.find("aaaaaaaa"), false);
}

TEST(HashTable, Empty) {
  HashTable<std::string> table;
  ASSERT_EQ(table.find("qwert"), false);
}
