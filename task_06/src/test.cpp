
#include <gtest/gtest.h>

#include <stdexcept>
#include <vector>

#include "k_sorted_sequence.hpp"

TEST(k_sorted_sequence, EmptyArray) {
  std::vector<int> array = {};
  EXPECT_THROW(FindSortedSequence(array, 1), std::out_of_range);
}

TEST(k_sorted_sequence, SingleElementArray) {
  std::vector<int> array = {42};
  ASSERT_EQ(FindSortedSequence(array, 0), 42);
}

TEST(k_sorted_sequence, NegativeNumbers) {
  std::vector<int> array = {-5, -3, -8, -1, -10, -2, -6, -4, -7, -9};
  ASSERT_EQ(FindSortedSequence(array, 4), -6);
}

TEST(k_sorted_sequence, SmallRandomArray) {
  std::vector<int> array = {-61, 20, -64, -39, 24,  -91, 28,  -69, -78,
                            7,   16, -97, -12, 29,  8,   -27, 50,  -98,
                            -37, 42, -72, -19, -25, 23,  96};
  ASSERT_EQ(FindSortedSequence(array, 7), -61);
}

TEST(k_sorted_sequence, LargeRandomArray) {
  std::vector<int> array = {
      75, 93, 82, 35, 79, 59,  1,  54, 84, 40, 94, 83, 81, 61, 2,  88, 92,
      70, 52, 14, 36, 33, 100, 97, 58, 17, 50, 96, 7,  53, 77, 74, 85, 38,
      34, 26, 90, 8,  55, 76,  6,  51, 63, 42, 21, 99, 67, 9,  41, 56, 64,
      25, 12, 49, 98, 44, 87,  68, 78, 28, 72, 37, 5,  31, 71, 29, 22, 91,
      13, 24, 89, 65, 80, 20,  11, 43, 19, 69, 10, 45, 16, 66, 57, 27, 32,
      86, 15, 47, 18, 30, 60,  23, 3,  46, 48, 73, 4,  95, 62, 39};
  ASSERT_EQ(FindSortedSequence(array, 87), 88);
}
