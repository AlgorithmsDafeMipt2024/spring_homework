#include "hash_table.hpp"

#include <math.h>

#include <memory>
#include <stdexcept>

size_t HashTable::Size() { return size_; }

size_t HashTable::FirstHashFunc(int key) {
  if constexpr (std::is_arithmetic<int>::value) {
    return floor(buffers_size_ *
                 ((key * hashCoefficient) - floor(key * hashCoefficient)));
  }
  throw std::invalid_argument(
      "Hash table cannot cannot work with it with an arithmetic data type");
}

size_t HashTable::SecondHashFunc(int key) {
  if constexpr (std::is_arithmetic<int>::value) {
    return (key * buffers_size_ - 1) % buffers_size_;
  }
  throw std::invalid_argument(
      "Hash table cannot cannot work with it with an arithmetic data type");
}

void HashTable::Clear() {
  used_cell_ = 0;
  size_ = 0;
  for (auto &cell : cell_conditions_) {
    cell = Condition::Empty;
  }
}

void HashTable::ReSize() {
  buffers_size_ *= 2;
  t_container_.resize(buffers_size_);
  cell_conditions_.resize(buffers_size_);
}

void HashTable::ReHash() {
  std::vector<int> used_elem;
  for (int i = 0; i < buffers_size_; ++i) {
    if (cell_conditions_[i] == Condition::Fill) {
      used_elem.push_back(t_container_[i]);
    }
  }

  ReSize();
  Clear();

  for (auto &elem : used_elem) {
    Insert(elem);
  }
}

bool HashTable::Contains(int value) {
  size_t hash = FirstHashFunc(value) % buffers_size_;
  int cnt_attemts = 0;
  while (cell_conditions_[hash] != Condition::Empty) {
    if (t_container_[hash] == value &&
        cell_conditions_[hash] == Condition::Fill) {
      return true;
    }
    cnt_attemts++;
    hash = (FirstHashFunc(value) + cnt_attemts * SecondHashFunc(value)) %
           buffers_size_;
  }
  return false;
}

void HashTable::Insert(int value) {
  size_t hash = FirstHashFunc(value) % buffers_size_;
  int cnt_attempts = 0;
  while (cell_conditions_[hash] == Condition::Fill) {
    if (t_container_[hash] == value) {
      return;
    }
    cnt_attempts++;
    hash = (FirstHashFunc(value) + cnt_attempts * SecondHashFunc(value)) %
           buffers_size_;
  }

  t_container_[hash] = value;
  cell_conditions_[hash] = Condition::Fill;
  used_cell_++;
  size_++;

  double used_cells_coefficient = double(used_cell_) / buffers_size_;
  if (used_cells_coefficient >= rehashCoefficient) {
    ReHash();
  }
}

void HashTable::Remove(int value) {
  size_t hash = FirstHashFunc(value) % buffers_size_;
  int cnt_attemts = 0;
  while (cell_conditions_[hash] != Condition::Empty) {
    if (t_container_[hash] == value &&
        cell_conditions_[hash] == Condition::Fill) {
      cell_conditions_[hash] = Condition::Deleted;
      size_--;
      break;
    }
    if (t_container_[hash] == value &&
        cell_conditions_[hash] == Condition::Deleted) {
      break;
    }
    cnt_attemts++;
    hash = (FirstHashFunc(value) + SecondHashFunc(value) * cnt_attemts) %
           buffers_size_;
  }
}