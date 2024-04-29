#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

/**
 * @brief Выбор случайного опорного элемента (пивота)
 * @param left: левая граница диапазона
 * @param right: правая граница диапазона
 * @return size_t: случайный индекс в диапазоне [left, right]
 */
static size_t RandomPivotIndex(size_t left, size_t right) {
  return left + rand() % (right - left + 1);
}

/**
 * @brief Разбиение массива вокруг опорного элемента (пивота)
 * @tparam T: тип элементов вектора
 * @param arr: ссылка на вектор
 * @param left: левая граница диапазона разбиения
 * @param right: правая граница диапазона разбиения
 * @return size_t: индекс опорного элемента после разбиения
 */
template <typename T>
static size_t Partition(std::vector<T>& data, size_t left, size_t right) {
  size_t pivotIndex = RandomPivotIndex(left, right);
  std::swap(data[pivotIndex], data[right]);
  size_t storeIndex = left;

  for (size_t i = left; i < right; i++) {
    if (data[i] < data[right]) {
      std::swap(data[i], data[storeIndex]);
      storeIndex++;
    }
  }

  std::swap(data[right], data[storeIndex]);
  return storeIndex;
}

// MARK: QuickSort

/**
 * @brief Быстрая сортировка — один из самых известных и широко используемых
алгоритмов сортировки. Среднее время работы O(nlogn), что является
асимптотически оптимальным временем работы для алгоритма, основанного на
сравнении
 * @tparam T: тип элементов вектора
 * @param data: сортируемый вектор
 */
template <typename T>
static void QuickSort(std::vector<T>& data) {
  size_t left = 0;
  size_t right = data.size() - 1;

  if (left < right) {
    size_t pivotIndex = Partition(data, left, right);
    QuickSort(data, left, pivotIndex - 1);
    QuickSort(data, pivotIndex + 1, right);
  }
}
