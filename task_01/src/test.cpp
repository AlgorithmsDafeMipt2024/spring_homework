#include <gtest/gtest.h>

#include <iostream>
#include <stdexcept>
#include <vector>

#include "get_two_nums.hpp"

TEST(GetTwoNums, Test_1) {
  ASSERT_EQ(GetTwoNums(15, std::vector<long long>{5, 10, 15, 20, 25}),
            (std::pair<long long, long long>{5, 10}));
}

TEST(GetTwoNums, Test_2) {
  ASSERT_EQ(
      GetTwoNums(18, std::vector<long long>{1, 2, 3, 5, 7, 8, 10, 14, 19, 25}),
      (std::pair<long long, long long>{8, 10}));
}

TEST(GetTwoNums, Test_3) {
  ASSERT_EQ(GetTwoNums(-20, std::vector<long long>{-100, -98, -72, -54, -11, 0,
                                                   10, 20, 34, 60}),
            (std::pair<long long, long long>{-54, 34}));
}

TEST(GetTwoNums, Test_4) {
  ASSERT_EQ(
      GetTwoNums(-6, std::vector<long long>{-120, -100, -84, -20, -11, -5, -1}),
      (std::pair<long long, long long>{-5, -1}));
}

TEST(GetTwoNums, Test_5) {
  ASSERT_EQ(
      GetTwoNums(21000000000,
                 std::vector<long long>{1000000000, 2000000000, 4000000000,
                                        8000000000, 11000000000, 13000000000}),
      (std::pair<long long, long long>{8000000000, 13000000000}));
}

TEST(GetTwoNums, Test_6) {
  ASSERT_EQ(
      GetTwoNums(
          11, std::vector<long long>{0, 0, 0, 0, 0, 1, 1,  2,  2,  2,  2,  3,
                                     6, 7, 8, 9, 9, 9, 12, 13, 15, 15, 16, 17}),
      (std::pair<long long, long long>{2, 9}));
}

TEST(GetTwoNums, Test_7) {
  ASSERT_EQ(GetTwoNums(100000000000000,
                       std::vector<long long>{
                           10000000000000, 20000000000000, 30000000000000,
                           30000000000000, 50000000000000, 50000000000000,
                           60000000000000, 110000000000000, 110000000000000,
                           110000000000000}),
            (std::pair<long long, long long>{50000000000000, 50000000000000}));
}

TEST(GetTwoNums, Test_8) {
  ASSERT_EQ(GetTwoNums(84, std::vector<long long>{-12, -6, -4, 1, 23, 25, 26,
                                                  33, 38, 46, 52, 58, 64, 69,
                                                  76, 82, 97, 101}),
            (std::pair<long long, long long>{26, 58}));
}

TEST(GetTwoNums, Test_9) {
  EXPECT_THROW(GetTwoNums(2, std::vector<long long>{2}), std::length_error);
}

TEST(GetTwoNums, Test_10) {
  EXPECT_THROW(GetTwoNums(100, std::vector<long long>{}), std::length_error);
}

TEST(GetTwoNums, Test_11) {
  EXPECT_THROW(GetTwoNums(5, std::vector<long long>{1, 2, 5, 7, 9, 11, 23, 55}),
               std::logic_error);
}

TEST(GetTwoNums, Test_12) {
  EXPECT_THROW(GetTwoNums(-10, std::vector<long long>{1, 2, 3, 4, 5, 6, 7, 8, 9,
                                                      10, 11, 12, 13, 14}),
               std::logic_error);
}
