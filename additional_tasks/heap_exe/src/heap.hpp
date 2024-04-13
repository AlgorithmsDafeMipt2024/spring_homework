#include <map>
#include <vector>

class Heap {
 public:
  void SiftUp(int i);
  void SiftDown(int i);
  void insert(int x);
  int getMin();
  void extractMin();
  int size();

 private:
  std::vector<int> a;
  int n = 0;
};

std::pair<int, std::vector<int>> Heap_exe(int n, int k, std::vector<int> a);