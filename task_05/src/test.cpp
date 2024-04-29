// std libs:
#include <iostream>

// test lib:
#include <gtest/gtest.h>

// sort algos:
#include <heap_sort.hpp>
#include <merge_sort.hpp>
#include <quick_sort.hpp>

TEST(Sort, Simple) {
  std::vector<int> a{5, 3, 4, 1, 2};
  HeapSort(a);
  ASSERT_EQ(std::is_sorted(a.begin(), a.end()), true);

  std::vector<int> b{5, 3, 4, 1, 2};
  MergeSort(b);
  ASSERT_EQ(std::is_sorted(b.begin(), b.end()), true);

  std::vector<int> c{5, 3, 4, 1, 2};
  QuickSort(c);
  ASSERT_EQ(std::is_sorted(c.begin(), c.end()), true);
}
