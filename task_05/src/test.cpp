
#include <gtest/gtest.h>

#include "quick_sort.hpp"

TEST(Sort, test1) {
  std::vector<double> a{5.34, 3.11, 4.41515215, -4151.51, 2.00001};
  QuickSort(a);
  EXPECT_TRUE(std::is_sorted(a.begin(), a.end()));

  std::vector<int> b;
  QuickSort(b);
  EXPECT_TRUE(b.empty());

  std::vector<int> c{-114, -452, -3, -455, -511};
  QuickSort(c);
  EXPECT_TRUE(std::is_sorted(c.begin(), c.end()));

  std::vector<double> d{-5.3, 3.1, 4.7, 1.2, -2.8};
  QuickSort(d);
  EXPECT_TRUE(std::is_sorted(d.begin(), d.end()));

  std::vector<int> e{51, 3, -414, 1, 2, 34, 1, 4};
  QuickSort(e);
  EXPECT_TRUE(std::is_sorted(e.begin(), e.end()));
}