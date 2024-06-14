#include "bin_heap.hpp"

BinHeap::BinHeap() {
  heap = {};
  size = 0;
}

BinHeap::BinHeap(std::vector<int> list) {
  heap = list;
  size = list.size();
  heapify();
}

std::vector<int> BinHeap::get_heap() { return heap; }

void BinHeap::swap(int i, int j) {
  if (i >= size or i < 0 or j >= size or j < 0) {
    throw std::range_error("swap: indexes must be in range");
  }

  int i_val = heap[i];
  heap[i] = heap[j];
  heap[j] = i_val;
}

void BinHeap::swap(int i, char key) {
  if (key != 'l' and key != 'r') {
    throw std::invalid_argument("swap: Key must be 'l' or 'r'");
  }

  if (key == 'l') {
    swap(i, i * 2 + 1);
  }
  if (key == 'r') {
    swap(i, i * 2 + 2);
  }
}

void BinHeap::heapify() {
  for (int i = size / 2 - 1; i >= 0; i--) {
    heapify(i);
  }
}

void BinHeap::heapify(int i) {
  if (i >= size or i < 0) {
    return;
  }

  int l = 2 * i + 1;
  int r = 2 * i + 2;
  int largest = i;
  if (l < size and heap[l] > heap[largest]) {
    largest = l;
  }
  if (r < size and heap[r] > heap[largest]) {
    largest = r;
  }
  if (largest != i) {
    swap(i, largest);
    heapify(largest);
  }
}

void BinHeap::insert_key_value(int key, int value) {
  if (key >= size or key < 0) {
    throw std::range_error("insert_key_value: index must be in range");
  }

  if (value <= heap[key]) {
    heap[key] = value;
    heapify(key);

  } else {
    heap[key] = value;
    for (int i = key; i > 0 and heap[i] > heap[(i - 1) / 2]; i = (i - 1) / 2) {
      swap(i, (i - 1) / 2);
    }
  }
}

void BinHeap::push_value(int value) {
  size++;
  heap.push_back(std::numeric_limits<int>::lowest());
  insert_key_value(size - 1, value);
}

int BinHeap::pop_max() {
  if (size < 1) {
    throw std::length_error("pop_max: heap is empty");
  }

  int max_value = heap[0];
  heap[0] = heap[size - 1];
  heap.pop_back();
  size -= 1;

  heapify(0);

  return max_value;
}
