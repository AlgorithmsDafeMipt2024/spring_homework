#include <gtest/gtest.h>

#include <numeric>

#include "bogo_sort.hpp"
#include "bubble_sort.hpp"
#include "insertion_sort.hpp"
#include "merge_sort.hpp"
#include "quick_sort.hpp"
#include "selection_sort.hpp"

// tests for quick sort
TEST(Quick_Sort, Simple) {
  std::vector<int> vec1{9, 8, 7, 6, 5, 4, 2, 3, 1, 0};
  ASSERT_EQ(QuickSort(vec1), (std::vector<int>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}));
  std::vector<int> vec2{10, 90, 30, 80, 60, 50};
  ASSERT_EQ(QuickSort(vec2), (std::vector<int>{10, 30, 50, 60, 80, 90}));
  std::vector<int> vec3{12,  43,  15, 26, -1233, 346, 1325,
                        -56, -12, 78, 0,  3345,  -34};
  ASSERT_EQ(QuickSort(vec3), (std::vector<int>{-1233, -56, -34, -12, 0, 12, 15,
                                               26, 43, 78, 346, 1325, 3345}));
  vec3.push_back(-10);
  vec3.push_back(1000);
  vec3.push_back(5);
  ASSERT_EQ(QuickSort(vec3),
            (std::vector<int>{-1233, -56, -34, -12, -10, 0, 5, 12, 15, 26, 43,
                              78, 346, 1000, 1325, 3345}));
}

TEST(Quick_Sort, EmptyVector) {
  std::vector<int> vec;
  ASSERT_EQ(QuickSort(vec), (std::vector<int>{}));
}

TEST(Quick_Sort, SingleElement) {
  std::vector<int> vec{1};
  ASSERT_EQ(QuickSort(vec), (std::vector<int>{1}));
}

TEST(Quick_Sort, RepeatedElements) {
  std::vector<int> vec{5, 5, 5, 5};
  ASSERT_EQ(QuickSort(vec), (std::vector<int>{5, 5, 5, 5}));
}

TEST(Quick_Sort, MixedNumbers) {
  std::vector<int> vec{-1, 3, -2, 5, 4, -3};
  ASSERT_EQ(QuickSort(vec), (std::vector<int>{-3, -2, -1, 3, 4, 5}));
}

TEST(Quick_Sort, AlreadySorted) {
  std::vector<int> vec{1, 2, 3, 4, 5};
  ASSERT_EQ(QuickSort(vec), (std::vector<int>{1, 2, 3, 4, 5}));
}

TEST(Quick_Sort, ReverseOrder) {
  std::vector<int> vec{5, 4, 3, 2, 1};
  ASSERT_EQ(QuickSort(vec), (std::vector<int>{1, 2, 3, 4, 5}));
}

TEST(Quick_Sort, ZerosAndNegatives) {
  std::vector<int> vec{0, -1, 0, -2, 0, -3};
  ASSERT_EQ(QuickSort(vec), (std::vector<int>{-3, -2, -1, 0, 0, 0}));
}

TEST(Quick_Sort, LargeArray) {
  std::vector<int> vec(1000);
  std::iota(vec.begin(), vec.end(), -500);
  std::random_shuffle(vec.begin(), vec.end());
  std::vector<int> sorted_vec(vec);
  std::sort(sorted_vec.begin(), sorted_vec.end());
  ASSERT_EQ(QuickSort(vec), sorted_vec);
}

// tests for bogo sort
TEST(Bogo_Sort, Simple) {
  std::vector<int> vec1{5, 4, 2, 3, 1, 0};

  ASSERT_EQ(BogoSort(vec1), (std::vector<int>{0, 1, 2, 3, 4, 5}));
}

TEST(Bogo_Sort, EmptyVector) {
  std::vector<int> vec;
  ASSERT_EQ(BogoSort(vec), (std::vector<int>{}));
}

TEST(Bogo_Sort, SingleElement) {
  std::vector<int> vec{1};
  ASSERT_EQ(BogoSort(vec), (std::vector<int>{1}));
}

TEST(Bogo_Sort, RepeatedElements) {
  std::vector<int> vec{5, 5, 5, 5};
  ASSERT_EQ(BogoSort(vec), (std::vector<int>{5, 5, 5, 5}));
}

