// std libs:
#include <iostream>
#include <stdexcept>
#include <utility>
#include <vector>

// test lib:
#include <gtest/gtest.h>

// my libs:
#include "two_sum.hpp"

using namespace std;

TEST(TopologySort, Subtest_1) {
  ASSERT_EQ(TwoElemsGivingSum(vector<int>{2, 3, 4, 7, 12}, 10),
            (pair<int, int>{3, 7}));
}

TEST(TopologySort, Subtest_2) {
  ASSERT_EQ(TwoElemsGivingSum(vector<int>{4, 7, 8, 9, 10}, 12),
            (pair<int, int>{4, 8}));
}

TEST(TopologySort, Subtest_3) {
  ASSERT_EQ(TwoElemsGivingSum(vector<int>{-3, -2, 0, 1, 2}, 0),
            (pair<int, int>{-2, 2}));
}

TEST(TopologySort, Subtest_4) {
  ASSERT_EQ(TwoElemsGivingSum(
                vector<int>{1, 2, 4, 5, 8, 10, 13, 17, 20, 21, 22, 25}, 27),
            (pair<int, int>{2, 25}));
}

TEST(TopologySort, Subtest_5) {
  ASSERT_EQ(TwoElemsGivingSum(vector<int>{1, 5, 13, 21, 22}, 6),
            (pair<int, int>{1, 5}));
}

TEST(TopologySort, Subtest_6) {
  EXPECT_THROW(TwoElemsGivingSum(vector<int>{1, 5, 13, 21, 22}, 7),
               logic_error);
}

TEST(TopologySort, Subtest_7) {
  EXPECT_THROW(TwoElemsGivingSum(vector<int>{2, 3, 4, 7, 12}, 57), logic_error);
}

TEST(TopologySort, Subtest_8) {
  EXPECT_THROW(TwoElemsGivingSum(
                   vector<int>{1, 2, 4, 5, 8, 10, 13, 17, 20, 21, 22, 25}, -3),
               logic_error);
}

TEST(TopologySort, Subtest_9) {
  EXPECT_THROW(TwoElemsGivingSum(
                   vector<int>{1, 5, 4, 5, 8, -10, 13, 17, 20, 21, 22, 25}, -3),
               invalid_argument);
}

TEST(TopologySort, Subtest_10) {
  EXPECT_THROW(TwoElemsGivingSum(vector<int>{1, -5, 13, -21, 22}, 6),
               invalid_argument);
}

TEST(TopologySort, Subtest_11) {
  ASSERT_EQ(
      TwoElemsGivingSum(vector<int>{10, 20, 40, 50, 60, 87, 100, 1278}, 1338),
      (pair<int, int>{60, 1278}));
}

TEST(TopologySort, Subtest_12) {
  ASSERT_EQ(TwoElemsGivingSum(
                vector<long>{50000000000000, 50000000000000, 60000000000000,
                             70000000000000, 80000000000000, 90000000000000},
                100000000000000),
            (pair<long, long>{50000000000000, 50000000000000}));
}

TEST(TopologySort, Subtest_13) {
  ASSERT_EQ(TwoElemsGivingSum(
                vector<long>{1000000000000, 2000000000000, 3000000000000,
                             4000000000000, 7000000000000},
                10000000000000),
            (pair<long, long>{3000000000000, 7000000000000}));
}

TEST(TopologySort, Subtest_14) {
  EXPECT_THROW(TwoElemsGivingSum(
                   vector<long>{11111111111111, 22222222222222, 22222222222222,
                                44444444444444, 66666666666666},
                   99999999999999),
               logic_error);
}

TEST(TopologySort, Subtest_15) {
  EXPECT_THROW(TwoElemsGivingSum(
                   vector<long>{50000000000000, -50000000000000, 60000000000000,
                                70000000000000, 80000000000000, 90000000000000},
                   100000000000000),
               invalid_argument);
}
