#include <util.hpp>
#include <vector>

template <class T>
int FindNthStatistic(std::vector<T> v, int n) {
  int low = 0;
  int high = v.size() - 1;

  while (low <= high) {
    int partitionIndex = Partition<T>(v, low, high);
    if (partitionIndex == n) {
      return v[partitionIndex];
    } else if (partitionIndex >= n) {
      high = partitionIndex - 1;
    } else
      low = partitionIndex + 1;
  }

  return -1;
}