TEST(Bogo_Sort, MixedNumbers) {
  std::vector<int> vec{-1, 3, -2, 5, 4, -3};
  ASSERT_EQ(BogoSort(vec), (std::vector<int>{-3, -2, -1, 3, 4, 5}));
}

TEST(Bogo_Sort, AlreadySorted) {
  std::vector<int> vec{1, 2, 3, 4, 5};
  ASSERT_EQ(BogoSort(vec), (std::vector<int>{1, 2, 3, 4, 5}));
}

TEST(Bogo_Sort, ReverseOrder) {
  std::vector<int> vec{5, 4, 3, 2, 1};
  ASSERT_EQ(BogoSort(vec), (std::vector<int>{1, 2, 3, 4, 5}));
}

TEST(Bogo_Sort, ZerosAndNegatives) {
  std::vector<int> vec{0, -1, 0, -2, 0, -3};
  ASSERT_EQ(BogoSort(vec), (std::vector<int>{-3, -2, -1, 0, 0, 0}));
}

// TEST(Bogo_Sort, LargeArray) {
//   std::vector<int> vec(1000);
//   std::iota(vec.begin(), vec.end(), -500);
//   std::random_shuffle(vec.begin(), vec.end());
//   std::vector<int> sorted_vec(vec);
//   std::sort(sorted_vec.begin(), sorted_vec.end());
//   ASSERT_EQ(BogoSort(vec), sorted_vec);
// }

// tests for bubble sort
TEST(Bubble_Sort, Simple) {
  std::vector<int> vec1{9, 8, 7, 6, 5, 4, 2, 3, 1, 0};
  ASSERT_EQ(BubbleSort(vec1), (std::vector<int>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}));
  std::vector<int> vec2{10, 90, 30, 80, 60, 50};
  ASSERT_EQ(BubbleSort(vec2), (std::vector<int>{10, 30, 50, 60, 80, 90}));
  std::vector<int> vec3{12,  43,  15, 26, -1233, 346, 1325,
                        -56, -12, 78, 0,  3345,  -34};
  ASSERT_EQ(BubbleSort(vec3), (std::vector<int>{-1233, -56, -34, -12, 0, 12, 15,
                                                26, 43, 78, 346, 1325, 3345}));
  vec3.push_back(-10);
  vec3.push_back(1000);
  vec3.push_back(5);
  ASSERT_EQ(BubbleSort(vec3),
            (std::vector<int>{-1233, -56, -34, -12, -10, 0, 5, 12, 15, 26, 43,
                              78, 346, 1000, 1325, 3345}));
}

TEST(Bubble_Sort, EmptyVector) {
  std::vector<int> vec;
  ASSERT_EQ(BubbleSort(vec), (std::vector<int>{}));
}

TEST(Bubble_Sort, SingleElement) {
  std::vector<int> vec{1};
  ASSERT_EQ(BubbleSort(vec), (std::vector<int>{1}));
}

TEST(Bubble_Sort, RepeatedElements) {
  std::vector<int> vec{5, 5, 5, 5};
  ASSERT_EQ(BubbleSort(vec), (std::vector<int>{5, 5, 5, 5}));
}

TEST(Bubble_Sort, MixedNumbers) {
  std::vector<int> vec{-1, 3, -2, 5, 4, -3};
  ASSERT_EQ(BubbleSort(vec), (std::vector<int>{-3, -2, -1, 3, 4, 5}));
}

TEST(Bubble_Sort, AlreadySorted) {
  std::vector<int> vec{1, 2, 3, 4, 5};
  ASSERT_EQ(BubbleSort(vec), (std::vector<int>{1, 2, 3, 4, 5}));
}

TEST(Bubble_Sort, ReverseOrder) {
  std::vector<int> vec{5, 4, 3, 2, 1};
  ASSERT_EQ(BubbleSort(vec), (std::vector<int>{1, 2, 3, 4, 5}));
}

TEST(Bubble_Sort, ZerosAndNegatives) {
  std::vector<int> vec{0, -1, 0, -2, 0, -3};
  ASSERT_EQ(BubbleSort(vec), (std::vector<int>{-3, -2, -1, 0, 0, 0}));
}

TEST(Bubble_Sort, LargeArray) {
  std::vector<int> vec(1000);
  std::iota(vec.begin(), vec.end(), -500);
  std::random_shuffle(vec.begin(), vec.end());
  std::vector<int> sorted_vec(vec);
  std::sort(sorted_vec.begin(), sorted_vec.end());
  ASSERT_EQ(BubbleSort(vec), sorted_vec);
}

