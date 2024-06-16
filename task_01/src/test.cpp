
#include <gtest/gtest.h>

#include "task.hpp"

// BinSearch tests
TEST(BinSearch, Simple) {
  // even len
  std::vector<int> mas = {1, 2, 3, 4, 5, 6, 7, 8};
  ASSERT_EQ(BinSearch(mas, 1), 0);
  ASSERT_EQ(BinSearch(mas, 2), 1);
  ASSERT_EQ(BinSearch(mas, 3), 2);
  ASSERT_EQ(BinSearch(mas, 4), 3);
  ASSERT_EQ(BinSearch(mas, 5), 4);
  ASSERT_EQ(BinSearch(mas, 6), 5);
  ASSERT_EQ(BinSearch(mas, 7), 6);
  ASSERT_EQ(BinSearch(mas, 8), 7);

  ASSERT_EQ(BinSearch(mas, 31), -1);

  // odd len
  mas = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  ASSERT_EQ(BinSearch(mas, 1), 0);
  ASSERT_EQ(BinSearch(mas, 2), 1);
  ASSERT_EQ(BinSearch(mas, 3), 2);
  ASSERT_EQ(BinSearch(mas, 4), 3);
  ASSERT_EQ(BinSearch(mas, 5), 4);
  ASSERT_EQ(BinSearch(mas, 6), 5);
  ASSERT_EQ(BinSearch(mas, 7), 6);
  ASSERT_EQ(BinSearch(mas, 8), 7);

  ASSERT_EQ(BinSearch(mas, 31), -1);

  // empty mas
  mas = {};
  ASSERT_EQ(BinSearch(mas, 8), -1);

  // mas of 1 elem
  mas = {1};
  ASSERT_EQ(BinSearch(mas, 1), 0);

  ASSERT_EQ(BinSearch(mas, 31), -1);

  // mas of 2 elems
  mas = {1, 2};
  ASSERT_EQ(BinSearch(mas, 1), 0);
  ASSERT_EQ(BinSearch(mas, 2), 1);

  ASSERT_EQ(BinSearch(mas, 31), -1);
}

// NSquareSearch tests
TEST(NSquareSearch, Simple) {
  std::vector<int> mas = {1, 2, 3, 4, 5, 6, 7, 8};
  ASSERT_EQ(NSquareSearch(mas, 11), std::make_tuple(2, 7));
  ASSERT_EQ(NSquareSearch(mas, 9), std::make_tuple(0, 7));

  ASSERT_EQ(NSquareSearch(mas, 1), std::make_tuple(-1, -1));
  ASSERT_EQ(NSquareSearch(mas, 16),
            std::make_tuple(-1, -1));  // not (7, 7), as indexes cant be same
}

// NLogNSearch tests
TEST(NLogNSearch, Simple) {
  std::vector<int> mas = {1, 2, 3, 4, 5, 6, 7, 8};
  ASSERT_EQ(NLogNSearch(mas, 11), std::make_tuple(2, 7));
  ASSERT_EQ(NLogNSearch(mas, 9), std::make_tuple(0, 7));

  ASSERT_EQ(NLogNSearch(mas, 1), std::make_tuple(-1, -1));
  ASSERT_EQ(NLogNSearch(mas, 16),
            std::make_tuple(-1, -1));  // not (7, 7), as indexes cant be same
}

// NSearch tests
TEST(NSearch, Simple) {
  std::vector<int> mas = {1, 2, 3, 4, 5, 6, 7, 8};
  ASSERT_EQ(NSearch(mas, 11), std::make_tuple(2, 7));
  ASSERT_EQ(NSearch(mas, 9), std::make_tuple(0, 7));

  ASSERT_EQ(NSearch(mas, 1), std::make_tuple(-1, -1));
  ASSERT_EQ(NSearch(mas, 16),
            std::make_tuple(-1, -1));  // not (7, 7), as indexes cant be same
}