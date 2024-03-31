
#include <gtest/gtest.h>

#include <vector>

#include "quick_sort.hpp"

TEST(quick_sort, EmptyArray) {
  std::vector<int> array = {};
  std::vector<int> sorted_array = {};
  QuickSort(array, 0, int(array.size() - 1));
  ASSERT_EQ(array, sorted_array);
}

TEST(quick_sort, AlreadySortedArray) {
  std::vector<int> array = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<int> sorted_array = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  QuickSort(array, 0, int(array.size() - 1));
  ASSERT_EQ(array, sorted_array);
}

TEST(quick_sort, ReverseSortedArray) {
  std::vector<int> array = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  std::vector<int> sorted_array = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  QuickSort(array, 0, int(array.size() - 1));
  ASSERT_EQ(array, sorted_array);
}

TEST(quick_sort, SmallRandomArray) {
  std::vector<int> array = {-61, 20, -64, -39, 24,  -91, 28,  -69, -78,
                            7,   16, -97, -12, 29,  8,   -27, 50,  -98,
                            -37, 42, -72, -19, -25, 23,  96};
  std::vector<int> sorted_array = {-98, -97, -91, -78, -72, -69, -64, -61, -39,
                                   -37, -27, -25, -19, -12, 7,   8,   16,  20,
                                   23,  24,  28,  29,  42,  50,  96};
  QuickSort(array, 0, int(array.size() - 1));
  ASSERT_EQ(array, sorted_array);
}

TEST(quick_sort, LargeRandomArray) {
  std::vector<int> array = {
      -141, -98,  477,  -592, 76,   -815, -826, 97,    -178, -723, 814,  -266,
      374,  602,  40,   -191, -578, 858,  919,  785,   -54,  -706, 294,  -187,
      -239, -946, -8,   -310, 305,  -353, 405,  699,   -767, 798,  -727, -452,
      400,  67,   -318, -814, 676,  -515, 693,  -848,  -470, 334,  -858, -576,
      953,  695,  442,  854,  103,  818,  274,  611,   129,  412,  517,  480,
      -246, 769,  57,   -431, -326, 492,  732,  -40,   -261, -463, -316, 915,
      -30,  836,  276,  309,  -225, -193, -623, -1000, -113, 614,  -869, 694,
      -480, -287, -343, 71,   -458, -775, -947, 335,   637,  -627, 43,   -874,
      109,  -805, 567,  927};
  std::vector<int> sorted_array = {
      -1000, -947, -946, -874, -869, -858, -848, -826, -815, -814, -805, -775,
      -767,  -727, -723, -706, -627, -623, -592, -578, -576, -515, -480, -470,
      -463,  -458, -452, -431, -353, -343, -326, -318, -316, -310, -287, -266,
      -261,  -246, -239, -225, -193, -191, -187, -178, -141, -113, -98,  -54,
      -40,   -30,  -8,   40,   43,   57,   67,   71,   76,   97,   103,  109,
      129,   274,  276,  294,  305,  309,  334,  335,  374,  400,  405,  412,
      442,   477,  480,  492,  517,  567,  602,  611,  614,  637,  676,  693,
      694,   695,  699,  732,  769,  785,  798,  814,  818,  836,  854,  858,
      915,   919,  927,  953};
  QuickSort(array, 0, int(array.size() - 1));
  ASSERT_EQ(array, sorted_array);
}