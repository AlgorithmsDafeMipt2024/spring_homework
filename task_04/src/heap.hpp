#pragma once

#include <iostream>
#include <vector>

class Heap {
 public:
  void SiftDown(int i);
  void SiftUp(int i);
  void Insert(int value);
  int GetMin();
  void Build(std::vector<int> vec);
  int DelMin();
  std::vector<int> Copy();

 private:
  std::vector<int> heap;
};

int FindMin(std::vector<int> vec);

std::vector<int> Result(std::vector<int> heap);
