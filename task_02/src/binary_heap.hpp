#include <vector>

/**
 * @brief реализация двоичной min-heap на std::vector
 * @tparam T: тип значений двоичной кучи
 */
template <typename T>
class BinaryMinHeap {
 public:
  BinaryMinHeap() = default;

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
   * @brief Доступ к данным кучи (&)
   * @return std::vector<T>&: вектор всех элементов
   */
  std::vector<T>& Data() { return data_; }

  /**
   * @brief Доступ к данным кучи (const &)
   * @return const std::vector<T>&: вектор всех элементов
   */
  operator const std::vector<T>&() const { return Data(); }

  /**
   * @brief Доступ к данным кучи (&)
   * @return std::vector<T>&: вектор всех элементов
   */
  operator std::vector<T>&() { return Data(); }

 private:
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
   * @brief Доступ к данным кучи (&)
   * @return std::vector<T>&: вектор всех элементов
   */
  std::vector<T>& Data() { return data_; }

  /**
   * @brief Доступ к данным кучи (const &)
   * @return const std::vector<T>&: вектор всех элементов
   */
  operator const std::vector<T>&() const { return Data(); }

  /**
   * @brief Доступ к данным кучи (&)
   * @return std::vector<T>&: вектор всех элементов
   */
  operator std::vector<T>&() { return Data(); }

 private:
  std::vector<T> data_;
};