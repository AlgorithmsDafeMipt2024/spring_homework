#include <gtest/gtest.h>

#include "hash_table.hpp"

TEST(hash_table, 1) {
  HashTable hashTable(10);

  hashTable.Insert(1, 100);
  hashTable.Insert(2, 200);
  hashTable.Insert(3, 300);

  int value;
  ASSERT_EQ(hashTable.Find(2, value), true);
  ASSERT_EQ(value, 200);

  hashTable.Remove(2);
  ASSERT_EQ(hashTable.Find(2, value), false);

  hashTable.Remove(2);
  ASSERT_EQ(hashTable.Find(2, value), false);

  hashTable.Insert(-1, -10);
  ASSERT_EQ(hashTable.Find(-1, value), true);
  ASSERT_EQ(value, -10);
}
