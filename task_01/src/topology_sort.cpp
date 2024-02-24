#include "topology_sort.hpp"

std::tuple<bool, int *, int *> SummanddsInArray(int *arr, int n, int sum) {
  int *begin = arr, *end = arr + (n - 1);
  bool found = true;
  while (begin && end && begin < end && *begin + *end != sum)
    if ((*begin + *end) > sum)
      end--;
    else
      begin++;
  if ((!begin) || (!end) || (begin >= end) || (*begin + *end != sum)) {
    begin = end = nullptr;
    found = 0;
  }
  return std::tuple<bool, int *, int *>{found, begin, end};
}
