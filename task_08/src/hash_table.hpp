#pragma once
#include <list>
#include <vector>

class HashSet {
  std::vector<std::list<int>> hash_table;
  size_t size;
  constexpr static size_t default_size = 128;

  void ReSize();

  unsigned HashFunction(int value) const;

  void ReHash();

 public:
  HashSet() {
    size = default_size;
    hash_table.resize(size, std::list<int>{});
  };

  bool Contains(int value) const;

  void Insert(int value);

  void Remove(int value);

  size_t Size();

  void Clear();
};
