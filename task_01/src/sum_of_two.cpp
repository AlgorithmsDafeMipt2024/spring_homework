#include "sum_of_two.hpp"

pair<long long, long long> Solve(vector<long long> arr, long long sum) {
  long long first_pointer = 0;
  long long second_pointer = arr.size() - 1;
  while (first_pointer < second_pointer) {
    if (arr[first_pointer] + arr[second_pointer] == sum) {
      return {arr[first_pointer], arr[second_pointer]};
    } else if (arr[first_pointer] + arr[second_pointer] > sum) {
      second_pointer--;
    } else {
      first_pointer++;
    }
  }
  return {-1, -1};
}
