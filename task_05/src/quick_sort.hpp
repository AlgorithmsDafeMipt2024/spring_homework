#include <util.hpp>
#include <vector>

template <class T>
void QuickSort(std::vector<T>& v, int low = 0, int high = -1) {
  if (high == -1) high = v.size() - 1;
  if (low < high) {
    int partitionIndex = Partition<T>(v, low, high);
    QuickSort(v, low, partitionIndex - 1);
    QuickSort(v, partitionIndex + 1, high);
  }
}