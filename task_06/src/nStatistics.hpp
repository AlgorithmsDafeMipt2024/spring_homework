#include <vector>

template <class T>
int partition(std::vector<T>& v, int low, int high) {
  int pivot = v[high];
  int i = low - 1;

  for (int j = low; j <= high - 1; j++) {
    if (v[j] <= pivot) {
      i++;
      std::swap(v[i], v[j]);
    }
  }
  std::swap(v[i + 1], v[high]);
  return (i + 1);
}

template <class T>
int FindNthStatistic(std::vector<T> v, int n) {
  int low = 0;
  int high = v.size() - 1;

  while (low <= high) {
    int partitionIndex = partition<T>(v, low, high);
    if (partitionIndex == n) {
      return v[partitionIndex];
    } else if (partitionIndex >= n) {
      high = partitionIndex - 1;
    } else
      low = partitionIndex + 1;
  }

  return -1;
}