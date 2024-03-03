#include "sortings.hpp"

#include <algorithm>
#include <cstddef>
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

std::vector<int> Insert(std::vector<int> massive, int num) {
  std::vector<int> new_massive;
  if (num < massive[0]) {
    new_massive.push_back(num);
    for (int i = 0; i < massive.size(); i++) {
      new_massive.push_back(massive[i]);
    }
    return new_massive;
  }

  else if (num > massive[massive.size() - 1]) {
    massive.push_back(num);
    return massive;
  }

  int position = 0;
  for (int i = 0; num >= massive[i]; i++) {
    new_massive.push_back(massive[i]);
    position = i;
  }
  new_massive.push_back(num);

  for (int i = position + 1; i < massive.size(); i++) {
    new_massive.push_back(massive[i]);
  }
  return new_massive;
}

// O(n^2)
std::vector<int> InsertionSort(std::vector<int> massive) {
  std::vector<int> new_massive;
  new_massive.push_back(massive[0]);
  for (int i = 1; i < massive.size(); i++) {
    new_massive = Insert(new_massive, massive[i]);
  }
  return new_massive;
}

std::vector<int> Merge(std::vector<int> part1, std::vector<int> part2) {
  std::vector<int> result;
  int index1 = 0;
  int index2 = 0;

  while (index1 < part1.size() &&
         index2 < part2.size()) {  // Add elements while each part is not empty
    if (part1[index1] <= part2[index2]) {
      result.push_back(part1[index1]);
      index1++;
    } else if (part2[index2] < part1[index1]) {
      result.push_back(part2[index2]);
      index2++;
    }
  }
  if (index1 < part1.size()) {  // Some elements left in part1
    while (index1 < part1.size()) {
      result.push_back(part1[index1]);
      index1++;
    }
  } else if (index2 < part2.size()) {  // Some elements left in part2
    while (index2 < part2.size()) {
      result.push_back(part2[index2]);
      index2++;
    }
  }
  return result;
}

// O(NlogN)
std::vector<int> MergeSort_topbottom(std::vector<int> massive) {
  std::vector<int> part1;
  std::vector<int> part2;
  if (massive.size() != 1) {
    if (massive.size() % 2 == 0) {
      part1 =
          std::vector<int>(massive.begin(), massive.end() - massive.size() / 2);
      part2 = std::vector<int>(massive.begin() + (massive.size()) / 2,
                               massive.end());
    } else {
      part1 =
          std::vector<int>(massive.begin(), massive.end() - massive.size() / 2);
      part2 = std::vector<int>(massive.begin() + (massive.size() + 1) / 2,
                               massive.end());
    }
  }

  else {
    return massive;
  }
  part1 = MergeSort_topbottom(part1);
  part2 = MergeSort_topbottom(part2);

  std::vector<int> result = Merge(part1, part2);

  return result;
}

// O(NlogN)
std::vector<int> MergeSort_bottomup(std::vector<int> massive) {
  std::vector<std::vector<int>> parts;
  for (int i = 0; i < massive.size(); i++) {
    parts.push_back(std::vector<int>{massive[i]});
  }
  std::vector<std::vector<int>> new_parts;
  while (parts.size() > 1) {
    for (int i = 0; i < parts.size() - 1; i) {
      new_parts.push_back(Merge(parts[i], parts[i + 1]));
      i += 2;
    }
    if (parts.size() % 2 != 0) {
      new_parts.push_back(parts[parts.size() - 1]);
    }
    parts = new_parts;
    new_parts.clear();
  }
  return parts[0];
}

// O*(NlogN) (but upper limit is O(n^2) if pivat is bad)
std::vector<int> QuickSort(std::vector<int> massive) {
  int pivat_index = massive.size() / 2;
  int pivat = massive[pivat_index];

  std::vector<int> smaller_part;
  std::vector<int> bigger_part;

  if (massive.size() > 1) {
    for (int i = 0; i < massive.size(); i++) {
      if (i != pivat_index) {
        if (massive[i] <= pivat) {
          smaller_part.push_back(massive[i]);
        } else {
          bigger_part.push_back(massive[i]);
        }
      }
    }
  } else {
    return massive;
  }
  if (smaller_part.size() > 1) {
    smaller_part = QuickSort(smaller_part);
  }

  if (bigger_part.size() > 1) {
    bigger_part = QuickSort(bigger_part);
  }

  std::vector<int> result = smaller_part;
  result.push_back(pivat);
  for (int i = 0; i < bigger_part.size(); i++) {
    result.push_back(bigger_part[i]);
  }
  return result;
}