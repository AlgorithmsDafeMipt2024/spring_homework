#pragma once

#include <iostream>
#include <vector>

class Heap {
 public:
  void SiftDown(int i);
  void SiftUp(int i);
  void Insert(int value);
  int GetMininum();
  void Build(std::vector<int> vec);
  int DelMininum();
  std::vector<int> Copy();

 private:
  std::vector<int> heap_;
};

int FindMininum(std::vector<int> vec);

std::vector<int> Result(std::vector<int> heap);