// tests for insertion sort
TEST(Insertion_Sort, Simple) {
  std::vector<int> vec1{9, 8, 7, 6, 5, 4, 2, 3, 1, 0};
  ASSERT_EQ(InsertionSort(vec1),
            (std::vector<int>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}));
  std::vector<int> vec2{10, 90, 30, 80, 60, 50};
  ASSERT_EQ(InsertionSort(vec2), (std::vector<int>{10, 30, 50, 60, 80, 90}));
  std::vector<int> vec3{12,  43,  15, 26, -1233, 346, 1325,
                        -56, -12, 78, 0,  3345,  -34};
  ASSERT_EQ(InsertionSort(vec3),
            (std::vector<int>{-1233, -56, -34, -12, 0, 12, 15, 26, 43, 78, 346,
                              1325, 3345}));
  vec3.push_back(-10);
  vec3.push_back(1000);
  vec3.push_back(5);
  ASSERT_EQ(InsertionSort(vec3),
            (std::vector<int>{-1233, -56, -34, -12, -10, 0, 5, 12, 15, 26, 43,
                              78, 346, 1000, 1325, 3345}));
}

TEST(Insertion_Sort, EmptyVector) {
  std::vector<int> vec;
  ASSERT_EQ(InsertionSort(vec), (std::vector<int>{}));
}

TEST(Insertion_Sort, SingleElement) {
  std::vector<int> vec{1};
  ASSERT_EQ(InsertionSort(vec), (std::vector<int>{1}));
}

TEST(Insertion_Sort, RepeatedElements) {
  std::vector<int> vec{5, 5, 5, 5};
  ASSERT_EQ(InsertionSort(vec), (std::vector<int>{5, 5, 5, 5}));
}

TEST(Insertion_Sort, MixedNumbers) {
  std::vector<int> vec{-1, 3, -2, 5, 4, -3};
  ASSERT_EQ(InsertionSort(vec), (std::vector<int>{-3, -2, -1, 3, 4, 5}));
}

TEST(Insertion_Sort, AlreadySorted) {
  std::vector<int> vec{1, 2, 3, 4, 5};
  ASSERT_EQ(InsertionSort(vec), (std::vector<int>{1, 2, 3, 4, 5}));
}

TEST(Insertion_Sort, ReverseOrder) {
  std::vector<int> vec{5, 4, 3, 2, 1};
  ASSERT_EQ(InsertionSort(vec), (std::vector<int>{1, 2, 3, 4, 5}));
}

TEST(Insertion_Sort, ZerosAndNegatives) {
  std::vector<int> vec{0, -1, 0, -2, 0, -3};
  ASSERT_EQ(InsertionSort(vec), (std::vector<int>{-3, -2, -1, 0, 0, 0}));
}

TEST(Insertion_Sort, LargeArray) {
  std::vector<int> vec(1000);
  std::iota(vec.begin(), vec.end(), -500);
  std::random_shuffle(vec.begin(), vec.end());
  std::vector<int> sorted_vec(vec);
  std::sort(sorted_vec.begin(), sorted_vec.end());
  ASSERT_EQ(InsertionSort(vec), sorted_vec);
}

// tests for selection sort
TEST(Selection_Sort, Simple) {
  std::vector<int> vec1{9, 8, 7, 6, 5, 4, 2, 3, 1, 0};
  ASSERT_EQ(SelectionSort(vec1),
            (std::vector<int>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}));
  std::vector<int> vec2{10, 90, 30, 80, 60, 50};
  ASSERT_EQ(SelectionSort(vec2), (std::vector<int>{10, 30, 50, 60, 80, 90}));
  std::vector<int> vec3{12,  43,  15, 26, -1233, 346, 1325,
                        -56, -12, 78, 0,  3345,  -34};
  ASSERT_EQ(SelectionSort(vec3),
            (std::vector<int>{-1233, -56, -34, -12, 0, 12, 15, 26, 43, 78, 346,
                              1325, 3345}));
  vec3.push_back(-10);
  vec3.push_back(1000);
  vec3.push_back(5);
  ASSERT_EQ(SelectionSort(vec3),
            (std::vector<int>{-1233, -56, -34, -12, -10, 0, 5, 12, 15, 26, 43,
                              78, 346, 1000, 1325, 3345}));
}

