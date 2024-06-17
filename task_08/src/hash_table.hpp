#pragma once
#include <iostream>
#include <vector>

class HashTable {
 public:
  HashTable() {
    used_elements_ = 0;
    size_ = 0;
    table_size_ = 8;
    table_container_ = std::vector<int>(table_size_);
    elements_conditions_ =
        std::vector<Condition>(table_size_, Condition::Empty);
  }

  bool Contains(int value);

  void Insert(int value);

  void Remove(int value);

  void Clear();

  size_t Size();

 private:
  enum class Condition { Fill, Deleted, Empty };
  constexpr static const double rehashCoefficient = 0.5;
  constexpr static const double hashCoefficient = 0.618033989;
  size_t table_size_;
  size_t size_;
  unsigned used_elements_;
  std::vector<int> table_container_;
  std::vector<Condition> elements_conditions_;

  size_t Hash(int key);

  void ReSize();

  void ReHash();
};
