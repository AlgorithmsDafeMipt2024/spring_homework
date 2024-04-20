#include <iostream>
#include <vector>

#include "sum_of_two.hpp"

using namespace std;

int main() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long s;
  cin >> s;
  pair<long long, long long> p = Solve(a, s);
  cout << p.first << ' ' << p.second;
  return 0;
}
