#include "merge_sort.h"

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