#include <gtest/gtest.h>
#include <hashtable.h>

#include <stdexcept>

TEST(HashTableTest, Simple) {
  HashTable table;
  table.Insert(5);
  ASSERT_TRUE(table.Contains(5));

  table.Insert(14);
  ASSERT_TRUE(table.Contains(14));

  table.Insert(45);
  table.Remove(45);
  ASSERT_FALSE(table.Contains(45));

  table.Insert(41420);
  table.Clear();
  ASSERT_EQ(table.Size(), 0);

  table.Insert(245);
  table.Insert(301);
  ASSERT_EQ(table.Size(), 2);

  for (int i = 0; i < 1000; ++i) {
    table.Insert(i);
  }
  table.Clear();
  ASSERT_EQ(table.Size(), 0);

  table.Insert(5);
  table.Insert(15);
  ASSERT_TRUE(table.Contains(5));
  ASSERT_TRUE(table.Contains(15));

  for (int i = 0; i < 100; i++) table.Insert(i);
  for (int i = 0; i <= 50; i++) table.Remove(100 - i);
  for (int i = 0; i < 38; i++) table.Insert(i);
  ASSERT_EQ(table.Size(), 50);
}