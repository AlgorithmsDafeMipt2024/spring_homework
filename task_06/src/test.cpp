#include <gtest/gtest.h>

#include <vector>

#include "nth_element.h"

TEST(NthElement, Sorted) {
  std::vector<int> v{1, 2, 3, 4, 5, 6};
  ASSERT_EQ(NthElement(v, 0), 1);
  ASSERT_EQ(NthElement(v, 1), 2);
  ASSERT_EQ(NthElement(v, 2), 3);
  ASSERT_EQ(NthElement(v, 3), 4);
  ASSERT_EQ(NthElement(v, 4), 5);
  ASSERT_EQ(NthElement(v, 5), 6);
}
TEST(NthElement, InverseSorted) {
  std::vector<int> v{6, 5, 4, 3, 2, 1};
  ASSERT_EQ(NthElement(v, 0), 1);
  ASSERT_EQ(NthElement(v, 1), 2);
  ASSERT_EQ(NthElement(v, 2), 3);
  ASSERT_EQ(NthElement(v, 3), 4);
  ASSERT_EQ(NthElement(v, 4), 5);
  ASSERT_EQ(NthElement(v, 5), 6);
}
//[8, 22, 37, 40, 60, 61, 63, 84, 97, 99]

TEST(NthElement, Integers) {
  std::vector<int> v{1, 10, 2, 9, 3, 8, 4, 7, 5, 6};
  ASSERT_EQ(NthElement(v, 0), 1);
  ASSERT_EQ(NthElement(v, 1), 2);
  ASSERT_EQ(NthElement(v, 2), 3);
  ASSERT_EQ(NthElement(v, 3), 4);
  ASSERT_EQ(NthElement(v, 4), 5);
  ASSERT_EQ(NthElement(v, 5), 6);
  ASSERT_EQ(NthElement(v, 6), 7);
  ASSERT_EQ(NthElement(v, 7), 8);
  ASSERT_EQ(NthElement(v, 8), 9);
  ASSERT_EQ(NthElement(v, 9), 10);
}
TEST(NthElement, Doubles) {
  std::vector<double> v{37.75, 99.53, 63.24, 22.56, 37.74,
                        60.32, 61.48, 8.15,  84.52, 97.93};
  ASSERT_EQ(NthElement(v, 0), 8.15);
  ASSERT_EQ(NthElement(v, 1), 22.56);
  ASSERT_EQ(NthElement(v, 2), 37.74);
  ASSERT_EQ(NthElement(v, 3), 37.75);
  ASSERT_EQ(NthElement(v, 4), 60.32);
  ASSERT_EQ(NthElement(v, 5), 61.48);
  ASSERT_EQ(NthElement(v, 6), 63.24);
  ASSERT_EQ(NthElement(v, 7), 84.52);
  ASSERT_EQ(NthElement(v, 8), 97.93);
  ASSERT_EQ(NthElement(v, 9), 99.53);
}

TEST(NthElement, Characters) {
  std::vector<char> v{'d', 's', 'a', 'b'};
  ASSERT_EQ(NthElement(v, 1), 'b');
}

TEST(NthElement, Duplicates) {
  std::vector<int> v{2, 2, 2, 2, 2, 2};
  ASSERT_EQ(NthElement(v, 0), 2);
  ASSERT_EQ(NthElement(v, 1), 2);
  ASSERT_EQ(NthElement(v, 2), 2);
  ASSERT_EQ(NthElement(v, 3), 2);
  ASSERT_EQ(NthElement(v, 4), 2);
  ASSERT_EQ(NthElement(v, 5), 2);
}