#include "topology_sort.hpp"

// O(logn)
int BinSearch(std::vector<int> mas, int num) {
  int n = mas.size();
  int l = 0;
  int r = n - 1;
  int ind = n / 2;
  while (r - l >= 0) {
    if (mas[ind] == num) {
      return ind;
    } else if (mas[ind] > num) {
      r = ind - 1;
    } else if (mas[ind] < num) {
      l = ind + 1;
    }
    ind = (r + l) / 2;
  }
  return -1;
}

// O(n^2)
std::tuple<int, int> NSquareSearch(std::vector<int> mas, int num) {
  int n = mas.size();
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (mas[i] + mas[j] == num) {
        return {i, j};
      }
    }
  }
  return {-1, -1};
}

// O(nlogn)
std::tuple<int, int> NLogNSearch(std::vector<int> mas, int num) {
  int n = mas.size();
  for (int i = 0; i < n; i++) {
    int el1 = mas[i];
    int el2 = num - el1;
    int j = BinSearch(mas, el2);
    if (j != -1) {
      return {i, j};
    }
  }
  return {-1, -1};
}

// O(n)
std::tuple<int, int> NSearch(std::vector<int> mas, int num) {
  int len = mas.size();
  int l = 0;
  int r = len - 1;
  while (r != l) {
    int sum = mas[l] + mas[r];
    if (sum == num) {
      return {l, r};
    } else if (sum < num) {
      l++;
    } else if (sum > num) {
      r--;
    }
  }
  return {-1, -1};
}