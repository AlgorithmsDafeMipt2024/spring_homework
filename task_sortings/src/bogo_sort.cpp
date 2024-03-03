#include "bogo_sort.h"

int Search(std::vector<int> massive, int num) {
  for (int i = 0; i < massive.size(); i++) {
    if (massive[i] == num) {
      return i;
    }
  }
  return -1;
}

std::vector<int> ShuffleIndexes(int n) {
  std::vector<int> random_nums(n);
  for (int i = 0; i < n; i) {
    int rand_num = std::experimental::randint(1, n);
    if (Search(random_nums, rand_num) == -1) {
      random_nums[i] = rand_num;
      i++;
    }
  }
  for (int i = 0; i < n; i++) {
    random_nums[i]--;
  }

  return random_nums;
}

std::vector<int> ShuffleMassive(std::vector<int> massive) {
  std::vector<int> random_indexes = ShuffleIndexes(massive.size());
  std::vector<int> new_massive(massive.size());

  for (int i = 0; i < massive.size(); i++) {
    new_massive[i] = massive[random_indexes[i]];
  }
  return new_massive;
}

bool IsSorted(std::vector<int> massive) {
  for (int i = 0; i < massive.size() - 1; i++) {
    if (massive[i] > massive[i + 1]) {
      return false;
    }
  }
  return true;
}

// O(n!)
std::vector<int> BogoSort(std::vector<int> massive) {
  if (IsSorted(massive)) {
    return massive;
  } else {
    std::vector<int> new_massive = ShuffleMassive(massive);
    while (not IsSorted(new_massive)) {
      new_massive = ShuffleMassive(massive);
    }
    return new_massive;
  }
}
