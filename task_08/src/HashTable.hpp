#include <functional>
#include <iostream>
#include <list>
#include <vector>

template <class Key, class Value>
class HashTable {
 public:
  HashTable(size_t size = 10) : table(size), load_factor(0.0) {}

  void insert(const Key& key, const Value& value);

  bool search(const Key& key);

  bool erase(const Key& key);

  size_t size() const;

 private:
  void rehash();
  std::vector<std::list<std::pair<Key, Value>>> table;
  std::hash<Key> hash;
  double load_factor;
};

template <class Key, class Value>
void HashTable<Key, Value>::insert(const Key& key, const Value& value) {
  if (load_factor >= 0.75) {
    rehash();
  }
  size_t index = hash(key) % table.size();
  for (auto& pair : table[index]) {
    if (pair.first == key) {
      pair.second = value;
      return;
    }
  }
  table[index].emplace_back(key, value);
  load_factor = static_cast<double>(size()) / table.size();
}

template <class Key, class Value>
bool HashTable<Key, Value>::search(const Key& key) {
  size_t index = hash(key) % table.size();
  for (const auto& pair : table[index]) {
    if (pair.first == key) {
      return true;
    }
  }
  return false;
}

template <class Key, class Value>
bool HashTable<Key, Value>::erase(const Key& key) {
  size_t index = hash(key) % table.size();
  for (auto it = table[index].begin(); it != table[index].end(); ++it) {
    if (it->first == key) {
      table[index].erase(it);
      load_factor = static_cast<double>(size()) / table.size();
      return true;
    }
  }
  return false;
}

template <class Key, class Value>
size_t HashTable<Key, Value>::size() const {
  size_t count = 0;
  for (const auto& list : table) {
    count += list.size();
  }
  return count;
}

template <class Key, class Value>
void HashTable<Key, Value>::rehash() {
  std::vector<std::list<std::pair<Key, Value>>> new_table(table.size() * 2);
  for (const auto& list : table) {
    for (const auto& pair : list) {
      size_t index = hash(pair.first) % new_table.size();
      new_table[index].emplace_back(pair);
    }
  }
  table = std::move(new_table);
  load_factor = static_cast<double>(size()) / table.size();
}