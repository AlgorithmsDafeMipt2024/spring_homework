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
  ASSERT_EQ(vector7, assert_vector7);
}

TEST(reverse_sort, multiple_elem) {
  std::vector<int> vector8 = {1, 2, 3, 4, 5};
  std::vector<int> assert_vector8 = vector8;
  std::sort(assert_vector8.begin(), assert_vector8.end(),
            [](int a, int b) { return a >= b; });
  int* begin = &vector8[0];
  int* end = &vector8[vector8.size()];
  merge_sort(begin, end, [](int a, int b) { return a >= b; });
  ASSERT_EQ(vector8, assert_vector8);
}

bool sum_comparasion(std::vector<int> a, std::vector<int> b) {
  int sum1 = 0;
  for (size_t ind = 0; ind < a.size(); ind++) sum1 += a[ind];
  int sum2 = 0;
  for (size_t ind = 0; ind < b.size(); ind++) sum2 += b[ind];
  return sum1 < sum2;
}

TEST(sum_sort, multiple_elem) {
  std::vector<std::vector<int>> vector9 = {{5, 1, 1}, {4, 4, 4}, {1, 1, 0}};
  std::vector<std::vector<int>> assert_vector9 = vector9;
  std::sort(assert_vector9.begin(), assert_vector9.end());
  std::vector<int>* begin = &vector9[0];
  std::vector<int>* end = &vector9[vector9.size()];
  merge_sort(begin, end, sum_comparasion);
  ASSERT_EQ(vector9 == assert_vector9, false);
  std::sort(assert_vector9.begin(), assert_vector9.end(), sum_comparasion);
  ASSERT_EQ(vector9 == assert_vector9, true);
}