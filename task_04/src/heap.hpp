#pragma once

#include <iostream>
#include <vector>

class Heap {
public:
  void SiftDown(int i);
  void SiftUp(int i);
  void Insert(int value);
  int Find_Min();
  void Build_heap(std::vector<int> vec);
  int Extract_Min();
  std::vector<int> Copy_Heap();

private:
  std::vector<int> vec_;
};

int Find_Minimum(std::vector<int> vec);

std::vector<int> Heap_Ready(std::vector<int> heap);