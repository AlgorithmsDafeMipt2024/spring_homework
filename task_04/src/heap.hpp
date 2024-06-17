#pragma once
#include <iostream>
#include <vector>

class Heap {
 public:
  Heap() { data_ = {}; }
  int PopMin();
  void Insert(int x);
  std::vector<int> GetData() { return data_; }
  void CleanHeap() { data_ = {}; }

 private:
  std::vector<int> data_;
};