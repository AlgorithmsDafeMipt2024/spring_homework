#include "task.hpp"

// O(logn)
int BinSearch(std::vector<int> massive, int num) {
  int length = massive.size();
  int left = 0;
  int right = length - 1;
  int index = length / 2;
  while (right - left >= 0) {
    if (massive[index] == num) {
      return index;
    } else if (massive[index] > num) {
      right = index - 1;
    } else if (massive[index] < num) {
      left = index + 1;
    }
    index = (right + left) / 2;
  }
  return -1;
}

// O(n^2)
std::tuple<int, int> NSquareSearch(std::vector<int> massive, int num) {
  int length = massive.size();
  for (int i = 0; i < length; i++) {
    for (int j = i + 1; j < length; j++) {
      if (massive[i] + massive[j] == num) {
        return {i, j};
      }
    }
  }
  return {-1, -1};
}

// O(nlogn)
std::tuple<int, int> NLogNSearch(std::vector<int> massive, int num) {
  int length = massive.size();
  for (int i = 0; i < length; i++) {
    int el1 = massive[i];
    int el2 = num - el1;
    int j = BinSearch(massive, el2);
    if (j != -1 && i != j) {
      return {i, j};
    }
  }
  return {-1, -1};
}

// O(n)
std::tuple<int, int> NSearch(std::vector<int> massive, int num) {
  int length = massive.size();
  int left = 0;
  int right = length - 1;
  while (right != left) {
    int sum = massive[left] + massive[right];
    if (sum == num) {
      return {left, right};
    } else if (sum < num) {
      left++;
    } else if (sum > num) {
      right--;
    }
  }
  return {-1, -1};
}