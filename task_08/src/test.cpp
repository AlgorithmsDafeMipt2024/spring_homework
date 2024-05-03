#include "hashtable.hpp"
#include <gtest/gtest.h>

TEST(Hashtable, Simple) {
  HashTable table;
  table.Insert(5);
  table.Insert(17);
  table.Insert(33);
  ASSERT_EQ(table.Contains(17), true);
  ASSERT_EQ(table.Size(), 3);
  table.Remove(5);
  ASSERT_EQ(table.Contains(5),false);
}

TEST(Hashtable, EmptyTable) {
  HashTable table;
  ASSERT_EQ(table.Size(), 0);
  ASSERT_EQ(table.Contains(10), false);
}

TEST(Hashtable, RemoveNonExistentElement) {
  HashTable table;
  table.Insert(7);
  table.Remove(10);
  ASSERT_EQ(table.Size(), 1);
}

TEST(Hashtable, InsertDuplicateElement) {
  HashTable table;
  table.Insert(5);
  table.Insert(5);
  ASSERT_EQ(table.Size(), 1);
}