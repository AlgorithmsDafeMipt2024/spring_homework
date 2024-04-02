
#include <gtest/gtest.h>

#include <cstddef>
#include <string>

#include "hash_table.hpp"

size_t CustomHashFunction(int key) { return key % 10; }
size_t CustomStringHashFunction(std::string key) { return key.size() % 17; }

TEST(HashTableTest, SimpleTest) {
  HashTable<int> table;
  ASSERT_EQ(table.Size(), 0);

  table.Insert(14);
  table.Insert(124);
  table.Insert(1);
  table.Insert(-23);
  table.Insert(54);
  table.Insert(44);
  table.Insert(0);
  table.Insert(674);

  ASSERT_EQ(table.Contains(124), true);
  ASSERT_EQ(table.Contains(44), true);
  ASSERT_EQ(table.Contains(54), true);
  ASSERT_EQ(table.Contains(0), true);
  ASSERT_EQ(table.Contains(-23), true);
  ASSERT_EQ(table.Contains(1), true);

  ASSERT_EQ(table.Size(), 8);

  table.Remove(14);
  ASSERT_EQ(table.Contains(14), false);

  table.Clear();
  ASSERT_EQ(table.Size(), 0);

  for (int i = 0; i < 100000; ++i) {
    table.Insert(i);
  }

  ASSERT_EQ(table.Contains(18353), true);
  table.Remove(18353);
  ASSERT_EQ(table.Contains(18353), false);

  table.Insert(-99999);
  ASSERT_EQ(table.Contains(-99999), true);
}

TEST(HashTableTest, CustomHashFunctionTest) {
  HashTable<int> table(CustomHashFunction);

  table.Insert(10);
  table.Insert(26);

  ASSERT_EQ(table.Contains(10), true);
  ASSERT_EQ(table.Contains(26), true);

  table.Remove(10);
  table.Remove(26);

  ASSERT_EQ(table.Contains(10), false);
  ASSERT_EQ(table.Contains(26), false);
}

TEST(HashTableTest, CollisionTest) {
  HashTable<int> table(CustomHashFunction);

  table.Insert(10);
  table.Insert(20);
  table.Insert(30);

  ASSERT_EQ(table.Contains(10), true);
  ASSERT_EQ(table.Contains(20), true);
  ASSERT_EQ(table.Contains(30), true);
}

TEST(HashTableTest, AnotherTypeTest) {
  HashTable<std::string> table(CustomStringHashFunction);

  table.Insert("Dog");
  table.Insert("Cat");
  table.Insert("Very long string");
  ASSERT_EQ(table.Contains("Dog"), true);
  ASSERT_EQ(table.Contains("Dog"), true);
  ASSERT_EQ(table.Contains("Short string"), false);

  table.Remove("Dog");
  ASSERT_EQ(table.Contains("Dog"), false);
  ASSERT_EQ(table.Size(), 2);
}