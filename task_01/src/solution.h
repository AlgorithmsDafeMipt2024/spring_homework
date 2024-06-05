#pragma once
#include <unordered_map>
#include <vector>

/*

Output - indices of two numbers, which sum is equal to needed number, if there's
no such numbers, the output is "-1 -1"

Input:

10
10
-2 2 3 3 5 8 11 13 14 15

Output:

1 5

*/

// Solution below has a time complexity of O(n) and memory complexity of O(1)

std::pair<int, int> solution(int sum, std::vector<int> vector) {
  if (vector.size() < 2) return {-1, -1};
  int left_pointer = 0, right_pointer = vector.size() - 1;
  while (vector[left_pointer] < vector[right_pointer]) {
    if (vector[left_pointer] + vector[right_pointer] > sum)
      right_pointer--;  // move right pointer to the left by one
    else if (vector[left_pointer] + vector[right_pointer] < sum)
      left_pointer++;  // move left pointer to the right by one
    else
      return {left_pointer, right_pointer};
  }
  return {-1, -1};  // in case there are no such numbers
}