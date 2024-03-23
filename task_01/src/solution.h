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

// Solution below has a time complexity of O(n) and memory complexity of O(n)

std::pair<int, int> solution(int sum, std::vector<int> v) {
  std::unordered_map<int, int> indices_map;  // keeps array numbers as keys and
                                             // indices as values behind keys

  for (int i = 0; i < v.size(); i++) {
    if (indices_map.find(sum - v[i]) !=
        indices_map
            .end()) {  // if key "number - t" exists, we have found the solution
      return {indices_map[sum - v[i]], i};
    }

    if (indices_map.find(v[i]) == indices_map.end())
      indices_map[v[i]] =
          i;  // We only add keys that weren't in the map before (that
              // way we get the least possible sum of i and j)
  }

  return {-1, -1};  // in case there are no such numbers
}