#include <cmath>
#include <iostream>
#include <string>

#include "hashtable.hpp"

int main() {
  hash_table<int, int> ht_int{};
  for (int i = 1; i <= 64; i++) {
    ht_int[i] = i * i;
  }
  std::cout << "push_back is alright";
  ht_int.print();
  std::cout << "\n\n\n";
  hash_table<std::string, std::string> ht_str{};
  for (char c1 = 'a'; c1 < 'a' + 8; c1++) {
    for (char c2 = 'a'; c2 < 'a' + 8; c2++) {
      std::string str1 = "";
      str1.push_back(c1);
      str1.push_back(c2);
      std::string str2 = "";
      str2.push_back(c1 + 8);
      str2.push_back(c2 + 8);
      ht_str[str1] = str2;
    }
  }

  ht_str.print();

  std::cout << "\n\nstr push_back done!\n\n";

  for (char c1 = 'a'; c1 < 'a' + 8; c1++) {
    for (char c2 = 'a'; c2 < 'a' + 8; c2++) {
      if (c1 > 'a' + 2 || c2 > 'a' + 2) {
        std::string str = "";
        str.push_back(c1);
        str.push_back(c2);
        ht_str.pop(str);
      }
    }
  }
  ht_str.print();
  return 0;
}