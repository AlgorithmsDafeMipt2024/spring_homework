#pragma once

#include <cstddef>
#include <stdexcept>
#include <vector>

template <typename T>
class Heap {
 public:
  Heap() : heap_array_(std::vector<T>{}){};
  explicit Heap(std::vector<T>&& array) {
    heap_array_ = std::move(array);
    for (size_t node = heap_array_.size(); node > 0; --node) SiftDown(node);
  }

  T Pop();

  T Top() const;

  void Push(T value);

  bool Empty() const;

  size_t Size() const;

 private:
  std::vector<T> heap_array_;

  void SiftUp(size_t node_index);

  void SiftDown(size_t node_index);
};

template <typename T>
bool Heap<T>::Empty() const {
  return (heap_array_.size() == 0);
}

template <typename T>
size_t Heap<T>::Size() const {
  return heap_array_.size();
}

template <typename T>
void Heap<T>::SiftUp(size_t node_index) {
  if (node_index <= 0) return;
  size_t parent_index = (node_index - 1) / 2;
  if (heap_array_[node_index] < heap_array_[parent_index]) {
    std::swap(heap_array_[node_index], heap_array_[parent_index]);
    SiftUp(parent_index);
  }
}

template <typename T>
void Heap<T>::SiftDown(size_t node_index) {
  size_t size = heap_array_.size();
  size_t left_child_index = 2 * node_index + 1;
  size_t right_child_index = 2 * node_index + 2;
  size_t smallest_child_index = node_index;
  if (left_child_index < size &&
      heap_array_[left_child_index] < heap_array_[smallest_child_index])
    smallest_child_index = left_child_index;
  if (right_child_index < size &&
      heap_array_[right_child_index] < heap_array_[smallest_child_index])
    smallest_child_index = right_child_index;
  if (smallest_child_index != node_index) {
    std::swap(heap_array_[smallest_child_index], heap_array_[node_index]);
    SiftDown(smallest_child_index);
  }
}

template <typename T>
void Heap<T>::Push(T value) {
  heap_array_.emplace_back(value);
  SiftUp(heap_array_.size() - 1);
}

template <typename T>
T Heap<T>::Top() const {
  if (Empty()) throw std::runtime_error("Heap is empty");
  return heap_array_[0];
}

template <typename T>
T Heap<T>::Pop() {
  T top = Top();
  std::swap(heap_array_[0], heap_array_.back());
  heap_array_.pop_back();
  SiftDown(0);
  return top;
}