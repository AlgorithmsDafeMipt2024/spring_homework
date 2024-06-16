#include <vector>

/**
 * @brief Сливает две отсортированные части вектора в один
 * @tparam T: Тип элементов вектора
 * @param data: Данные двух векторов
 * @param left: Индекс начала первого вектора
 * @param mid: Индекс конца первого вектора и начала второго вектора
 * @param right: Индекс конца второго вектора
 */
template <typename T>
static void Merge(std::vector<T>& data, std::size_t left, std::size_t mid,
                  std::size_t right) {
  std::size_t index_1 = 0;  // индекс для первой части
  std::size_t index_2 = 0;  // индекс для второй части

  /// @brief Вспомогательный вектор для слияния
  std::vector<T> res(right - left);

  // Сливаем два вектора, пока не достигнем конца одного из них
  while (left + index_1 < mid && mid + index_2 < right) {
    if (data[left + index_1] < data[mid + index_2]) {
      // берем элемент из первой части
      res[index_1 + index_2] = data[left + index_1];
      index_1++;

    } else {
      // берем элемент из второй части
      res[index_1 + index_2] = data[mid + index_2];
      index_2++;
    }
  }

  // Копируем остаток первого вектора, если он не кончился
  while (left + index_1 < mid) {
    res[index_1 + index_2] = data[left + index_1];
    index_1++;
  }

  // Копируем остаток первого вектора, если он не кончился
  while (mid + index_2 < right) {
    res[index_1 + index_2] = data[mid + index_2];
    index_2++;
  }

  // Копируем результат слияния в исходный вектор
  for (std::size_t i = 0; i < index_1 + index_2; i++) data[left + i] = res[i];
}

/**
 * @brief Сортировка слиянием — алгоритм сортировки, использующий O(n)
 * дополнительной памяти и работающий за O(nlog(n)) времени
 * @tparam T: Тип данных
 * @param data: Данные
 */
template <typename T>
void MergeSort(std::vector<T>& data) {
  if (data.empty()) return;

  auto n = data.size();

  for (std::size_t i = 1; i < n; i *= 2)
    for (std::size_t j = 0; j < n - i; j += 2 * i)
      Merge(data, j, j + i, std::min(j + 2 * i, n));
}