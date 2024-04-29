#include <functional>
#include <random>
#include <vector>

/**
 * @brief Выбор случайного опорного элемента (пивота)
 * @param left: левая граница диапазона
 * @param right: правая граница диапазона
 * @return size_t: случайный индекс в диапазоне [left, right]
 */
static size_t RandomPivotIndex(size_t left, size_t right) {
  static std::random_device rd;
  static std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(left, right);
  return dis(gen);
}

/**
 * @brief Разбиение массива вокруг опорного элемента (пивота)
 * @tparam T: тип элементов вектора
 * @param data: ссылка на вектор
 * @param left: левая граница диапазона разбиения
 * @param right: правая граница диапазона разбиения
 * @return size_t: индекс опорного элемента после разбиения
 */
template <typename T>
static size_t Partition(std::vector<T>& data, size_t left, size_t right) {
  size_t pivot_index = RandomPivotIndex(left, right);
  std::swap(data[pivot_index], data[right]);
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
void QuickSort(std::vector<T>& data) {
  if (data.empty()) return;

  size_t left = 0;
  size_t right = data.size() - 1;

  std::function<void(size_t, size_t)> QuickSortRecursive = [&](size_t l,
                                                               size_t r) {
    if (l < r) {
      size_t pivot_index = Partition(data, l, r);
      QuickSortRecursive(l, pivot_index - 1);
      QuickSortRecursive(pivot_index + 1, r);
    }
  };

  QuickSortRecursive(left, right);
}
