#include <iostream>
#include <vector>

class Heap {
 public:
  void SiftUp(int i);
  void SiftDown(int i);
  void Insert(int x);
  int GetMin();
  void ExtractMin();
  int Size();

 private:
  std::vector<int> a;
  int n = 0;
};