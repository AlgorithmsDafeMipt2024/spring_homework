
#include <gtest/gtest.h>

#include <vector>

#include "sorts.hpp"

TEST(Sorts, Simple) {
  SORT sort;

  std::vector<int> temp;

  std::vector<int> list1 = {1, 2, 6, 5, 3, 4};
  std::vector<int> list2 = {0, 5, 0, -1, -2, -3, 10, 7};
  std::vector<int> list3 = {};
  std::vector<int> list4 = {0};

  // HEAPSORT
  // -----------------------------------------------------------------
  ASSERT_EQ(sort.heapsorted(list1), std::vector<int>({1, 2, 3, 4, 5, 6}));
  ASSERT_EQ(list1, std::vector<int>({1, 2, 6, 5, 3, 4}));

  temp = list2;
  sort.heapsort(temp);
  ASSERT_EQ(temp, std::vector<int>({-3, -2, -1, 0, 0, 5, 7, 10}));
  ASSERT_EQ(list2, std::vector<int>({0, 5, 0, -1, -2, -3, 10, 7}));

  ASSERT_EQ(sort.heapsorted(list3), std::vector<int>());
  ASSERT_EQ(list3, std::vector<int>({}));

  sort.heapsort(list4);
  ASSERT_EQ(list4, std::vector<int>({0}));

  // QUICK SORT
  // -----------------------------------------------------------------
  ASSERT_EQ(sort.quicksorted(list1), std::vector<int>({1, 2, 3, 4, 5, 6}));
  ASSERT_EQ(list1, std::vector<int>({1, 2, 6, 5, 3, 4}));

  temp = list2;
  sort.quicksort(temp);
  ASSERT_EQ(temp, std::vector<int>({-3, -2, -1, 0, 0, 5, 7, 10}));
  ASSERT_EQ(list2, std::vector<int>({0, 5, 0, -1, -2, -3, 10, 7}));

  ASSERT_EQ(sort.quicksorted(list3), std::vector<int>());
  ASSERT_EQ(list3, std::vector<int>({}));

  sort.quicksort(list4);
  ASSERT_EQ(list4, std::vector<int>({0}));

  // MERGE SORT
  // -----------------------------------------------------------------
  ASSERT_EQ(sort.mergesorted(list1), std::vector<int>({1, 2, 3, 4, 5, 6}));
  ASSERT_EQ(list1, std::vector<int>({1, 2, 6, 5, 3, 4}));

  temp = list2;
  sort.mergesort(temp);
  ASSERT_EQ(temp, std::vector<int>({-3, -2, -1, 0, 0, 5, 7, 10}));
  ASSERT_EQ(list2, std::vector<int>({0, 5, 0, -1, -2, -3, 10, 7}));

  ASSERT_EQ(sort.mergesorted(list3), std::vector<int>());
  ASSERT_EQ(list3, std::vector<int>({}));

  sort.mergesort(list4);
  ASSERT_EQ(list4, std::vector<int>({0}));
}
