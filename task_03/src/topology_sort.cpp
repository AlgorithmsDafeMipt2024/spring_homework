#include "topology_sort.hpp"

std::vector<int> DaysBeforeWarming(std::vector<int> temperatures) {
  std::vector<int> answer(temperatures.size());
  for (int i = 0; i < temperatures.size(); i++) {
    answer[i] = 1;
    bool was_warmer_found = false;
    for (int j = i + 1; j < temperatures.size() and not was_warmer_found; j++) {
      if (temperatures[i] >=
          temperatures[j]) {  // skip days, when tempreture is lower
        answer[i] += 1;
      } else if ((temperatures[i] < temperatures[j]) &
                 (j == i + 1)) {  // case, when warmer day is rigth next
        answer[i] = 1;
        was_warmer_found = true;
      } else if ((temperatures[i] < temperatures[j]) &
                 (j != i + 1)) {  // case, when warmer day is rigth next
        was_warmer_found = true;
      }
    }

    if (not was_warmer_found) {
      answer[i] = 0;
    }
  }
  return answer;
}