#pragma once
#include <cstddef>
#include <vector>

class Heap {
 public:
  Heap() {
    heap_array.push_back(0);
    size = 0;
  };
  Heap(std::vector<int> &array) {
    heap_array = array;
    size = array.size();
    heap_array.insert(heap_array.begin(), 0);

    for (size_t node = size; node > 0; --node) SiftDown(node);
  }

  int Pop();

  int Top() const;

  void Push(int value);

  bool Empty() const;

  size_t Size() const;

 private:
  std::vector<int> heap_array{};
  size_t size;

  void SiftUp(size_t node_index);

  void SiftDown(size_t node_index);
};