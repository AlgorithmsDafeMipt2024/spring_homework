#ifndef NTH_ORDINAL_STATISTIC
#define NTH_ORDINAL_STATISTIC
#include <stdexcept>
#include <vector>

template <class T>
T nth_ordinal_statistics(std::vector<T> data, size_t k) {
  if (data.empty() || k >= data.size())
    throw std::runtime_error("vector is empty");
  for (size_t left = 0, right = data.size();;) {
    if (right <= left + 1) {
      if (right == left + 1 && data[right] < data[left])
        std::swap(data[left], data[right]);
      return data[k];
    }

    size_t mid = (left + right) / 2;
    std::swap(data[mid], data[left + 1]);
    if (data[left] > data[right]) std::swap(data[left], data[right]);
    if (data[left + 1] > data[right]) std::swap(data[left + 1], data[right]);
    if (data[left] > data[left + 1]) std::swap(data[left], data[left + 1]);

    size_t i = left + 1, j = right;
    const T cur = data[left + 1];
    for (;;) {
      while (data[++i] < cur)
        ;
      while (data[--j] > cur)
        ;
      if (i > j) break;
      std::swap(data[i], data[j]);
    }
    std::swap(data[left + 1], data[j]);
    if (j >= k) right = j - 1;
    if (j <= k) left = i;
  }
}

#endif