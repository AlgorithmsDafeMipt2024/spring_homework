#include <iostream>
#include <unordered_map>

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

void solution() {
  int number, n, t;
  bool flag = false;  // in case there are no such numbers
  std::unordered_map<int, int> mp;

  std::cin >> number >> n;

  for (int i = 0; i < n; i++) {
    std::cin >> t;

    if (mp.find(number - t) !=
        mp.end()) {  // if key "number - t" exists, we have found the solution
      std::cout << mp[number - t] << ' ' << i;
      flag = true;
      break;
    }

    if (mp.find(t) == mp.end())
      mp[t] = i;  // We only add keys that weren't in the map before (that way
                  // we get the least possible sum of i and j)
  }

  if (!flag) std::cout << -1 << ' ' << -1;
}

int main() {
  solution();
  return 0;
}
