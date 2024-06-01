#include "find_order_statistic.hpp"

#include <experimental/random>

// what element has index k in sorted massive
int FindOrderStatistic(std::vector<int> massive, int k) {
  // empty massive
  if (massive.size() == 0) {
    return -1;
  }

  // k out of range
  if (k >= massive.size() or k < 0) {
    return -1;
  }

  if (massive.size() == 1) {
    return massive[0];
  }

  int pivat = massive[0 + (rand() % (massive.size()))];  // random int from 0 to
                                                         // massive.size()-1
  std::vector<int> smaller_part;
  std::vector<int> bigger_part;
  for (int i = 0; i < massive.size(); i++) {
    if (massive[i] < pivat) {
      smaller_part.push_back(massive[i]);
    } else {
      bigger_part.push_back(massive[i]);
    }
  }
  int middle_index = smaller_part.size();
  int answer;
  if (k >= middle_index) {
    answer = FindOrderStatistic(bigger_part, k - middle_index);

  } else if (k < middle_index) {
    answer = FindOrderStatistic(smaller_part, k);
  }

  return answer;
}