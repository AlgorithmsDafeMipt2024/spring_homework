#pragma once

#include <math.h>

#include <concepts>
#include <functional>
#include <memory>
#include <stdexcept>
#include <type_traits>

template <typename T>
class HashTable {
 public:
  explicit HashTable(std::function<size_t(T key)> hash_func)
      : used_cell_count_(0),
        size_(0),
        buffer_size_(DefaultBufferSize),
        table_container_(std::vector<T>(buffer_size_)),
        cell_conditions_(
            std::vector<Condition>(buffer_size_, Condition::Empty)),
        is_custom_hash_func_(true),
        CustomHashFunction(hash_func) {}

  HashTable()
      : used_cell_count_(0),
        size_(0),
        buffer_size_(DefaultBufferSize),
        table_container_(std::vector<T>(buffer_size_)),
        cell_conditions_(
            std::vector<Condition>(buffer_size_, Condition::Empty)),
        is_custom_hash_func_(false) {}

  bool Contains(T value) const;

  void Insert(T value);

  void Remove(T value);

  void Clear();

  size_t Size() const;

 private:
  enum class Condition { Fill, Deleted, Empty };
  constexpr static const double RehashCoefficient = 0.7;
  constexpr static const double HashCoefficient = 0.618033989;
  constexpr static const double DefaultBufferSize = 16;
  bool is_custom_hash_func_;

  size_t buffer_size_;
  size_t size_;
  unsigned used_cell_count_;

  std::vector<T> table_container_;
  std::vector<Condition> cell_conditions_;

  size_t SecondHashFunction(T key) const;

  size_t FirstHashFunction(T key) const;

  void Rehash();

  void ReSize();

  std::function<size_t(T key)> CustomHashFunction;
};

template <typename T>
size_t HashTable<T>::Size() const {
  return size_;
}

template <typename T>
concept tip = std::same_as<T, int>;

template <typename T>
size_t HashTable<T>::SecondHashFunction(T key) const {
  if constexpr (std::is_arithmetic<T>::value)
    return (key * buffer_size_ - 1) % buffer_size_;
  throw std::invalid_argument(
      "HashHashTable does not support this data type, use custom hash "
      "functions");
}

template <typename T>
size_t HashTable<T>::FirstHashFunction(T key) const {
  if constexpr (std::is_arithmetic<T>::value)
    return floor(buffer_size_ *
                 ((key * HashCoefficient) - floor(key * HashCoefficient)));
  throw std::invalid_argument(
      "HashHashTable does not support this data type, use custom hash "
      "functions");
}

template <typename T>
void HashTable<T>::Clear() {
  size_ = 0;
  used_cell_count_ = 0;
  std::fill(cell_conditions_.begin(), cell_conditions_.end(), Condition::Empty);
}

template <typename T>
void HashTable<T>::Insert(T value) {
  size_t hash;
  if (is_custom_hash_func_) {
    hash = CustomHashFunction(value) % buffer_size_;
    while (cell_conditions_[hash] == Condition::Fill) {
      if (table_container_[hash] == value) return;
      hash++;
    }
  } else {
    hash = FirstHashFunction(value) % buffer_size_;
    int attempt_count = 0;
    while (cell_conditions_[hash] == Condition::Fill) {
      if (table_container_[hash] == value) return;
      attempt_count++;
      hash = (FirstHashFunction(value) +
              attempt_count * SecondHashFunction(value)) %
             buffer_size_;
    }
  }

  table_container_[hash] = value;
  cell_conditions_[hash] = Condition::Fill;
  used_cell_count_++;
  size_++;

  auto fill_coefficient = double(used_cell_count_) / buffer_size_;
  if (fill_coefficient >= RehashCoefficient) Rehash();
}

template <typename T>
bool HashTable<T>::Contains(T value) const {
  size_t hash;
  if (is_custom_hash_func_) {
    hash = CustomHashFunction(value) % buffer_size_;
    while (cell_conditions_[hash] != Condition::Empty) {
      if (table_container_[hash] == value &&
          cell_conditions_[hash] == Condition::Fill)
        return true;
      hash++;
    }
  } else {
    hash = FirstHashFunction(value) % buffer_size_;
    int attempt_count = 0;
    while (cell_conditions_[hash] != Condition::Empty) {
      if (table_container_[hash] == value &&
          cell_conditions_[hash] == Condition::Fill)
        return true;
      attempt_count++;
      hash = (FirstHashFunction(value) +
              attempt_count * SecondHashFunction(value)) %
             buffer_size_;
    }
  }
  return false;
}

template <typename T>
void HashTable<T>::Remove(T value) {
  size_t hash;
  if (is_custom_hash_func_) {
    hash = CustomHashFunction(value);
    while (cell_conditions_[hash] != Condition::Empty) {
      if (table_container_[hash] == value &&
          cell_conditions_[hash] == Condition::Fill) {
        cell_conditions_[hash] = Condition::Deleted;
        size_--;
        break;
      }
      if (table_container_[hash] == value &&
          cell_conditions_[hash] == Condition::Deleted)
        break;
      hash++;
    }
  } else {
    hash = FirstHashFunction(value) % buffer_size_;
    int attempt_count = 0;
    while (cell_conditions_[hash] != Condition::Empty) {
      if (table_container_[hash] == value &&
          cell_conditions_[hash] == Condition::Fill) {
        cell_conditions_[hash] = Condition::Deleted;
        size_--;
        break;
      }
      if (table_container_[hash] == value &&
          cell_conditions_[hash] == Condition::Deleted)
        break;
      attempt_count++;
      hash = (FirstHashFunction(value) +
              attempt_count * SecondHashFunction(value)) %
             buffer_size_;
    }
  }
}

template <typename T>
void HashTable<T>::ReSize() {
  buffer_size_ *= 2;
  table_container_.resize(buffer_size_);
  cell_conditions_.resize(buffer_size_);
}

template <typename T>
void HashTable<T>::Rehash() {
  std::vector<T> outdated_container;
  for (int i = 0; i < buffer_size_; ++i)
    if (cell_conditions_[i] == Condition::Fill)
      outdated_container.push_back(table_container_[i]);

  ReSize();
  Clear();
  for (auto &elem : outdated_container) Insert(elem);
}