TEST(Selection_Sort, EmptyVector) {
  std::vector<int> vec;
  ASSERT_EQ(SelectionSort(vec), (std::vector<int>{}));
}

TEST(Selection_Sort, SingleElement) {
  std::vector<int> vec{1};
  ASSERT_EQ(SelectionSort(vec), (std::vector<int>{1}));
}

TEST(Selection_Sort, RepeatedElements) {
  std::vector<int> vec{5, 5, 5, 5};
  ASSERT_EQ(SelectionSort(vec), (std::vector<int>{5, 5, 5, 5}));
}

TEST(Selection_Sort, MixedNumbers) {
  std::vector<int> vec{-1, 3, -2, 5, 4, -3};
  ASSERT_EQ(SelectionSort(vec), (std::vector<int>{-3, -2, -1, 3, 4, 5}));
}

TEST(Selection_Sort, AlreadySorted) {
  std::vector<int> vec{1, 2, 3, 4, 5};
  ASSERT_EQ(SelectionSort(vec), (std::vector<int>{1, 2, 3, 4, 5}));
}

TEST(Selection_Sort, ReverseOrder) {
  std::vector<int> vec{5, 4, 3, 2, 1};
  ASSERT_EQ(SelectionSort(vec), (std::vector<int>{1, 2, 3, 4, 5}));
}

TEST(Selection_Sort, ZerosAndNegatives) {
  std::vector<int> vec{0, -1, 0, -2, 0, -3};
  ASSERT_EQ(SelectionSort(vec), (std::vector<int>{-3, -2, -1, 0, 0, 0}));
}

TEST(Selection_Sort, LargeArray) {
  std::vector<int> vec(1000);
  std::iota(vec.begin(), vec.end(), -500);
  std::random_shuffle(vec.begin(), vec.end());
  std::vector<int> sorted_vec(vec);
  std::sort(sorted_vec.begin(), sorted_vec.end());
  ASSERT_EQ(SelectionSort(vec), sorted_vec);
}

// tests for merge sort top buttom
TEST(Merge_Sort_Top_Buttom, Simple) {
  std::vector<int> vec1{9, 8, 7, 6, 5, 4, 2, 3, 1, 0};
  ASSERT_EQ(MergeSortTopBottom(vec1),
            (std::vector<int>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}));
  std::vector<int> vec2{10, 90, 30, 80, 60, 50};
  ASSERT_EQ(MergeSortTopBottom(vec2),
            (std::vector<int>{10, 30, 50, 60, 80, 90}));
  std::vector<int> vec3{12,  43,  15, 26, -1233, 346, 1325,
                        -56, -12, 78, 0,  3345,  -34};
  ASSERT_EQ(MergeSortTopBottom(vec3),
            (std::vector<int>{-1233, -56, -34, -12, 0, 12, 15, 26, 43, 78, 346,
                              1325, 3345}));
  vec3.push_back(-10);
  vec3.push_back(1000);
  vec3.push_back(5);
  ASSERT_EQ(MergeSortTopBottom(vec3),
            (std::vector<int>{-1233, -56, -34, -12, -10, 0, 5, 12, 15, 26, 43,
                              78, 346, 1000, 1325, 3345}));
}

TEST(Merge_Sort_Top_Buttom, EmptyVector) {
  std::vector<int> vec;
  ASSERT_EQ(MergeSortTopBottom(vec), (std::vector<int>{}));
}

TEST(Merge_Sort_Top_Buttom, SingleElement) {
  std::vector<int> vec{1};
  ASSERT_EQ(MergeSortTopBottom(vec), (std::vector<int>{1}));
}

TEST(Merge_Sort_Top_Buttom, RepeatedElements) {
  std::vector<int> vec{5, 5, 5, 5};
  ASSERT_EQ(MergeSortTopBottom(vec), (std::vector<int>{5, 5, 5, 5}));
}

TEST(Merge_Sort_Top_Buttom, MixedNumbers) {
  std::vector<int> vec{-1, 3, -2, 5, 4, -3};
  ASSERT_EQ(MergeSortTopBottom(vec), (std::vector<int>{-3, -2, -1, 3, 4, 5}));
}

TEST(Merge_Sort_Top_Buttom, AlreadySorted) {
  std::vector<int> vec{1, 2, 3, 4, 5};
  ASSERT_EQ(MergeSortTopBottom(vec), (std::vector<int>{1, 2, 3, 4, 5}));
}

