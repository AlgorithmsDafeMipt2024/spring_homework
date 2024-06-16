#include <initializer_list>
#include <iostream>
#include <stdexcept>
#include <utility>
#include <vector>

/**
 * @brief Двоичная куча на std::vector с доступом к минимальному элементу
 * @tparam T: Тип данных в двоичной кучи
 */
template <typename T>
class BinaryMinHeap {
 public:
  BinaryMinHeap() = default;
  BinaryMinHeap(const std::vector<T>& data) {
    for (const auto& elem : data) Add(elem);
  }

  BinaryMinHeap(const std::initializer_list<T>& data) {
    for (const auto& elem : data) Add(elem);
  }

  /**
   * @brief Индексация элементов кучи
   * @param index
   * @return T: Значение элемента
   * @throw std::out_of_range: Индекс больше размера кучи
   */
  T operator[](size_t index) const {
    if (index > Size()) throw std::out_of_range("invalid index");

    return data_[index];
  }

  /**
   * @brief Доступ к данным кучи (const &)
   * @return const std::vector<T>&: все элементов
   */
  const std::vector<T>& Data() const { return data_; }

  /**
   * @brief Доступ к данным кучи (const &)
   * @return const std::vector<T>&: вектор всех элементов
   */
  explicit operator const std::vector<T>&() const { return Data(); }

  /**
   * @brief Добавление элемента в кучу
   * @param elem: Значение нового элемента
   */
  void Add(T elem) {
    data_.push_back(elem);
    SiftUp();
  }

  /**
   * @brief Вырезает корень кучи
   * @return T: Значение корня
   * @throw std::out_of_range: Куча пуста
   */
  T ExtractMin() {
    if (Empty()) throw std::out_of_range("empty heap");

    auto res = Data()[0];

    // меняем местами минимум с последним
    std::swap(data_[0], data_[Size() - 1]);
    data_.pop_back();
    SiftDown();

    return res;
  }

  /**
   * @brief Возвращает значение корня
   * @return T: Значение корня
   * @throw std::out_of_range: Куча пуста
   */
  T GetMin() const {
    if (Empty()) throw std::out_of_range("empty heap");

    return Data()[0];
  }

  size_t Size() const { return data_.size(); }

  bool Empty() const { return Size() == 0; }

 private:
  /**
   * @brief Возвращает индекс родителя
   * @param index: Индекс элемента
   * @return size_t: Индекс родителя
   */
  size_t ParentIndex(size_t index) const { return (index - 1) / 2; }

  /**
   * @brief Возвращает индекс левого ребенка
   * @param index: Индекс элемента
   * @return size_t: Индекс левого ребенка
   */
  size_t LeftChildIndex(size_t index) const { return (2 * index + 1); }

  /**
   * @brief Возвращает индекс правого ребенка
   * @param index: Индекс элемента
   * @return size_t: Индекс правого ребенка
   */
  size_t RightChildIndex(size_t index) const { return (2 * index + 2); }

  /// @brief Корректирует кучу после добавления элемента
  void SiftUp() {
    // начинаем с конца
    size_t index = Size() - 1;

    // меняем элемент с родителям местами, пока последний больше
    while (index > 0 && data_[ParentIndex(index)] > data_[index]) {
      std::swap(data_[index], data_[ParentIndex(index)]);
      index = ParentIndex(index);
    }
  }

  /// @brief Корректирует кучу после удаления элемента
  void SiftDown(size_t index = 0) {
    while (index < Size()) {
      size_t smallest = index;  // индекс кореня поддерева

      // если левый ребенок существует и меньше текущего наименьшего элемента
      if (LeftChildIndex(index) < Size() &&
          data_[LeftChildIndex(index)] < data_[smallest]) {
        smallest = LeftChildIndex(index);
      }

      // если правый ребенок существует и меньше текущего наименьшего элемента
      if (RightChildIndex(index) < Size() &&
          data_[RightChildIndex(index)] < data_[smallest]) {
        smallest = RightChildIndex(index);
      }

      // если текущий элемент не меньше своих детей, завершаем итерацию
      if (smallest == index) break;

      // меняем местами текущий элемент с наименьшим из детей
      std::swap(data_[index], data_[smallest]);

      // переходим вниз по дереву к ребенку, с которым произвели обмен
      index = smallest;
    }
  }

  /// @brief Элементы кучи
  std::vector<T> data_;
};
