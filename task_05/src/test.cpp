#include <gtest/gtest.h>

#include <vector>

#include "qsort.hpp"

TEST(Qsort, Simple1) {
  std::vector<int> vec = {77, 42, 19, 53, 18, 20};
  QuickSort<int>(vec, 0, vec.size() - 1);
  ASSERT_EQ((vec), (std::vector<int>{18, 19, 20, 42, 53, 77}));
}

TEST(Qsort, Simple2) {
  std::vector<double> vec2{12.75, 5.3, 1.1, 23.223, -13.1, 37.37};
  QuickSort<double>(vec2, 0, vec2.size() - 1);
  ASSERT_EQ((vec2),
            (std::vector<double>{-13.1, 1.1, 5.3, 12.75, 23.223, 37.37}));
}

TEST(Qsort, Simple3) {
  std::vector<int> vec3 = {-1, 2, -1, 3, 4, 5, 2};
  QuickSort<int>(vec3, 0, vec3.size() - 1);
  ASSERT_EQ((vec3), (std::vector<int>{-1, -1, 2, 2, 3, 4, 5}));
}

TEST(Qsort, Simple4) {
  std::vector<int> vec4{2, 4, 2, 1, 3, 4, 1};
  QuickSort<int>(vec4, 0, vec4.size() - 1);
  ASSERT_EQ((vec4), (std::vector<int>{1, 1, 2, 2, 3, 4, 4}));
}

TEST(Qsort, Simple5){
  std::vector<int> vec5{};
  QuickSort<int>(vec5, 0, vec5.size()-1);
  ASSERT_EQ((vec5), std::vector<int>{});
}
