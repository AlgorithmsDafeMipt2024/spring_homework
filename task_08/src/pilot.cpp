#include <cmath>
#include <iostream>
#include <string>

#include "hashtable.hpp"

int main() {
  HashTable<int, int> ht_int{};
  for (int i = 1; i <= 64; i++) {
    ht_int[i] = i * i;
  }
  std::cout << "push_back is alright";
  ht_int.print();
  std::cout << "\n\n\n";
  HashTable<std::string, std::string> ht_str{};
  for (char c1 = 'a'; c1 < 'a' + 8; c1++) {
    for (char c2 = 'a'; c2 < 'a' + 8; c2++) {
      std::string str1 = "";
      str1.push_back(c1);
      str1.push_back(c2);
      ht_str[str1] = str1;
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

  std::cout << "\nstr pop done!\n\n";

  LinkedList<int> ll1 = {1};
  ll1.print();
  std::cout << "\n\n";
  HashTable<int, int> ht_i_lst = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6},
                                  {6, 7}, {7, 8}, {8, 9}, {9, 10}};
  ht_i_lst.print();
  std::cout << "initializer_list works\n\n";
  return 0;
}