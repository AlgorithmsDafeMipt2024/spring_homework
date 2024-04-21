#include <initializer_list>
#include <utility>
#include <vector>

/**
 * @brief реализация двоичной min-heap на std::vector
 * @tparam T: тип значений двоичной кучи
 */
template <typename T>
class BinaryMinHeap {
 public:
  BinaryMinHeap() = default;
  BinaryMinHeap(const std::vector<T>& data) : data_{data} { Heapify(); }
  BinaryMinHeap(const std::initializer_list<T>& data) : data_{data} {
    Heapify();
  }

  /**
   * @brief Доступ к копиям элементов кучи по индексу
   * @param index
   * @return T: элемент по индексу
   */
  T operator[](size_t index) const { return data_[index]; }

  /**
   * @brief Доступ к данным кучи (const &)
   * @return const std::vector<T>&: вектор всех элементов
   */
  const std::vector<T>& Data() const { return data_; }

  /**
   * @brief Доступ к данным кучи (const &)
   * @return const std::vector<T>&: вектор всех элементов
   */
  explicit operator const std::vector<T>&() const { return Data(); }

  /**
   * @brief Добавляет элемент в кучу
   * @param elem: значение элемента
   */
  void Add(T elem) {
    data_.push_back(elem);
    Heapify();
  }

  /**
   * @brief Удаляет элемент из кучи по индексу
   * @param index: индекс удаляемого элемента
   */
  void Remove(size_t index);

  /**
   * @brief Возвращает элемент, который находится выше
   * @param index: индекс элемента, выше которого нужное значение
   * @return T: элемент, который находится выше
   */
  T ParentOf(size_t index) const { return (index - 1) / 2; }

  /**
   * @brief Возвращает элемент, который находится левее
   * @param index: индекс элемента, левее которого нужное значение
   * @return T: элемент, который находится левее
   */
  T LeftOf(size_t index) const { return (2 * index + 1); }

  /**
   * @brief Возвращает элемент, который находится правее
   * @param index: индекс элемента, правее которого нужное значение
   * @return T: элемент, который находится правее
   */
  T RightOf(size_t index) const { return (2 * index + 2); }

  /**
   * @brief Вырезает минимум (корень) из кучи
   * @return T: значение этого минимума (корня)
   */
  T ExtractMin();

  /**
   * @brief Вырезает корень (минимум) из кучи
   * @return T: значение этого корня (минимума)
   */
  T ExtractRoot() { return ExtractMin(); }

  /**
   * @brief Возвращает значение минимума (корня)
   * @return T: значение минимума (корня)
   */
  T GetMin() const { return Data()[0]; }

  /**
   * @brief Возвращает значение корня (минимума)
   * @return T: значение корня (минимума)
   */
  T GetRoot() const { return GetMin(); }

  /**
   * @brief Устанавливает значение элемента кучи по индексу
   * @param index: индекс изменяемого элемента
   */
  void SetValue(size_t index);

 private:
  ///@brief Приводит кучу в валидное состояние
  void Heapify() {
    // идем с конца по родителям
    size_t i = Data().size() - 1;

    // пока следующий родитель больше, меняем местами
    while (i > 0 && data_[ParentOf(i)] > data_[i]) {
      std::swap(data_[i], data_[ParentOf(i)]);
      i = ParentOf(i);
    }
  }

  /// @brief Данные кучи
  std::vector<T> data_;
};

/**
 * @brief реализация двоичной max-heap на std::vector
 * @tparam T: тип значений двоичной кучи
 */
template <typename T>
class BinaryMaxHeap {
 public:
  BinaryMaxHeap() = default;
  BinaryMaxHeap(const std::vector<T>& data) : data_{data} { Heapify(); }
  BinaryMaxHeap(const std::initializer_list<T>& data) : data_{data} {
    Heapify();
  }

  /**
   * @brief Доступ к копиям элементов кучи по индексу
   * @param index
   * @return T: элемент по индексу
   */
  T operator[](size_t index) const { return data_[index]; }

  /**
   * @brief Доступ к данным кучи (const &)
   * @return const std::vector<T>&: вектор всех элементов
   */
  const std::vector<T>& Data() const { return data_; }

  /**
   * @brief Доступ к данным кучи (const &)
   * @return const std::vector<T>&: вектор всех элементов
   */
  explicit operator const std::vector<T>&() const { return Data(); }

  /**
   * @brief Добавляет элемент в кучу
   * @param elem: значение элемента
   */
  void Add(T elem) {
    data_.push_back(elem);
    Heapify();
  }

  /**
   * @brief Удаляет элемент из кучи по индексу
   * @param index: индекс удаляемого элемента
   */
  void Remove(size_t index);

  /**
   * @brief Возвращает элемент, который находится выше
   * @param index: индекс элемента, выше которого нужное значение
   * @return T: элемент, который находится выше
   */
  T ParentOf(size_t index) const { return (index - 1) / 2; }

  /**
   * @brief Возвращает элемент, который находится левее
   * @param index: индекс элемента, левее которого нужное значение
   * @return T: элемент, который находится левее
   */
  T LeftOf(size_t index) const { return (2 * index + 1); }

  /**
   * @brief Возвращает элемент, который находится правее
   * @param index: индекс элемента, правее которого нужное значение
   * @return T: элемент, который находится правее
   */
  T RightOf(size_t index) const { return (2 * index + 2); }

  /**
   * @brief Вырезает максимум (корень) из кучи
   * @return T: значение этого максимума (корня)
   */
  T ExtractMax();

  /**
   * @brief Вырезает корень (максимум) из кучи
   * @return T: значение этого корня (максимума)
   */
  T ExtractRoot() { return ExtractMax(); }

  /**
   * @brief Возвращает значение максимума (корня)
   * @return T: значение максимума (корня)
   */
  T GetMax() const { return Data()[0]; }

  /**
   * @brief Возвращает значение корня (максимума)
   * @return T: значение корня (максимума)
   */
  T GetRoot() const { return GetMax(); }

  /**
   * @brief Устанавливает значение элемента кучи по индексу
   * @param index: индекс изменяемого элемента
   */
  void SetValue(size_t index);

 private:
  ///@brief Приводит кучу в валидное состояние
  void Heapify() {
    // идем с конца по родителям
    size_t i = Data().size() - 1;

    // пока следующий родитель меньше, меняем местами
    while (i > 0 && data_[ParentOf(i)] < data_[i]) {
      std::swap(data_[i], data_[ParentOf(i)]);
      i = ParentOf(i);
    }
  }

  /// @brief Данные кучи
  std::vector<T> data_;
};