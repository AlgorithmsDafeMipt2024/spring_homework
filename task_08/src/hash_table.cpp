#include "hash_table.hpp"

unsigned HashSet::HashFunction(int value) const { return value % size; }

void HashSet::ReSize() {
  size *= 2;
  hash_table.resize(size, std::list<int>{});
}

void HashSet::Insert(int value) {
  size_t key = HashFunction(value);
  hash_table[key].push_front(value);
  if (hash_table[key].size() > size / 2) ReHash();
}

bool HashSet::Contains(int value) const {
  size_t key = HashFunction(value);
  for (auto &num : hash_table[key])
    if (num == value) return true;
  return false;
}

void HashSet::Remove(int value) {
  size_t key = HashFunction(value);
  for (auto num = hash_table[key].begin(); num != hash_table[key].end();
       ++num) {
    if (*num == value) {
      hash_table[key].erase(num);
      return;
    }
  }
}

void HashSet::ReHash() {
  std::vector<std::list<int>> old_hash_table = hash_table;
  hash_table.clear();
  ReSize();
  for (auto &list : old_hash_table) {
    for (auto &num : list) Insert(num);
  }
}

size_t HashSet::Size() { return hash_table.size(); }

void HashSet::Clear() {
  size = default_size;
  hash_table.clear();
  hash_table.resize(size);
}