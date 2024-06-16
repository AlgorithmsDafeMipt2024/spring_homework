#include <functional>
#include <iostream>
#include <list>
#include <stdexcept>
#include <vector>

template <class Key, class Value>
class HashTable {
 public:
  HashTable(size_t size = 10) : table_(size), load_factor_(0.0) {}

  void Insert(const Key& key, const Value& value);

  bool Search(const Key& key);
  Value Get(const Key& key);

  bool Erase(const Key& key);

  size_t Size() const;

 private:
  void Rehash();
  std::vector<std::list<std::pair<Key, Value>>> table_;
  std::hash<Key> hash_;
  double load_factor_;
};

template <class Key, class Value>
void HashTable<Key, Value>::Insert(const Key& key, const Value& value) {
  if (load_factor_ >= 0.75) {
    Rehash();
  }
  size_t index = hash_(key) % table_.size();
  for (auto& pair : table_[index]) {
    if (pair.first == key) {
      pair.second = value;
      return;
    }
  }
  table_[index].emplace_back(key, value);
  load_factor_ = static_cast<double>(Size()) / table_.size();
}

template <class Key, class Value>
bool HashTable<Key, Value>::Search(const Key& key) {
  size_t index = hash_(key) % table_.size();
  for (const auto& pair : table_[index]) {
    if (pair.first == key) {
      return true;
    }
  }
  return false;
}

template <class Key, class Value>
Value HashTable<Key, Value>::Get(const Key& key) {
  size_t index = hash_(key) % table_.size();
  for (const auto& pair : table_[index]) {
    if (pair.first == key) {
      return pair.second;
    }
  }
  throw std::out_of_range("No such key in table");
}

template <class Key, class Value>
bool HashTable<Key, Value>::Erase(const Key& key) {
  size_t index = hash_(key) % table_.size();
  for (auto it = table_[index].begin(); it != table_[index].end(); ++it) {
    if (it->first == key) {
      table_[index].erase(it);
      load_factor_ = static_cast<double>(Size()) / table_.size();
      return true;
    }
  }
  return false;
}

template <class Key, class Value>
size_t HashTable<Key, Value>::Size() const {
  size_t count = 0;
  for (const auto& list : table_) {
    count += list.size();
  }
  return count;
}

template <class Key, class Value>
void HashTable<Key, Value>::Rehash() {
  std::vector<std::list<std::pair<Key, Value>>> new_table(table_.size() * 2);
  for (auto& list : table_) {
    for (auto& pair : list) {
      size_t index = hash_(pair.first) % new_table.size();
      new_table[index].emplace_back(std::move(pair));
    }
  }
  table_ = std::move(new_table);
  load_factor_ = static_cast<double>(Size()) / table_.size();
}