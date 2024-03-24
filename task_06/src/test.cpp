
#include <gtest/gtest.h>

#include <stdexcept>
#include <vector>

#include "k_sorted_sequence.hpp"

TEST(k_sorted_sequence, Simple) {
  std::vector<int> array_1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  ASSERT_EQ(FindSortedSequence(array_1, 4), 5);

  std::vector<int> array_2 = {-61, 20, -64, -39, 24,  -91, 28,  -69, -78,
                              7,   16, -97, -12, 29,  8,   -27, 50,  -98,
                              -37, 42, -72, -19, -25, 23,  96};
  ASSERT_EQ(FindSortedSequence(array_2, 7), -61);

  std::vector<int> array_3 = {
      75, 93, 82, 35, 79, 59,  1,  54, 84, 40, 94, 83, 81, 61, 2,  88, 92,
      70, 52, 14, 36, 33, 100, 97, 58, 17, 50, 96, 7,  53, 77, 74, 85, 38,
      34, 26, 90, 8,  55, 76,  6,  51, 63, 42, 21, 99, 67, 9,  41, 56, 64,
      25, 12, 49, 98, 44, 87,  68, 78, 28, 72, 37, 5,  31, 71, 29, 22, 91,
      13, 24, 89, 65, 80, 20,  11, 43, 19, 69, 10, 45, 16, 66, 57, 27, 32,
      86, 15, 47, 18, 30, 60,  23, 3,  46, 48, 73, 4,  95, 62, 39};
  ASSERT_EQ(FindSortedSequence(array_3, 87), 88);

  std::vector<int> array_4 = {1, 2, 3};
  EXPECT_THROW(FindSortedSequence(array_4, 3), std::out_of_range);

  std::vector<int> array_5 = {-38, -49, -60, -20, -71, 82,   -61, -56, 66,
                              -28, -89, 46,  10,  94,  98,   -25, -13, -42,
                              83,  9,   85,  33,  -62, -100, 92};
  ASSERT_EQ(FindSortedSequence(array_5, 11), -25);
}
