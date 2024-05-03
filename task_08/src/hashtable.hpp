#pragma once

#include <vector>

class HashTable {
 public:
  HashTable()
      : size_{0},
        buffer_size_{DefaultSize},
        used_cell_size_{0},
        table_{std::vector<int>(buffer_size_)},
        cell_status_{std::vector<Status>(buffer_size_, Status::Empty)} {};
  void Insert(int key);
  void Remove(int key);
  bool Contains(int key);
  unsigned Size();

 private:
  constexpr static const int DefaultSize = 8;
  constexpr static const double RehashSize = 0.75;
  constexpr static const double HashCoeff = 0.61803398;
  unsigned size_; // занятые ячейки без учёта Deleted
  unsigned buffer_size_;
  unsigned used_cell_size_;// занятые ячейки с учётом Deleted
  std::vector<int> table_;
  enum class Status { Empty, Deleted, Fill };
  std::vector<Status> cell_status_;

  unsigned HashFunction1(int key);
  unsigned HashFunction2(int key);
  void Rehash();
  void Resize();
  void Clear();
};

