#include <gtest/gtest.h>

#include <algorithm>
#include <string>
#include <vector>

#include "sort.hpp"

using std::string;

TEST(sort, empty) {
  std::vector<int> vector1 = {};
  std::vector<int> assert_vector1 = vector1;
  std::sort(assert_vector1.begin(), assert_vector1.end());
  int* begin = &vector1[0];
  int* end = &vector1[vector1.size()];
  merge_sort(begin, end);
  ASSERT_EQ(vector1, assert_vector1);
}
TEST(sort, one_elem) {
  std::vector<int> vector2 = {1};
  std::vector<int> assert_vector2 = vector2;
  std::sort(assert_vector2.begin(), assert_vector2.end());
  int* begin = &vector2[0];
  int* end = &vector2[vector2.size()];
  merge_sort(begin, end);
  ASSERT_EQ(vector2, assert_vector2);
}

TEST(sort, two_elem) {
  std::vector<int> vector3 = {1, 2};
  std::vector<int> assert_vector3 = vector3;
  std::sort(assert_vector3.begin(), assert_vector3.end());
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

TEST(sort, multiple_elem_1) {
  std::vector<int> vector5 = {1, 3, 2, 5, 4};
  std::vector<int> assert_vector5 = vector5;
  std::sort(assert_vector5.begin(), assert_vector5.end());
  int* begin = &vector5[0];
  int* end = &vector5[vector5.size()];
  merge_sort(begin, end);
  ASSERT_EQ(vector5, assert_vector5);
}

TEST(sort, multiple_elem_2) {
  std::vector<int> vector6 = {4, 3, 2, 1};
  std::vector<int> assert_vector6 = vector6;
  std::sort(assert_vector6.begin(), assert_vector6.end());
  int* begin = &vector6[0];
  int* end = &vector6[vector6.size()];
  merge_sort(begin, end);
  ASSERT_EQ(vector6, assert_vector6);
}

TEST(sort, strings) {
  std::vector<string> vector7 = {"bb", "ba", "ab", "aa"};
  std::vector<string> assert_vector7 = vector7;
  std::sort(assert_vector7.begin(), assert_vector7.end());
  string* begin = &vector7[0];
  string* end = &vector7[vector7.size()];

  merge_sort(begin, end);

  ASSERT_EQ(vector7 == assert_vector7, true);
}