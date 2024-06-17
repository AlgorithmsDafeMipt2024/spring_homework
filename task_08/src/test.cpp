#include <gtest/gtest.h>

#include <hash_table.hpp>
#include <stdexcept>

TEST(HashTable_Test, Test_1) {
  HashTable<int> table;
  table.Insert(1);
  ASSERT_TRUE(table.Contains(1));
  ASSERT_FALSE(table.Contains(2));
  table.Remove(1);
  ASSERT_FALSE(table.Contains(1));
}

TEST(HashTable_Test, Test_2) {
  HashTable<short> table;
  table.Insert(2);
  table.Insert(5);
  table.Insert(7);
  ASSERT_TRUE(table.Contains(2));
  ASSERT_TRUE(table.Contains(5));
  ASSERT_TRUE(table.Contains(7));
  ASSERT_EQ(table.Size(), 3);
  table.Clear();
  ASSERT_TRUE(table.Empty());
}

TEST(HashTable_Test, Test_3) {
  HashTable<double> table;
  table.Insert(10);
  table.Insert(20);
  table.Insert(30);
  ASSERT_TRUE(table.Contains(10));
  ASSERT_FALSE(table.Contains(40));
  table.Clear();
  ASSERT_EQ(table.Size(), 0);
}
