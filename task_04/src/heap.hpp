#pragma once

#include <vector>
class Heap {
 public:
  int Top();
  int Size();
  int Min();
  void Insert(int value);
  void Build(std::vector<int> data);

 private:
  std::vector<int> heap_;
  void SiftUp(int index);
  void SiftDown(int index);
};

int FindMin(std::vector<int> data);