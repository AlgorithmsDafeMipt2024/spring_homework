#include "hash_table.hpp"

#include <cmath>
#include <vector>

void HashTable::Insert(int value) {
  size_t hash = FirstHashFunction(value) % buffer_size_;
  int attemps_count = 0;
  while (cell_conditions_[hash] == Condition::Fill) {
    if (container_[hash] == value) return;
    ++attemps_count;
    hash =
        (FirstHashFunction(value) + attemps_count * SecondHashFunction(value)) %
        buffer_size_;
  }
  container_[hash] = value;
  cell_conditions_[hash] = Condition::Fill;
  ++used_cell_;
  ++size_;

  double used_cells_coef = double(used_cell_) / buffer_size_;
  if (used_cells_coef >= rehash_coefficient) Rehash();
}

void HashTable::Remove(int value) {
  size_t hash = FirstHashFunction(value) % buffer_size_;
  int attemps_count = 0;
  while (cell_conditions_[hash] != Condition::Empty) {
    if (container_[hash] == value &&
        cell_conditions_[hash] == Condition::Fill) {
      cell_conditions_[hash] = Condition::Deleted;
      --size_;
      break;
    }
    if (container_[hash] == value &&
        cell_conditions_[hash] == Condition::Deleted)
      break;
    ++attemps_count;
    hash =
        (FirstHashFunction(value) + attemps_count * SecondHashFunction(value)) %
        buffer_size_;
  }
}

bool HashTable::Contains(int value) {
  size_t hash = FirstHashFunction(value);
  int attemps_count = 0;
  while (cell_conditions_[hash] != Condition::Empty) {
    if (container_[hash] == value && cell_conditions_[hash] == Condition::Fill)
      return true;
    ++attemps_count;
    hash =
        (FirstHashFunction(value) + attemps_count * SecondHashFunction(value)) %
        buffer_size_;
  }
  return false;
}

void HashTable::Clear() {
  used_cell_ = 0;
  size_ = 0;
  for (auto& cell : cell_conditions_) cell = Condition::Empty;
}
size_t HashTable::Size() { return size_; }

size_t HashTable::FirstHashFunction(int key) {
  return floor(buffer_size_ *
               ((key * hash_coeficent) - floor(key * hash_coeficent)));
}
size_t HashTable::SecondHashFunction(int key) {
  return (key * buffer_size_ - 1) % buffer_size_;
}

void HashTable::Resize() {
  buffer_size_ *= 2;
  container_.resize(buffer_size_);
  cell_conditions_.resize(buffer_size_, Condition::Empty);
}

void HashTable::Rehash() {
  std::vector<int> used_elem;
  for (size_t i = 0; i < buffer_size_; ++i)
    if (cell_conditions_[i] == Condition::Fill)
      used_elem.push_back(container_[i]);

  Resize();
  Clear();
  for (auto& elem : used_elem) Insert(elem);
}