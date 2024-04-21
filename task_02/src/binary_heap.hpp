#include <vector>

/**
 * @brief реализация двоичной min-heap на std::vector
 * @tparam T: тип значений двоичной кучи
 */
template <typename T>
class BinaryMinHeap {
 public:
  BinaryMinHeap() = default;

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

 private:
  std::vector<T> data_;
};