TEST(Merge_Sort_Top_Buttom, ReverseOrder) {
  std::vector<int> vec{5, 4, 3, 2, 1};
  ASSERT_EQ(MergeSortTopBottom(vec), (std::vector<int>{1, 2, 3, 4, 5}));
}

TEST(Merge_Sort_Top_Buttom, ZerosAndNegatives) {
  std::vector<int> vec{0, -1, 0, -2, 0, -3};
  ASSERT_EQ(MergeSortTopBottom(vec), (std::vector<int>{-3, -2, -1, 0, 0, 0}));
}

TEST(Merge_Sort_Top_Buttom, LargeArray) {
  std::vector<int> vec(1000);
  std::iota(vec.begin(), vec.end(), -500);
  std::random_shuffle(vec.begin(), vec.end());
  std::vector<int> sorted_vec(vec);
  std::sort(sorted_vec.begin(), sorted_vec.end());
  ASSERT_EQ(MergeSortTopBottom(vec), sorted_vec);
}

// tests for merge sort buttom up
TEST(Merge_Sort_Buttom_Up, Simple) {
  std::vector<int> vec1{9, 8, 7, 6, 5, 4, 2, 3, 1, 0};
  ASSERT_EQ(MergeSortBottomUp(vec1),
            (std::vector<int>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}));
  std::vector<int> vec2{10, 90, 30, 80, 60, 50};
  ASSERT_EQ(MergeSortBottomUp(vec2),
            (std::vector<int>{10, 30, 50, 60, 80, 90}));
  std::vector<int> vec3{12,  43,  15, 26, -1233, 346, 1325,
                        -56, -12, 78, 0,  3345,  -34};
  ASSERT_EQ(MergeSortBottomUp(vec3),
            (std::vector<int>{-1233, -56, -34, -12, 0, 12, 15, 26, 43, 78, 346,
                              1325, 3345}));
  vec3.push_back(-10);
  vec3.push_back(1000);
  vec3.push_back(5);
  ASSERT_EQ(MergeSortBottomUp(vec3),
            (std::vector<int>{-1233, -56, -34, -12, -10, 0, 5, 12, 15, 26, 43,
                              78, 346, 1000, 1325, 3345}));
}

TEST(Merge_Sort_Buttom_Up, EmptyVector) {
  std::vector<int> vec;
  ASSERT_EQ(MergeSortBottomUp(vec), (std::vector<int>{}));
}

TEST(Merge_Sort_Buttom_Up, SingleElement) {
  std::vector<int> vec{1};
  ASSERT_EQ(MergeSortBottomUp(vec), (std::vector<int>{1}));
}

TEST(Merge_Sort_Buttom_Up, RepeatedElements) {
  std::vector<int> vec{5, 5, 5, 5};
  ASSERT_EQ(MergeSortBottomUp(vec), (std::vector<int>{5, 5, 5, 5}));
}

TEST(Merge_Sort_Buttom_Up, MixedNumbers) {
  std::vector<int> vec{-1, 3, -2, 5, 4, -3};
  ASSERT_EQ(MergeSortBottomUp(vec), (std::vector<int>{-3, -2, -1, 3, 4, 5}));
}

TEST(Merge_Sort_Buttom_Up, AlreadySorted) {
  std::vector<int> vec{1, 2, 3, 4, 5};
  ASSERT_EQ(MergeSortBottomUp(vec), (std::vector<int>{1, 2, 3, 4, 5}));
}

TEST(Merge_Sort_Buttom_Up, ReverseOrder) {
  std::vector<int> vec{5, 4, 3, 2, 1};
  ASSERT_EQ(MergeSortBottomUp(vec), (std::vector<int>{1, 2, 3, 4, 5}));
}

TEST(Merge_Sort_Buttom_Up, ZerosAndNegatives) {
  std::vector<int> vec{0, -1, 0, -2, 0, -3};
  ASSERT_EQ(MergeSortBottomUp(vec), (std::vector<int>{-3, -2, -1, 0, 0, 0}));
}

TEST(Merge_Sort_Buttom_Up, LargeArray) {
  std::vector<int> vec(1000);
  std::iota(vec.begin(), vec.end(), -500);
  std::random_shuffle(vec.begin(), vec.end());
  std::vector<int> sorted_vec(vec);
  std::sort(sorted_vec.begin(), sorted_vec.end());
  ASSERT_EQ(MergeSortBottomUp(vec), sorted_vec);
}
