#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "sort.hpp"

using std::string;

TEST(sort, empty) {
  std::vector<int> vector1 = {};
  std::vector<int> assert_vector1 = {};
  int* begin = &vector1[0];
  int* end = &vector1[vector1.size()];
  merge_sort(begin, end);
  ASSERT_EQ(vector1, assert_vector1);
}
TEST(sort, one_elem) {
  std::vector<int> vector2 = {1};
  std::vector<int> assert_vector2 = {1};
  int* begin = &vector2[0];
  int* end = &vector2[vector2.size()];
  merge_sort(begin, end);
  ASSERT_EQ(vector2, assert_vector2);
}

TEST(sort, two_elem) {
  std::vector<int> vector3 = {1, 2};
  std::vector<int> assert_vector3 = {1, 2};
  int* begin = &vector3[0];
  int* end = &vector3[vector3.size()];
  merge_sort(begin, end);
  ASSERT_EQ(vector3, assert_vector3);

  std::vector<int> vector4 = {2, 1};
  std::vector<int> assert_vector4 = {1, 2};
  begin = &vector4[0];
  end = &vector4[vector4.size()];
  merge_sort(begin, end);
  ASSERT_EQ(vector4, assert_vector4);
}

TEST(sort, multiple_elem) {
  std::vector<int> vector5 = {1, 3, 2, 5, 4};
  std::vector<int> assert_vector5 = {1, 2, 3, 4, 5};
  int* begin = &vector5[0];
  int* end = &vector5[vector5.size()];
  merge_sort(begin, end);
  ASSERT_EQ(vector5, assert_vector5);
}

// Test below fails to check at compile time bc of use of concepts
//
//                              |
//                              |
//                              V

/*
TEST(sort, strings) {
  std::vector<string> vector6 = {"bb", "ba", "ab", "aa"};
  std::vector<string> assert_vector6 = {"aa", "ab", "ba", "bb"};
  string* begin = &vector6[0];
  string* end = &vector6[vector6.size()];
  merge_sort(begin, end);
  ASSERT_EQ(vector6, assert_vector6);
}
*/