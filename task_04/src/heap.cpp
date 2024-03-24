#include "heap.hpp"

#include <cstddef>
#include <stdexcept>

bool Heap::Empty() const { return (size == 0); }

size_t Heap::Size() const { return size; }

void Heap::SiftUp(size_t node) {
  size_t parent = node / 2;
  while (node > 1 && heap_array[parent] > heap_array[node]) {
    std::swap(heap_array[node], heap_array[parent]);
    node = parent;
    parent /= 2;
  }
}

void Heap::SiftDown(size_t node) {
  while (node * 2 <= size) {
    size_t left_son = 2 * node;
    size_t right_son = 2 * node + 1;
    size_t smallest_son;
    if (right_son <= size && heap_array[right_son] < heap_array[left_son])
      smallest_son = right_son;
    else
      smallest_son = left_son;

    if (heap_array[smallest_son] >= heap_array[node]) break;
    std::swap(heap_array[smallest_son], heap_array[node]);
    node = smallest_son;
  }
}

int Heap::Pop() {
  if (Empty()) throw std::out_of_range("Heap is empty");
  int root = heap_array[1];
  heap_array[1] = heap_array[size];
  heap_array.pop_back();
  size--;
  SiftDown(1);
  return root;
}

int Heap::Top() const {
  if (Empty()) throw std::out_of_range("Heap is empty");
  int root = heap_array[1];
  return root;
}

void Heap::Push(int value) {
  heap_array.push_back(value);
  size++;
  SiftUp(size);
}
