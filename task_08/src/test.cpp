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
  table.Insert(14);
  ASSERT_TRUE(table.Contains(14));
}

TEST(HashTableTest, RemoveElement) {
  HashTable table;
  table.Insert(45);
  table.Remove(45);
  ASSERT_FALSE(table.Contains(45));
}

TEST(HashTableTest, ClearTable) {
  HashTable table;
  table.Insert(41420);
  table.Clear();
  ASSERT_EQ(table.Size(), 0);
}

TEST(HashTableTest, SizeAfterInsertion) {
  HashTable table;
  table.Insert(245);
  table.Insert(301);
  ASSERT_EQ(table.Size(), 2);
}

TEST(HashTableTest, ClearTableWithManyElements) {
  HashTable table;
  for (int i = 0; i < 1000; ++i) {
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
TEST(HashTableTest, ADD100Delete50Rehash) {
  HashTable table;
  for (int i = 0; i < 100; i++) table.Insert(i);
  for (int i = 0; i <= 50; i++) table.Remove(100 - i);
  for (int i = 0; i < 38; i++) table.Insert(i);
  ASSERT_EQ(table.Size(), 50);
}