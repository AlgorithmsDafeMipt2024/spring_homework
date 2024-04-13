#include <cstddef>
#include <functional>
#include <initializer_list>
#include <vector>

// default constructor works only if your custom type is comparable!
template <typename T>
class heap {
 public:
  heap();
  heap(std::function<bool(const T&, const T&)> function);
  heap(std::initializer_list<T> initializer_list);
  heap(std::initializer_list<T> initializer_list,
       std::function<bool(const T&, const T&)> function);

  void push(T element);
  T extract_bottom_element();

 private:
  void sift_down(size_t index);
  void sift_up(size_t index);
  size_t heap_size;

  std::function<bool(const T&, const T&)> comparing_function;
  std::vector<T> data;
};

template <typename T>
heap<T>::heap() : data{}, heap_size{0} {
  comparing_function = [](const T& a, const T& b) { return a < b; };
}

template <typename T>
heap<T>::heap(std::function<bool(const T&, const T&)> function)
    : data{}, heap_size{0}, comparing_function{function} {}

template <typename T>
heap<T>::heap(std::initializer_list<T> initializer_list) {
  comparing_function = [](const T& a, const T& b) { return a < b; };

  for (const T& value : initializer_list) data.push_back(value);
  heap_size = data.size();
}

template <typename T>
heap<T>::heap(std::initializer_list<T> initializer_list,
              std::function<bool(const T&, const T&)> function)
    : comparing_function{function} {
  for (const T& value : initializer_list) data.push_back(value);
}

// time complexity - O(logn)
template <typename T>
void heap<T>::sift_down(size_t index) {
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
void heap<T>::sift_up(size_t index) {
  while (comparing_function(data[index], data[(index - 1) / 2])) {
    std::swap(data[index], data[(index - 1) / 2]);
    index = (index - 1) / 2;
  }
}

// time complexity - O(logn)
template <typename T>
T heap<T>::extract_bottom_element() {
  T bottom = data[0];
  data[0] = data[heap_size - 1];
  heap_size--;
  sift_down(0);

  return bottom;
}

template <typename T>
void heap<T>::push(T element) {}