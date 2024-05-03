#include "heap.hpp"

#include <vector>

void Heap::SiftUp(int index) {
  while (heap_[index] < heap_[(index - 1) / 2]) {
    std::swap(heap_[index], heap_[(index - 1) / 2]);
    index = (index - 1) / 2;
  }
}

void Heap::SiftDown(int index) {
  while (2 * index + 1 < heap_.size()) {
    int l = 2 * index + 1, r = 2 * index + 2;
    int j = l;
    if (r < heap_.size() && heap_[r] < heap_[l]) {
      j = r;
    }
    if (heap_[index] < heap_[j]) {
      break;
    }
    std::swap(heap_[index], heap_[j]);
    index = j;
  }
}

int Heap::Min() {
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

int FindMin(std::vector<int> data) {
  Heap heap;
  heap.Build(data);
  return heap.Min();
}
