#include "WeatherReport.h"

#include <stack>
#include <vector>

std::vector<int> findNextGreater(std::vector<int> v) {
  std::vector<int> res(v.size(), -1);
  std::stack<int> stack;

  for (int i = v.size() - 1; i >= 0; i--) {
    while (stack.size() != 0 && v[i] >= v[stack.top()]) {
      stack.pop();
    }
    if (stack.size() == 0) {
      res[i] = stack.top() - i;
    }
    stack.push(i);
  }
  return res;
}