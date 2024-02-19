#include <vector>
//#include <priority_queue>

// left child: 2*i + 1;
// right child: 2*i + 2;
// parent: [(i-1)/2];

struct Heap {
  Heap() : size{0}, values{} {}

  void sift_up(int i);
  void sift_down(int i);
  void append(int x);

  std::vector<int> values;
  int size;
};

void Heap::sift_up(int i) {}