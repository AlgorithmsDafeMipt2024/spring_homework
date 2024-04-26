#pragma once
#include <iostream>
#include <vector>

class HashTable {
public:
  HashTable() {
    used_cell_ = 0;
    size_ = 0;
    buffers_size_ = DefaultBufferSize;
    t_container_ = std::vector<int>(buffers_size_);
    cell_conditions_ = std::vector<Condition>(buffers_size_, Condition::Empty);
  }

  bool Contains(int value);

  void Insert(int value);

  void Remove(int value);

  void Clear();

  size_t Size();

private:
  enum class Condition { Fill, Deleted, Empty };
  constexpr static const double rehashCoefficient = 0.7;
  constexpr static const double hashCoefficient = 0.618033989;
  constexpr static const double DefaultBufferSize = 8;
  size_t buffers_size_;
  size_t size_;
  unsigned used_cell_;
  std::vector<int> t_container_;
  std::vector<Condition> cell_conditions_;

  size_t FirstHashFunc(int key);
  size_t SecondHashFunc(int key);

  void ReSize();

  void ReHash();
};