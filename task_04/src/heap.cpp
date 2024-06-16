#include "heap.hpp"

using namespace std;

void Heap::SiftDown(int u) {
  while (2 * u + 1 < heap_.size()) {
    int left = 2 * u + 1;
    int right = 2 * u + 2;
    int j = left;
    if ((right < heap_.size()) && heap_[right] < heap_[left]) j = right;
    if (heap_[u] <= heap_[j]) break;
    std::swap(heap_[u], heap_[j]);
    u = j;
  }
}

void Heap::SiftUp(int i) {
  while (heap_[i] < heap_[(i - 1) / 2]) {
    std::swap(heap_[i], heap_[(i - 1) / 2]);
    i = (i - 1) / 2;
  }
}

int Heap::GetMininum() { return heap_[0]; }

int Heap::DelMininum() {
  int minimum = heap_[0];
  heap_[0] = heap_[heap_.size() - 1];
  heap_.erase(heap_.begin());
  SiftDown(0);
  return minimum;
}

std::vector<int> Heap::Copy() { return heap_; }

void Heap::Insert(int x) {
  heap_.push_back(x);
  SiftUp(heap_.size() - 1);
}

void Heap::Build(std::vector<int> vec) {
  for (int i = 0; i < vec.size(); ++i) {
    Insert(vec[i]);
  }
}

int FindMininum(std::vector<int> vec) {
  Heap heap_;
  heap_.Build(vec);
  return heap_.GetMininum();
}

std::vector<int> Result(std::vector<int> vec) {
  Heap heap_;
  heap_.Build(vec);
  return heap_.Copy();
}