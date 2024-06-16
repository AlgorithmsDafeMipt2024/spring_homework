#pragma once
#include <vector>

class HashTable {
 public:
  HashTable() {
    cells = 0;
    size = 0;
    buffers_size = DefaultBufferSize;
    t_container = std::vector<int>(buffers_size);
    cell_conditions = std::vector<Condition>(buffers_size, Condition::Empty);
  }

  bool Contains(std::size_t value);

  void Insert(std::size_t value);

  void Remove(std::size_t value);

  void Clear();

  size_t Size() { return size; }

 private:
  enum class Condition { Fill, Deleted, Empty };
  constexpr static const double rehashCoefficient = 0.7;
  constexpr static const double hashCoefficient = 0.618033989;
  constexpr static const double DefaultBufferSize = 8;
  size_t buffers_size;
  size_t size;
  std::size_t cells;
  std::vector<int> t_container;
  std::vector<Condition> cell_conditions;

  size_t FirstHashFunc(std::size_t key);
  size_t SecondHashFunc(std::size_t key);

  void ReSize();

  void ReHash();
};