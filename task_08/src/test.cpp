#include <gtest/gtest.h>

#include <hash_table.hpp>
#include <stdexcept>

TEST(HashTableTest, ContainsElement) {
  HashTable table;
  table.Insert(5);
  ASSERT_TRUE(table.Contains(5));
}

TEST(HashTableTest, InsertElement) {
  HashTable table;
  table.Insert(10);
  ASSERT_TRUE(table.Contains(10));
}

TEST(HashTableTest, RemoveElement) {
  HashTable table;
  table.Insert(15);
  table.Remove(15);
  ASSERT_FALSE(table.Contains(15));
}

TEST(HashTableTest, ClearTable) {
  HashTable table;
  table.Insert(20);
  table.Clear();
  ASSERT_EQ(table.Size(), 0);
}

TEST(HashTableTest, SizeAfterInsertion) {
  HashTable table;
  table.Insert(25);
  table.Insert(30);
  ASSERT_EQ(table.Size(), 2);
}

TEST(HashTableTest, ClearTableWithManyElements) {
  HashTable table;
  for (int i = 0; i < 100; ++i) {
    table.Insert(i);
  }
  table.Clear();
  ASSERT_EQ(table.Size(), 0);
}

TEST(HashTableTest, CollisionHandling) {
  HashTable table;
  table.Insert(5);
  table.Insert(15);
  ASSERT_TRUE(table.Contains(5));
  ASSERT_TRUE(table.Contains(15));
}

TEST(HashTableTest, SizeAfterRemoval) {
  HashTable table;
  for (int i = 0; i < 50; ++i) {
    table.Insert(i);
  }
  for (int i = 0; i < 25; ++i) {
    table.Remove(i);
  }
  table.Clear();
  ASSERT_EQ(table.Size(), 0);
}
