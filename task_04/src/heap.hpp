#include <concepts>
#include <cstddef>
#include <functional>
#include <initializer_list>
#include <stdexcept>
#include <vector>

// try to deduce if type is comparable (naive solution)
template <typename T>
constexpr bool is_comparable() {
  T a{};
  try {
    bool attempt_to_compate = a < a;
  } catch (...) {
    return false;
  }
  return true;
}

// default constructor works only if your custom type is comparable!
template <typename T>
requires(is_comparable<T>()) class heap {
 public:
  heap();
  explicit heap(std::initializer_list<T> initializer_list);
  void push(T element);
  T pop_bottom();
  T bottom();
  size_t size() { return heap_size; }
  bool empty() { return heap_size == 0; }

 private:
  void sift_down(size_t index);
  void sift_up(size_t index);
  size_t heap_size;

  std::function<bool(const T&, const T&)> comparing_function;
  std::vector<T> data;
};

// time complexity - O(1)
template <typename T>
requires(is_comparable<T>()) heap<T>::heap() : data{}, heap_size{0} {
  comparing_function = [](const T& a, const T& b) { return a < b; };
}

// time complexity - O(nlogn)
template <typename T>
requires(is_comparable<T>()) heap<T>::heap(
    std::initializer_list<T> initializer_list)
    : heap()  // requires( is_comparable<T>())
{
  comparing_function = [](const T& a, const T& b) { return a < b; };

  for (const T& value : initializer_list) push(value);
}

// time complexity - O(logn)
template <typename T>
requires(is_comparable<T>()) void heap<T>::sift_down(size_t index) {
  size_t& index_1 = index;  // for code to be more readable

  while (2 * index_1 + 1 < heap_size) {
    size_t left_child = 2 * index_1 + 1;
    size_t right_child = 2 * index_1 + 2;
    size_t index_2 = left_child;

    if ((right_child < heap_size) &&
        comparing_function(data[right_child], data[left_child]))
      index_2 = right_child;
    if (comparing_function(data[index_1], data[index_2]) ||
        (data[index_1] == data[index_2]))
      break;

    std::swap(data[index_1], data[index_2]);
    index_1 = index_2;
  }
}

// time complexity - O(logn)
template <typename T>
requires(is_comparable<T>()) void heap<T>::sift_up(size_t index) {
  while (comparing_function(data[index], data[(index - 1) / 2])) {
    std::swap(data[index], data[(index - 1) / 2]);
    index = (index - 1) / 2;
  }
}

// time complexity - O(1)
template <typename T>
requires(is_comparable<T>()) T heap<T>::bottom() {
  if (empty()) throw std::runtime_error("heap is empty");
  return data[0];
}

// time complexity - O(logn)
template <typename T>
requires(is_comparable<T>()) T heap<T>::pop_bottom() {
  T bottom_elem = bottom();
  std::swap(data[0], data.back());
  data.pop_back();
  heap_size--;
  sift_down(0);
  return bottom_elem;
}

// time complexity - O(logn)
template <typename T>
requires(is_comparable<T>()) void heap<T>::push(T element) {
  data.push_back(element);
  heap_size++;
  sift_up(heap_size - 1);
}