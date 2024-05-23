#include <gtest/gtest.h>
#include <vector>
#include "utils.h"

TEST(main, Simple) {
  ASSERT_EQ(Task1(9, std::vector < int > {1, 2, 4, 5, 6, 8, 10, 12}), (std::pair < int, int > {1,8}));

  ASSERT_EQ(Task1(39, std::vector < int > {1, 2, 4, 5, 6, 9, 10, 35}), (std::pair < int, int > {4,35}));

  ASSERT_EQ(Task1(14, std::vector < int > {1, 2, 4, 5, 6, 8, 10, 12}), (std::pair < int, int > {2,12}));

  ASSERT_EQ(Task1(1338, std::vector < int > {10, 20, 40, 50, 60, 87, 100, 1278}), (std::pair < int, int > {60,1278}));

  ASSERT_EQ(Task1(22, std::vector < int > {10, 10, 11, 11, 12, 15}), (std::pair < int, int > {10,12}));
}