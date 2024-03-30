#pragma once

#include <vector>
struct Heap {
  void SiftUp(int index);
  void SiftDown(int index);
  int Min();
  void Insert(int value);
  void Build(std::vector<int> data);

  std::vector<int> heap_;
};

int FindMin(std::vector<int> data);