#include "topology_sort.hpp"

std::tuple<bool, int *, int *> topology_sort(int *arr, int n, int m) {
  int *b = arr, *e = arr + (n - 1);
  bool found = 1;
  while (b && e && b != e && *b + *e != m)
    if ((*b + *e) > m)
      e--;
    else
      b++;
  if ((!b) || (!e) || (b == e) || (*b + *e != m)) {
    b = e = nullptr;
    found = 0;
  }
  return std::tuple<bool, int *, int *>{found, b, e};
}
