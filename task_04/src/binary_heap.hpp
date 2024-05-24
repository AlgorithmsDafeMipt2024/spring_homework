#include <initializer_list>
#include <iostream>
#include <stdexcept>
#include <utility>
#include <vector>

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

  T operator[](size_t index) const {
    if (index > Size()) throw std::out_of_range("invalid index");

    return data[index];
  }

  const std::vector<T>& Data() const { return data; }

  void Add(T elem) {
    data.push_back(elem);
    SiftUp();
  }

  T ExtractMin() {
    if (Empty()) throw std::underflow_error("Heap is empty!");

    std::swap(data[0], data[Size() - 1]);
    data.pop_back();
    SiftDown();

    return data[0];
  }

  T GetMin() const {
    if (Empty()) throw std::underflow_error("Heap is empty!");

    return data[0];
  }

  size_t Size() const { return data.size(); }

  bool Empty() const { return Size() == 0; }

 private:
  size_t ParentOf(size_t index) const { return (index - 1) / 2; }

  size_t LeftChildOf(size_t index) const { return (2 * index + 1); }

  size_t RightChildOf(size_t index) const { return (2 * index + 2); }

  void SiftUp() {
    size_t index = Size() - 1;

    while (index > 0 && data[ParentOf(index)] > data[index]) {
      std::swap(data[index], data[ParentOf(index)]);
      index = ParentOf(index);
    }
  }

  void SiftDown(size_t index = 0) {
    while (index < Size()) {
      size_t current_index = index;

      if (LeftChildOf(index) < Size() &&
          data[LeftChildOf(index)] < data[current_index]) {
        current_index = LeftChildOf(index);
      }

      if (RightChildOf(index) < Size() &&
          data[RightChildOf(index)] < data[current_index]) {
        current_index = RightChildOf(index);
      }

      if (current_index == index) break;

      std::swap(data[index], data[current_index]);

      index = current_index;
    }
  }

  std::vector<T> data;
};

template <typename T>
class BinaryMaxHeap {
 public:
  BinaryMaxHeap() = default;
  BinaryMaxHeap(const std::vector<T>& data) {
    for (const auto& elem : data) Add(elem);
  }

  BinaryMaxHeap(const std::initializer_list<T>& data) {
    for (const auto& elem : data) Add(elem);
  }

  T operator[](size_t index) const {
    if (index > Size()) throw std::out_of_range("invalid index");

    return data[index];
  }

  const std::vector<T>& Data() const { return data; }

  void Add(T elem) {
    data.push_back(elem);
    SiftUp();
  }

  T ExtractMax() {
    if (Empty()) throw std::underflow_error("Heap is empty!");

    std::swap(data[0], data[Size() - 1]);
    data.pop_back();
    SiftDown();

    return data[0];
  }

  T GetMax() const {
    if (Empty()) throw std::underflow_error("Heap is empty!");

    return data[0];
  }

  size_t Size() const { return data.size(); }

  bool Empty() const { return Size() == 0; }

 private:
  size_t ParentOf(size_t index) const { return (index - 1) / 2; }

  size_t LeftChildOf(size_t index) const { return (2 * index + 1); }

  size_t RightChildOf(size_t index) const { return (2 * index + 2); }

  void SiftUp() {
    size_t index = Size() - 1;

    while (index > 0 && data[ParentOf(index)] < data[index]) {
      std::swap(data[index], data[ParentOf(index)]);
      index = ParentOf(index);
    }
  }

  void SiftDown(size_t index = 0) {
    while (index < Size()) {
      size_t current_index = index;

      if (LeftChildOf(index) < Size() &&
          data[LeftChildOf(index)] > data[current_index]) {
        current_index = LeftChildOf(index);
      }

      if (RightChildOf(index) < Size() &&
          data[RightChildOf(index)] > data[current_index]) {
        current_index = RightChildOf(index);
      }

      if (current_index == index) break;

      std::swap(data[index], data[current_index]);

      index = current_index;
    }
  }

  std::vector<T> data;
};