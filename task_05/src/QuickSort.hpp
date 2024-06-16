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
void QuickSort(std::vector<T>& v, int low = 0, int high = -1) {
  if (high == -1) high = v.size() - 1;
  if (low < high) {
    int partitionIndex = partition<T>(v, low, high);
    QuickSort(v, low, partitionIndex - 1);
    QuickSort(v, partitionIndex + 1, high);
  }
}