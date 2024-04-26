#include "k_stat.hpp"
#include <gtest/gtest.h>
#include <numeric>
#include <stdexcept>

// Простое тестирование
TEST(k_stat, Simple) {
  std::vector<int> vec1{14, -1, 5, 21, 6, -3, 7, 93, 9, 0, 84};
  ASSERT_EQ(FindOrderStatistic(vec1, 8), 21);
  ASSERT_EQ(FindOrderStatistic(vec1, 3), 5);
  ASSERT_EQ(FindOrderStatistic(vec1, 10), 93);
  EXPECT_THROW(FindOrderStatistic(vec1, 13), std::logic_error);
  std::vector<int> vec2{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  ASSERT_EQ(FindOrderStatistic(vec2, 4), 5);
  vec2.pop_back();
  vec2.pop_back();
  vec2.push_back(-12);
  vec2.push_back(100);
  vec2.push_back(134);
  ASSERT_EQ(FindOrderStatistic(vec2, 9), 100);
}

// Тестирование поиска k-й порядковой статистики в случайном массиве
TEST(k_stat, RandomArray) {
  std::vector<int> vec{10, 85, -24, 45, 28, 5, 12, -90, 67};
  ASSERT_EQ(FindOrderStatistic(vec, 0), -90);
  ASSERT_EQ(FindOrderStatistic(vec, 2), 5);
  ASSERT_EQ(FindOrderStatistic(vec, 5), 28);
  ASSERT_EQ(FindOrderStatistic(vec, 8), 85);
}

// Тестирование поиска k-й порядковой статистики в отсортированном массиве
TEST(k_stat, SortedArray) {
  std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9};
  ASSERT_EQ(FindOrderStatistic(vec, 0), 1);
  ASSERT_EQ(FindOrderStatistic(vec, 3), 4);
  ASSERT_EQ(FindOrderStatistic(vec, 8), 9);
}

// Тестирование поиска k-й порядковой статистики в массиве с повторяющимися
// элементами
TEST(k_stat, RepeatedElements) {
  std::vector<int> vec{4, 2, 4, 2, 4, 2};
  ASSERT_EQ(FindOrderStatistic(vec, 2), 2);
  ASSERT_EQ(FindOrderStatistic(vec, 5), 4);
}

// Тестирование поиска k-й порядковой статистики в массиве с отрицательными
// числами
TEST(k_stat, NegativeNumbers) {
  std::vector<int> vec{-5, -1, -3, -4, -2};
  ASSERT_EQ(FindOrderStatistic(vec, 0), -5);
  ASSERT_EQ(FindOrderStatistic(vec, 4), -1);
}

// Тестирование поиска k-й порядковой статистики в массиве с одинаковыми
// элементами
TEST(k_stat, UniformElements) {
  std::vector<int> vec{5, 5, 5, 5, 5};
  ASSERT_EQ(FindOrderStatistic(vec, 0), 5);
  ASSERT_EQ(FindOrderStatistic(vec, 4), 5);
}

// Тестирование на выброс исключения при некорректном k
TEST(k_stat, OutOfBounds) {
  std::vector<int> vec{3, 1, 4};
  EXPECT_THROW(FindOrderStatistic(vec, 4), std::logic_error);
  EXPECT_THROW(FindOrderStatistic(vec, -1), std::logic_error);
}

// Тестирование поиска k-й порядковой статистики в большом массиве
TEST(k_stat, LargeArray) {
  std::vector<int> vec(1000);
  std::iota(vec.begin(), vec.end(),
            1); // Заполнение массива числами от 1 до 1000
  std::random_shuffle(vec.begin(), vec.end()); // Перемешивание элементов
  ASSERT_EQ(FindOrderStatistic(vec, 499), 484);
}
