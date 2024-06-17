#include <algorithm>
#include <iostream>
#include <vector>

/**
 * @brief Разбивает вектор вокруг опорного элемента.
 * @tparam T: тип элементов в векторе
 * @param data: вектор, который нужно разбить
 * @param left: левый индекс диапазона, который нужно разбить
 * @param right: правый индекс диапазона, который нужно разбить
 * @return индекс опорного элемента после разбиения
 */
template <typename T>
size_t Partition(std::vector<T>& data, size_t left, size_t right) {
  T pivot = data[right];
  size_t i = left;

  for (size_t j = left; j < right; j++)
    if (data[j] < pivot) {
      std::swap(data[i], data[j]);
      i++;
    }

  std::swap(data[i], data[right]);
  return i;
}

/**
 * @brief Находит n-ю порядковую статистику (n-й наименьший элемент) в векторе.
 * @tparam T: тип элементов в векторе
 * @param data: вектор, в котором нужно найти n-ю порядковую статистику
 * @param n: порядок статистики, которую нужно найти (индекс начиная с 1)
 * @return n-я порядковая статистика в векторе
 */
template <typename T>
T FindNOrderStatistic(std::vector<T>& data, size_t n) {
  size_t k = data.size();
  size_t left = 0, right = k - 1;

  while (left <= right) {
    size_t pivot_index = Partition(data, left, right);

    if (pivot_index == n - 1)
      return data[pivot_index];

    else if (pivot_index > n - 1)
      right = pivot_index - 1;

    else
      left = pivot_index + 1;
  }

  return T();
}
