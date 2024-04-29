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
  EXPECT_TRUE(std::is_sorted(a.begin(), a.end()));

  std::vector<int> b{5, 3, 4, 1, 2};
  MergeSort(b);
  EXPECT_TRUE(std::is_sorted(b.begin(), b.end()));

  std::vector<int> c{5, 3, 4, 1, 2};
  QuickSort(c);
  EXPECT_TRUE(std::is_sorted(c.begin(), c.end()));
}

TEST(Sort, Empty) {
  std::vector<int> a;
  HeapSort(a);
  EXPECT_TRUE(a.empty());

  std::vector<int> b;
  MergeSort(b);
  EXPECT_TRUE(b.empty());

  std::vector<int> c;
  QuickSort(c);
  EXPECT_TRUE(c.empty());
}

TEST(Sort, Sorted) {
  std::vector<int> a{1, 2, 3, 4, 5};
  HeapSort(a);
  EXPECT_TRUE(std::is_sorted(a.begin(), a.end()));

  std::vector<int> b{1, 2, 3, 4, 5};
  MergeSort(b);
  EXPECT_TRUE(std::is_sorted(b.begin(), b.end()));

  std::vector<int> c{1, 2, 3, 4, 5};
  QuickSort(c);
  EXPECT_TRUE(std::is_sorted(c.begin(), c.end()));
}
