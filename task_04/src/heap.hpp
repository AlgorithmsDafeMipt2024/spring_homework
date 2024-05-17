#pragma once
#include <concepts>
#include <cstddef>
#include <functional>
#include <initializer_list>
#include <stdexcept>
#include <vector>

template <typename CustomType>
concept constructable = requires(CustomType a, CustomType b) {
  a = CustomType{};
  b = CustomType{a};
};

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

// data structure that allows to retrieve minimal element with O(1) time
// complexity and pop a minimal element with O(logn) time complexity
template <constructable CustomType,
          comparing<CustomType> Function =
              std::function<bool(const CustomType&, const CustomType&)>>
class Heap {
 public:
  // default constructor works only if your custom type is comparable!
  Heap();
  // this constructor works only if your custom type is comparable with a
  // function
  Heap(std::function<bool(const CustomType&, const CustomType&)>
           comparing_function_);
  explicit Heap(std::initializer_list<CustomType> initializer_list);
  explicit Heap(std::function<bool(const CustomType&, const CustomType&)>
                    comparing_function_,
                std::initializer_list<CustomType> initializer_list);
  // push an element into heap, O(logn) time complexity
  void Push(CustomType element);
  // pop a minimal element from heap, O(logn) time complexity
  CustomType PopBottom();
  // retrieve a minimal element from heap, O(1) time complexity
  CustomType Bottom();
  // return size of heap
  size_t Size() { return heap_size; }
  // check if heap is empty
  bool Empty() { return heap_size == 0; }

 private:
  // bring minimal element back to place if element with given index is
  // increased
  void SiftDown(size_t index);
  // bring minimal element back to place if element with given index is decreaed
  void SiftUp(size_t index);
  size_t heap_size;

  std::function<bool(const CustomType&, const CustomType&)> comparing_function;
  std::vector<CustomType> data;
};

// time complexity - O(1)
template <constructable CustomType, comparing<CustomType> Function>
Heap<CustomType, Function>::Heap() : data{}, heap_size{0} {
  comparing_function = [](const CustomType& a, const CustomType& b) {
    return a < b;
  };
}

// time complexity - O(1)
template <constructable CustomType, comparing<CustomType> Function>
Heap<CustomType, Function>::Heap(
    std::function<bool(const CustomType&, const CustomType&)>
        comparing_function_)
    : data{}, heap_size{0} {
  comparing_function = comparing_function_;
}

// time complexity - O(nlogn)
template <constructable CustomType, comparing<CustomType> Function>
Heap<CustomType, Function>::Heap(
    std::initializer_list<CustomType> initializer_list)
    : Heap() {
  comparing_function = [](const CustomType& a, const CustomType& b) {
    return a < b;
  };

  for (const CustomType& value : initializer_list) Push(value);
}

// time complexity - O(nlogn)
template <constructable CustomType, comparing<CustomType> Function>
Heap<CustomType, Function>::Heap(
    std::function<bool(const CustomType&, const CustomType&)>
        comparing_function_,
    std::initializer_list<CustomType> initializer_list)
    : comparing_function{comparing_function_} {
  for (const CustomType& value : initializer_list) Push(value);
}

// time complexity - O(logn)
template <constructable CustomType, comparing<CustomType> Function>
void Heap<CustomType, Function>::SiftDown(size_t index) {
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
template <constructable CustomType, comparing<CustomType> Function>
void Heap<CustomType, Function>::SiftUp(size_t index) {
  while (comparing_function(data[index], data[(index - 1) / 2])) {
    std::swap(data[index], data[(index - 1) / 2]);
    index = (index - 1) / 2;
  }
}

// time complexity - O(1)
template <constructable CustomType, comparing<CustomType> Function>
CustomType Heap<CustomType, Function>::Bottom() {
  if (Empty()) throw std::runtime_error("heap is empty");
  return data[0];
}

// time complexity - O(logn)
template <constructable CustomType, comparing<CustomType> Function>
CustomType Heap<CustomType, Function>::PopBottom() {
  CustomType bottom_elem = Bottom();
  std::swap(data[0], data.back());
  data.pop_back();
  heap_size--;
  SiftDown(0);
  return bottom_elem;
}

// time complexity - O(logn)
template <constructable CustomType, comparing<CustomType> Function>
void Heap<CustomType, Function>::Push(CustomType element) {
  data.push_back(element);
  heap_size++;
  if (heap_size >= 2) SiftUp(heap_size - 1);
}