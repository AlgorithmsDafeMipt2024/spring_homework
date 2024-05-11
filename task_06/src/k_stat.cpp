#include "k_stat.hpp"

#include <iostream>
#include <stdexcept>
#include <vector>

int Partition(std::vector<int> &vec, int l, int r) {
  int piv = vec[rand() % vec.size()];
  int i = l;
  int j = r;
  while (i <= j) {
    while (vec[i] < piv) {
      i++;
    }
    while (vec[j] > piv) {
      j--;
    }
    if (i >= j) {
      break;
    }
    std::swap(vec[i++], vec[j--]);
  }
  return j;
}

int FindOrderStatistic(std::vector<int> &vec, int k) {
  if (k >= vec.size() || k < 0) {
    throw std::logic_error("Wrong k order statistic");
  }
  int left = 0;
  int right = int(vec.size() - 1);
  while (left < vec.size()) {
    int mid = Partition(vec, left, right);

    if (mid == k) {
      return vec[mid];
    }

    else if (k < mid) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  throw std::logic_error("Wrong k order statistic");
}