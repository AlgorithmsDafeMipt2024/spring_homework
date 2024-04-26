
#include <gtest/gtest.h>

#include "topology_sort.hpp"

//Простые тесты
TEST(TopologySort, Simple) {
  ASSERT_EQ(Rise_Temperature(std::vector<int>{1, 2, 3, 4, 5}),
            (std::vector<int>{1, 1, 1, 1, 0}));
  ASSERT_EQ(Rise_Temperature(std::vector<int>{5, 4, 3, 2, 1}),
            (std::vector<int>{0, 0, 0, 0, 0}));
  ASSERT_EQ(
      Rise_Temperature(std::vector<int>{-3, 0, 1, 23, 4, 5, 12, 1, 2, 1, 3}),
      (std::vector<int>{1, 1, 1, 0, 1, 1, 0, 1, 2, 1, 0}));
  ASSERT_EQ(
      Rise_Temperature(std::vector<int>{12, 14, 2, 12, 11, 10, 0, 5, 3, 20, 4}),
      (std::vector<int>{1, 8, 1, 6, 5, 4, 1, 2, 1, 0, 0}));
  ASSERT_EQ(
      Rise_Temperature(std::vector<int>{11, -2, 3, 1, 5, 2, 6, 3, 7, 84, 4}),
      (std::vector<int>{9, 1, 2, 1, 2, 1, 2, 1, 1, 0, 0}));
  ASSERT_EQ(Rise_Temperature(std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9}),
            (std::vector<int>{1, 1, 1, 1, 1, 1, 1, 1, 0}));
}

// Тестирование поведения при убывающих температурах
TEST(TopologySort, DecreasingTemperature) {
  ASSERT_EQ(Rise_Temperature(std::vector<int>{10, 9, 8, 7, 6}),
            (std::vector<int>{0, 0, 0, 0, 0}));
}

// Тестирование поведения при возрастающих температурах
TEST(TopologySort, IncreasingTemperature) {
  ASSERT_EQ(Rise_Temperature(std::vector<int>{-5, -4, -3, -2, -1}),
            (std::vector<int>{1, 1, 1, 1, 0}));
}

// Тестирование поведения с случайными температурами
TEST(TopologySort, RandomTemperature) {
  ASSERT_EQ(Rise_Temperature(std::vector<int>{3, -1, 4, 1, 5}),
            (std::vector<int>{2, 1, 2, 1, 0}));
}

// Тестирование поведения с пустым вектором
TEST(TopologySort, EmptyVector) {
  EXPECT_THROW(Rise_Temperature(std::vector<int>{}), WrongVector);
}

// Тестирование поведения с максимальными и минимальными значениями
TEST(TopologySort, ExtremeValues) {
  ASSERT_EQ(Rise_Temperature(std::vector<int>{-2, 0, 5}),
            (std::vector<int>{1, 1, 0}));
}
