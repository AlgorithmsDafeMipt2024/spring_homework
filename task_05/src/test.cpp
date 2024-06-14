#include <gtest/gtest.h>

#include <merge_sort.hpp>

TEST(SortAlgos, Simple_Int) {
  std::vector<int> a1{5, 3, 4, 1, 2};
  MergeSort(&a1[0], &a1[a1.size()]);
  EXPECT_TRUE(std::is_sorted(&a1[0], &a1[a1.size()]));

  std::vector<int> a2{7, 7, -10, -9, 2, 5, -5};
  MergeSort(&a2[0], &a2[a2.size()]);
  EXPECT_TRUE(std::is_sorted(&a2[0], &a2[a2.size()]));

  std::vector<int> a3{3, 9, 3, -3, 1, 0, -3, -5, 0};
  MergeSort(&a3[0], &a3[a3.size()]);
  EXPECT_TRUE(std::is_sorted(&a3[0], &a3[a3.size()]));

  std::vector<int> a4{3, -3, 3, -3, 3, 3, -3, -3};
  MergeSort(&a4[0], &a4[a4.size()]);
  EXPECT_TRUE(std::is_sorted(&a4[0], &a4[a4.size()]));

  std::vector<int> a5{5, 4, 3, 2, 1};
  MergeSort(&a5[0], &a5[a5.size()]);
  EXPECT_TRUE(std::is_sorted(&a5[0], &a5[a5.size()]));
}

TEST(SortAlgos, Empty) {
  std::vector<int> a;
  MergeSort(&a[0], &a[a.size()]);
  EXPECT_TRUE(a.empty());
}

TEST(SortAlgos, Sorted) {
  std::vector<int> a{1, 2, 3, 4, 5};
  MergeSort(&a[0], &a[a.size()]);
  EXPECT_TRUE(std::is_sorted(&a[0], &a[a.size()]));
}

TEST(SortAlgos, Double) {
  std::vector<double> a{-9.4, -8.4, 8.7, 4.3, 5.8, 0.4};
  MergeSort(&a[0], &a[a.size()]);
  EXPECT_TRUE(std::is_sorted(&a[0], &a[a.size()]));

  std::vector<double> a2{-7.1, 0.3, 9.3, 9.6, -0.0, -3.2, 4.3, -9.2, 8.6, 2.7};
  MergeSort(&a2[0], &a2[a2.size()]);
  EXPECT_TRUE(std::is_sorted(&a2[0], &a2[a2.size()]));

  std::vector<double> a3{0.4, -6.2, 2.7, 6.9, -7.1, -1.5, 8.9, 5.8, 2.1};
  MergeSort(&a3[0], &a3[a3.size()]);
  EXPECT_TRUE(std::is_sorted(&a3[0], &a3[a3.size()]));

  std::vector<double> a4{5.2,  -8.8, 3.6,  2.3,  9.5, 2.5,
                         -7.5, 5.0,  -1.2, -3.8, -1.1};
  MergeSort(&a4[0], &a4[a4.size()]);
  EXPECT_TRUE(std::is_sorted(&a4[0], &a4[a4.size()]));

  std::vector<double> a5{50.1, 6.4, 8.7,  5.4,  9.1, -5.9, -4.8, -8.7, 5.6,
                         8.4,  0.5, -0.7, -7.1, 3.7, -3.3, -7.8, -2.1};
  MergeSort(&a5[0], &a5[a5.size()]);
  EXPECT_TRUE(std::is_sorted(&a5[0], &a5[a5.size()]));
}

TEST(SortAlgos, Strings) {
  std::vector<std::string> a{"a", "b", "c", "d", "e"};
  MergeSort(&a[0], &a[a.size()]);
  EXPECT_TRUE(std::is_sorted(&a[0], &a[a.size()]));
}

TEST(SortAlgos, Duplicates) {
  std::vector<int> a{5, 3, 4, 1, 2, 3, 1, 4};
  MergeSort(&a[0], &a[a.size()]);
  EXPECT_TRUE(std::is_sorted(&a[0], &a[a.size()]));
}

TEST(SortAlgos, Characters) {
  std::vector<char> a{'e', 'a', 'c', 'a', 'd'};
  MergeSort(&a[0], &a[a.size()]);
  EXPECT_TRUE(std::is_sorted(&a[0], &a[a.size()]));
}
