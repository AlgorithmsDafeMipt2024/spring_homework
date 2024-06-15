#include <iostream>
#include <list>
#include <vector>

class HashTable {
 public:
  HashTable(size_t size) : table(size) {}

  // Вставка элемента
  void insert(int key, int value) {
    auto& list = table[hashFunction(key, table.size())];
    for (auto& pair : list) {
      if (pair.first == key) {
        pair.second = value;
        return;
      }
    }
    list.emplace_back(key, value);
  }

  // Удаление элемента
  void remove(int key) {
    auto& list = table[hashFunction(key, table.size())];
    for (auto it = list.begin(); it != list.end(); ++it) {
      if (it->first == key) {
        list.erase(it);
        return;
      }
    }
  }

  // Поиск элемента
  bool find(int key, int& value) {
    auto& list = table[hashFunction(key, table.size())];
    for (auto pair : list) {
      if (pair.first == key) {
        value = pair.second;
        return true;
      }
    }
    return false;
  }

 private:
  std::vector<std::list<std::pair<int, int>>> table;
  std::function<size_t(int, size_t)> hashFunction =
      [](int key, size_t mod) -> size_t { return (key * 1363) % mod; };
};