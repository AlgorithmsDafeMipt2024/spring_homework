#include <gtest/gtest.h>

#include <algorithm>
#include <string>
#include <type_traits>
#include <vector>

#include "sort.hpp"

using std::string;

TEST(sort, simple_1) {
  std::vector<int> vector = {6, 10};
  std::vector<int> test = vector;
  std::sort(test.begin(), test.end());
  int* begin = &vector[0];
  int* end = &vector[vector.size()];
  MergeSort(begin, end);
  ASSERT_EQ(vector, test);
}

TEST(sort, already_sorted) {
  std::vector<int> vector = {1, 2, 3, 4};
  std::vector<int> test = vector;
  std::sort(test.begin(), test.end());
  int* begin = &vector[0];
  int* end = &vector[vector.size()];
  MergeSort(begin, end);
  ASSERT_EQ(vector, test);
}

TEST(sort, multiple_1) {
  std::vector<int> vector = {5, 6, 10, 25, 1, 4, 6, 8, 10, 10, 10};
  std::vector<int> test = vector;
  std::sort(test.begin(), test.end());
  int* begin = &vector[0];
  int* end = &vector[vector.size()];
  MergeSort(begin, end);
  ASSERT_EQ(vector, test);
}

TEST(sort, multiple_2) {
  std::vector<int> vector = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  std::vector<int> test = vector;
  std::sort(test.begin(), test.end());
  int* begin = &vector[0];
  int* end = &vector[vector.size()];
  MergeSort(begin, end);
  ASSERT_EQ(vector, test);
}

TEST(sort, empty) {
  std::vector<int> vector = {};
  std::vector<int> test = vector;
  std::sort(test.begin(), test.end());
  int* begin = &vector[0];
  int* end = &vector[vector.size()];
  MergeSort(begin, end);
  ASSERT_EQ(vector, test);
}

TEST(sort, one_elem) {
  std::vector<int> vector = {1};
  std::vector<int> test = vector;
  std::sort(test.begin(), test.end());
  int* begin = &vector[0];
  int* end = &vector[vector.size()];
  MergeSort(begin, end);
  ASSERT_EQ(vector, test);
}