#include <gtest/gtest.h>

#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>

#include "merge_sort.hpp"

TEST(MergeSort, Test_1) {
  vector<int> data{2, 1, 3, 7, 5, 6, 4};
  int* begin = &(data[0]);
  int* end = &(data[data.size()]);
  MergeSort(begin, end);
  ASSERT_EQ(data, (vector<int>{1, 2, 3, 4, 5, 6, 7}));
}

TEST(MergeSort, Test_2) {
  vector<int> data{};
  int* begin = &(data[0]);
  int* end = &(data[data.size()]);
  MergeSort(begin, end);
  ASSERT_EQ(data, (vector<int>{}));
}

TEST(MergeSort, Test_3) {
  vector<int> data{1};
  int* begin = &(data[0]);
  int* end = &(data[data.size()]);
  MergeSort(begin, end);
  ASSERT_EQ(data, (vector<int>{1}));
}

TEST(MergeSort, Test_4) {
  vector<int> data{2, 1};
  int* begin = &(data[0]);
  int* end = &(data[data.size()]);
  MergeSort(begin, end);
  ASSERT_EQ(data, (vector<int>{1, 2}));
}

TEST(MergeSort, Test_5) {
  vector<int> data{20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10,
                   9,  8,  7,  6,  5,  4,  3,  2,  1,  0};
  int* begin = &(data[0]);
  int* end = &(data[data.size()]);
  MergeSort(begin, end);
  ASSERT_EQ(data, (vector<int>{0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10,
                               11, 12, 13, 14, 15, 16, 17, 18, 19, 20}));
}

TEST(MergeSort, Test_6) {
  vector<double> data{3.456, 7.890, 8.976, 4.567, 6.543, 5.432, 2.109, 9.012,
                      1.234, 6.789, 0.987, 1.234, 5.678, 4.321, 9.876, 8.765,
                      2.345, 7.654, 0.123, 3.210, 4.321, 1.234, 5.432, 9.876,
                      6.543, 8.765, 3.456, 7.890, 2.109, 0.987, 6.789, 4.567,
                      8.976, 2.345, 9.012, 7.654, 5.678, 3.210, 0.123};

  vector<double> sorted_data = data;
  std::sort(sorted_data.begin(), sorted_data.end());

  double* begin = &(data[0]);
  double* end = &(data[data.size()]);
  MergeSort(begin, end);

  ASSERT_EQ(data, sorted_data);
}

TEST(MergeSort, Test_7) {
  vector<int> data{3, 5, 3, 2, 4, 5, 7, 3, 3, 2, 1, 4, 9, 7, 5};

  vector<int> sorted_data = data;
  std::sort(sorted_data.begin(), sorted_data.end());

  int* begin = &(data[0]);
  int* end = &(data[data.size()]);
  MergeSort(begin, end);

  ASSERT_EQ(data, sorted_data);
}

TEST(MergeSort, Test_8) {
  vector<int> data{3, 5, 3, 2, 4, 5, 7, 3, 3, 2, 1, 4, 9, 7, 5};

  vector<int> sorted_data = data;
  std::sort(sorted_data.begin(), sorted_data.end());

  int* begin = &(data[0]);
  int* end = &(data[data.size()]);
  MergeSort(begin, end);

  ASSERT_EQ(data, sorted_data);
}

TEST(MergeSort, Test_9) {
  vector<int> data{18, 5, 26, 21, 7, 25, 19, 16, 9,  3,  8,  13, 27,
                   14, 2, 1,  23, 6, 29, 17, 4,  15, 11, 28, 12};

  vector<int> sorted_data = data;
  std::sort(sorted_data.begin(), sorted_data.begin() + 12);

  int* begin = &(data[0]);
  int* end = &(data[12]);
  MergeSort(begin, end);

  ASSERT_EQ(data, sorted_data);
}

TEST(MergeSort, Test_10) {
  vector<int> data{1,  2,  3,  4,  5,  1,  6,  7,  8,  9,  2,  10, 11,
                   12, 13, 14, 3,  15, 16, 17, 4,  18, 19, 20, 5,  21,
                   22, 23, 24, 1,  25, 26, 27, 28, 29, 2,  30, 31, 32,
                   33, 34, 35, 3,  36, 37, 38, 39, 40, 4,  41, 42, 43,
                   44, 45, 5,  46, 47, 48, 49, 50, 1,  51, 52, 53, 54,
                   55, 2,  56, 57, 58, 59, 60, 3,  61, 62, 63, 64, 65,
                   4,  66, 67, 68, 69, 70, 5,  71, 72, 73, 74, 75, 1};

  vector<int> sorted_data = data;
  std::sort(sorted_data.begin(), sorted_data.end());

  int* begin = &(data[0]);
  int* end = &(data[data.size()]);
  MergeSort(begin, end);

  ASSERT_EQ(data, sorted_data);
}