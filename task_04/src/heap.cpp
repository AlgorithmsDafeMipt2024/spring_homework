#include "heap.hpp"

#include <cstddef>
#include <stdexcept>
#include <vector>

void Heap::SiftUp(int index) {
  while (index >= 0 && heap_[index] < heap_[(index - 1) / 2]) {
    std::swap(heap_[index], heap_[(index - 1) / 2]);
    index = (index - 1) / 2;
  }
}

void Heap::SiftDown(int index) {
  while (2 * index + 1 < heap_.size()) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int small_child_index = left;
    if (right < heap_.size() && heap_[right] < heap_[left]) {
      small_child_index = right;
    }
    if (heap_[index] < heap_[small_child_index]) {
      break;
    }
    std::swap(heap_[index], heap_[small_child_index]);
    index = small_child_index;
  }
}

int Heap::Min() {
  if (Size() == 0) throw std::runtime_error("Empty Heap");
  int m = heap_[0];
  std::swap(heap_[0], heap_[heap_.size() - 1]);
  heap_.pop_back();
  SiftDown(0);
  return m;
}

void Heap::Insert(int value) {
  heap_.push_back(value);
  this->SiftUp(heap_.size() - 1);
}

void Heap::Build(std::vector<int> data) {
  for (auto x : data) {
    this->Insert(x);
  }
}

int Heap::Size() { return heap_.size(); }

int Heap::Top() {
  if (Size() == 0) throw std::runtime_error("Empty Heap");
  return heap_[0];
}

int FindMin(std::vector<int> data) {
  Heap heap;
  heap.Build(data);
  return heap.Min();
}
