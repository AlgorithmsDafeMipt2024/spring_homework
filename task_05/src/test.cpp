
#include "sort.hpp"
#include <gtest/gtest.h>

TEST(Quick_Sort, Simple) {
  std::vector<int> vec_1{9, 8, 7, 6, 5, 4, 2, 3, 1, 0};
  ASSERT_EQ(Quick_Sort(vec_1, 0, 9),
            (std::vector<int>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}));
  std::vector<int> vec_2{10, 90, 30, 80, 60, 50};
  ASSERT_EQ(Quick_Sort(vec_2, 0, 5),
            (std::vector<int>{10, 30, 50, 60, 80, 90}));
  std::vector<int> vec_3{12,  43,  15, 26, -1233, 346, 1325,
                         -56, -12, 78, 0,  3345,  -34};
  ASSERT_EQ(Quick_Sort(vec_3, 0, 12),
            (std::vector<int>{-1233, -56, -34, -12, 0, 12, 15, 26, 43, 78, 346,
                              1325, 3345}));
}
