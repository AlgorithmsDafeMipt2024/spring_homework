#include "sortings.hpp"

#include <algorithm>
#include <experimental/random>
#include <iostream>
#include <optional>
#include <valarray>
#include <vector>

int Search(std::vector<int> massive, int num) {
  for (int i = 0; i < massive.size(); i++) {
    if (massive[i] == num) {
      return i;
    }
  }
  return -1;
}
int SearchMin(std::vector<int> massive) {
  int min = massive[0];
  int index = 0;
  for (int i = 0; i < massive.size(); i++) {
    if (massive[i] < min) {
      min = massive[i];
      index = i;
    }
  }
  return index;
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

// O(n^2)
std::vector<int> BubbleSort(std::vector<int> massive) {
  for (int i = 0; i < massive.size(); i++) {
    for (int j = 0; j < massive.size() - i - 1; j++) {
      if (massive[j] > massive[j + 1]) {
        int temporary = massive[j];
        massive[j] = massive[j + 1];
        massive[j + 1] = temporary;
      }
    }
  }
  return massive;
}

// O(n^2)
std::vector<int> SelectionSort(std::vector<int> massive) {
  for (int i = 0; i < massive.size(); i++) {
    std::vector<int> cutted_massive =
        std::vector<int>(massive.begin() + i, massive.end());
    int min_element_index = SearchMin(cutted_massive) + i;
    std::swap(massive[i], massive[min_element_index]);
  }
  return massive;
}

std::vector<int> Insert(std::vector<int> massive, int position, int num) {
  std::vector<int> new_massive;
  for (int i = 0; i < position; i++) {
    new_massive.push_back(massive[i]);
  }
  new_massive.push_back(num);
  for (int i = position; i < massive.size(); i++) {
    new_massive.push_back(massive[i]);
  }
  return new_massive;
}

// O(n^2)
std::vector<int> InsertionSort(std::vector<int> massive) {
  std::vector<int> new_massive;
  new_massive.push_back(massive[0]);
  for (int i = 1; i < massive.size(); i++) {
    bool insertion_done = false;
    for (int j = 0; j < new_massive.size() - 1; j++) {
      if (massive[i] > new_massive[j] && massive[i] < new_massive[j + 1]) {
        new_massive = Insert(new_massive, j + 1, massive[i]);
        insertion_done = true;
      }
    }
    if (not insertion_done && massive[i] <= new_massive[0]) {
      new_massive = Insert(new_massive, 0, massive[i]);
      insertion_done = true;

    } else if (not insertion_done &&
               massive[i] >= new_massive[new_massive.size() - 1]) {
      new_massive.push_back(massive[i]);
      insertion_done = true;
    }
  }
  return new_massive;
}

// O(NlogN)
std::vector<int> Merge(std::vector<int> massive) {
  std::vector<int> part1;
  std::vector<int> part2;
  if (massive.size() % 2 == 0) {
    part1 =
        std::vector<int>(massive.begin(), massive.end() - massive.size() / 2);
    part2 =
        std::vector<int>(massive.begin() + (massive.size()) / 2, massive.end());
  } else {
    part1 =
        std::vector<int>(massive.begin(), massive.end() - massive.size() / 2);
    part2 = std::vector<int>(massive.begin() + (massive.size() + 1) / 2,
                             massive.end());
  }
  if (part1.size() == 1 and part2.size()==1

  std::vector<int> part1 = std::vector<int>(massive.begin(), massive.end() -);
  ;
  return;
}
