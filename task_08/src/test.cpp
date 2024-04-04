
#include <gtest/gtest.h>

#include <algorithm>

#include "hashtable.hpp"

TEST(hashtable, simple) {
  HashTable<int, int> hash_table_1;
  std::vector<int> assert_vector_1;

  for (int i = 1; i <= 64; i++) {
    hash_table_1[i] = i * i;
    assert_vector_1.push_back(i * i);
  }

  std::vector<int> assert_vector_2;
  for (int i = 1; i <= 64; i++) assert_vector_2.push_back(hash_table_1[i]);

  std::vector<int> assert_vector_3 = hash_table_1.values();
  std::sort(assert_vector_3.begin(), assert_vector_3.end());

  // check if we don't lose any data when inserting into hash_table
  ASSERT_EQ(assert_vector_1, assert_vector_2);
  ASSERT_EQ(assert_vector_1, assert_vector_3);

  for (int i = 17; i <= 64; i++) hash_table_1.pop(i);

  std::vector<int> assert_vector_4;
  std::vector<int> assert_vector_5;

  for (int i = 1; i <= 16; i++) {
    assert_vector_4.push_back(i * i);
    assert_vector_5.push_back((hash_table_1[i]));
  }

  std::vector<int> assert_vector_6 = hash_table_1.values();
  std::sort(assert_vector_6.begin(), assert_vector_6.end());

  // check if we don't lose any data when deleting elements from hash_table
  ASSERT_EQ(assert_vector_4, assert_vector_5);
  ASSERT_EQ(assert_vector_4, assert_vector_6);

  std::vector<bool> assert_vector_7;
  std::vector<bool> assert_vector_8;

  for (int i = 1; i <= 16; i++) {
    assert_vector_7.push_back(hash_table_1.has_key(i));
    assert_vector_8.push_back(true);
  }

  for (int i = 17; i <= 64; i++) {
    assert_vector_7.push_back(hash_table_1.has_key(i));
    assert_vector_8.push_back(false);
  }

  // check if don't have "phantom" elements after deletion
  ASSERT_EQ(assert_vector_7, assert_vector_8);

  hash_table_1.clear();

  std::vector<bool> assert_vector_9;
  std::vector<bool> assert_vector_10;

  for (int i = 1; i <= 64; i++) {
    assert_vector_9.push_back(hash_table_1.has_key(i));
    assert_vector_10.push_back(false);
  }

  // check the method "clear()"
  ASSERT_EQ(assert_vector_9, assert_vector_10);

  hash_table_1.set_default(16);

  std::vector<int> assert_vector_11;
  std::vector<int> assert_vector_12;

  for (int i = 1; i <= 16; i++) {
    assert_vector_11.push_back(hash_table_1[i]);
    assert_vector_12.push_back(16);
  }

  // check default value
  ASSERT_EQ(assert_vector_11, assert_vector_12);
}