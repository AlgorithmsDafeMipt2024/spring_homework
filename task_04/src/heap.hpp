#pragma once
#include <iostream>
#include <vector>

class Heap {
 public:
  void SiftDown(int i);
  void SiftUp(int i);
  void Insert(int value);
  int FindMin();
  void BuildHeap(std::vector<int> vec);
  int ExtractMin();
  std::vector<int> CopyHeap();

 private:
  std::vector<int> vec_;
};

int FindMinimum(std::vector<int> vec);

std::vector<int> HeapReady(std::vector<int> heap);