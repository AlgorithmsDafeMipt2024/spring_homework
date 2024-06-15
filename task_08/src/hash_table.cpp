#include "hash_table.hpp"

#include <math.h>

#include <memory>
#include <stdexcept>

size_t HashTable::Size() { return size_; }

size_t HashTable::Hash(int key) {
  if constexpr (std::is_arithmetic<int>::value) {
    return floor(table_size_ *
                 ((key * hashCoefficient) - floor(key * hashCoefficient)));
  }
  throw std::invalid_argument(
      "Hash table cannot cannot work with it with an arithmetic data type");
}

void HashTable::Clear() {
  used_elements_ = 0;
  size_ = 0;
  for (auto &cell : elements_conditions_) {
    cell = Condition::Empty;
  }
}

void HashTable::ReSize() {
  table_size_ *= 2;
  table_container_.resize(table_size_);
  elements_conditions_.resize(table_size_);
}

void HashTable::ReHash() {
  std::vector<int> used_elem;
  for (int i = 0; i < table_size_; ++i) {
    if (elements_conditions_[i] == Condition::Fill) {
      used_elem.push_back(table_container_[i]);
    }
  }

  ReSize();
  Clear();

  for (auto &elem : used_elem) {
    Insert(elem);
  }
}

bool HashTable::Contains(int value) {
  size_t hash = Hash(value) % table_size_;
  int cnt_attemts = 0;
  while (elements_conditions_[hash] != Condition::Empty) {
    if (table_container_[hash] == value &&
        elements_conditions_[hash] == Condition::Fill) {
      return true;
    }
    cnt_attemts++;
    hash = (Hash(value) + cnt_attemts * Hash(value)) % table_size_;
  }
  return false;
}

void HashTable::Insert(int value) {
  size_t hash = Hash(value) % table_size_;
  int cnt_attempts = 0;
  while (elements_conditions_[hash] == Condition::Fill) {
    if (table_container_[hash] == value) {
      return;
    }
    cnt_attempts++;
    hash = (Hash(value) + cnt_attempts * Hash(value)) % table_size_;
  }

  table_container_[hash] = value;
  elements_conditions_[hash] = Condition::Fill;
  used_elements_++;
  size_++;

  double used_cells_coefficient = double(used_elements_) / table_size_;
  if (used_cells_coefficient >= rehashCoefficient) {
    ReHash();
  }
}

void HashTable::Remove(int value) {
  size_t hash = Hash(value) % table_size_;
  int cnt_attemts = 0;
  while (elements_conditions_[hash] != Condition::Empty) {
    if (table_container_[hash] == value &&
        elements_conditions_[hash] == Condition::Fill) {
      elements_conditions_[hash] = Condition::Deleted;
      size_--;
      break;
    }
    if (table_container_[hash] == value &&
        elements_conditions_[hash] == Condition::Deleted) {
      break;
    }
    cnt_attemts++;
    hash = (Hash(value) + Hash(value) * cnt_attemts) % table_size_;
  }
}
