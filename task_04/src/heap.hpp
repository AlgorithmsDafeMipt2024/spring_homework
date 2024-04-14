#pragma once
#include <vector>

class Heap {
 public:
  Heap() { data = {}; }
  int pop_min();
  void insert(int x);
  std::vector<int> get_data() { return data; }
  void clean_heap() { data = {}; }

 private:
  std::vector<int> data;
};