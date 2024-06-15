#include <gtest/gtest.h>

#include "hash_table.hpp"

TEST(hash_table, 1) {
  HashTable hashTable(10);

  hashTable.insert(1, 100);
  hashTable.insert(2, 200);
  hashTable.insert(3, 300);

  int value;
  ASSERT_EQ(hashTable.find(2, value), true);
  ASSERT_EQ(value, 200);

  hashTable.remove(2);
  ASSERT_EQ(hashTable.find(2, value), false);

  hashTable.remove(2);
  ASSERT_EQ(hashTable.find(2, value), false);

  hashTable.insert(-1, -10);
  ASSERT_EQ(hashTable.find(-1, value), true);
  ASSERT_EQ(value, -10);
}
