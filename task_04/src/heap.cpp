#include "heap.hpp"

using namespace std;

void Heap::SiftDown(int u) {
  while (2 * u + 1 < heap.size()) {
    int left = 2 * u + 1;
    int right = 2 * u + 2;
    int j = left;
    if ((right < heap.size()) && heap[right] < heap[left]) j = right;
    if (heap[u] <= heap[j]) break;
    std::swap(heap[u], heap[j]);
    u = j;
  }
}

void Heap::SiftUp(int i) {
  while (heap[i] < heap[(i - 1) / 2]) {
    std::swap(heap[i], heap[(i - 1) / 2]);
    i = (i - 1) / 2;
  }
}

int Heap::GetMin() { return heap[0]; }

int Heap::DelMin() {
  int minimum = heap[0];
  heap[0] = heap[heap.size() - 1];
  heap.erase(heap.begin());
  SiftDown(0);
  return minimum;
}

std::vector<int> Heap::Copy() { return heap; }

void Heap::Insert(int x) {
  heap.push_back(x);
  SiftUp(heap.size() - 1);
}

void Heap::Build(std::vector<int> vec) {
  for (int i = 0; i < vec.size(); ++i) {
    Insert(vec[i]);
  }
}

int FindMin(std::vector<int> vec) {
  Heap heap;
  heap.Build(vec);
  return heap.GetMin();
}

std::vector<int> Result(std::vector<int> vec) {
  Heap heap;
  heap.Build(vec);
  return heap.Copy();
}