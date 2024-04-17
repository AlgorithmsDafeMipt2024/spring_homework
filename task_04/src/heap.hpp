#pragma once
#include <concepts>
#include <cstddef>
#include <functional>
#include <initializer_list>
#include <stdexcept>
#include <vector>

// concept to check if the type is comparable (now obsolete)
template <typename CustomType>
concept comparable = requires(CustomType a, CustomType b) {
  a < b;
  a <= b;
  a == b;
  a >= b;
  a > b;
  a != b;
};

// concept to check if the type is comparable with a concrete function
template <typename Function, typename CustomType>
concept comparing = requires(CustomType a, CustomType b, Function f) {
  f(a, b);
};

// default constructor works only if your custom type is comparable!
template <typename CustomType,
          comparing<CustomType> Function =
              std::function<bool(const CustomType&, const CustomType&)>>
class heap {
 public:
  heap();
  heap(std::function<bool(const CustomType&, const CustomType&)>
           comparing_function_);
  explicit heap(std::initializer_list<CustomType> initializer_list);
  explicit heap(std::function<bool(const CustomType&, const CustomType&)>
                    comparing_function_,
                std::initializer_list<CustomType> initializer_list);
  void push(CustomType element);
  CustomType pop_bottom();
  CustomType bottom();
  size_t size() { return heap_size; }
  bool empty() { return heap_size == 0; }

 private:
  void sift_down(size_t index);
  void sift_up(size_t index);
  size_t heap_size;

  std::function<bool(const CustomType&, const CustomType&)> comparing_function;
  std::vector<CustomType> data;
};

// time complexity - O(1)
template <typename CustomType, comparing<CustomType> Function>
heap<CustomType, Function>::heap() : data{}, heap_size{0} {
  comparing_function = [](const CustomType& a, const CustomType& b) {
    return a < b;
  };
}

// time complexity - O(1)
template <typename CustomType, comparing<CustomType> Function>
heap<CustomType, Function>::heap(
    std::function<bool(const CustomType&, const CustomType&)>
        comparing_function_)
    : data{}, heap_size{0} {
  comparing_function = comparing_function_;
}

// time complexity - O(nlogn)
template <typename CustomType, comparing<CustomType> Function>
heap<CustomType, Function>::heap(
    std::initializer_list<CustomType> initializer_list)
    : heap() {
  comparing_function = [](const CustomType& a, const CustomType& b) {
    return a < b;
  };

  for (const CustomType& value : initializer_list) push(value);
}

// time complexity - O(nlogn)
template <typename CustomType, comparing<CustomType> Function>
heap<CustomType, Function>::heap(
    std::function<bool(const CustomType&, const CustomType&)>
        comparing_function_,
    std::initializer_list<CustomType> initializer_list)
    : comparing_function{comparing_function_} {
  for (const CustomType& value : initializer_list) push(value);
}

// time complexity - O(logn)
template <typename CustomType, comparing<CustomType> Function>
void heap<CustomType, Function>::sift_down(size_t index) {
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
template <typename CustomType, comparing<CustomType> Function>
void heap<CustomType, Function>::sift_up(size_t index) {
  while (comparing_function(data[index], data[(index - 1) / 2])) {
    std::swap(data[index], data[(index - 1) / 2]);
    index = (index - 1) / 2;
  }
}

// time complexity - O(1)
template <typename CustomType, comparing<CustomType> Function>
CustomType heap<CustomType, Function>::bottom() {
  if (empty()) throw std::runtime_error("heap is empty");
  return data[0];
}

// time complexity - O(logn)
template <typename CustomType, comparing<CustomType> Function>
CustomType heap<CustomType, Function>::pop_bottom() {
  CustomType bottom_elem = bottom();
  std::swap(data[0], data.back());
  data.pop_back();
  heap_size--;
  sift_down(0);
  return bottom_elem;
}

// time complexity - O(logn)
template <typename CustomType, comparing<CustomType> Function>
void heap<CustomType, Function>::push(CustomType element) {
  data.push_back(element);
  heap_size++;
  if (heap_size >= 2) sift_up(heap_size - 1);
}