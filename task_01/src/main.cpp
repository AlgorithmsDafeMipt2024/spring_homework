#include <iostream>
#include <vector>

// proverka 4

int main() {
  int a;
  int x;
  std::cin >> a;
  std::vector<int> b;
  while (std::cin >> x) {
    b.push_back(x);
  }

  int i = 0;
  int j = b.size() - 1;
  while (b[i] + b[j] != a) {
    if (b[i] + b[j] < a) i++;
    if (b[i] + b[j] > a) j--;
  }
  std::cout << b[i] << ' ' << b[j] << '\n';
  return 0;
}
