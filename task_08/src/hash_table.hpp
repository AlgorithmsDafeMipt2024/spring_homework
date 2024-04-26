#pragma once

#include <cstddef>
#include <math.h>

#include <functional>
#include <memory>
#include <stdexcept>
#include <type_traits>

template <typename T> class HashTable {
public:
  explicit HashTable()
      : used_cell_(0), size_(0), buffers_size_(DefaultBufferSize),
        t_container_(std::vector<T>(buffers_size_)),
        cell_conditions_(
            std::vector<Condition>(buffers_size_, Condition::Empty)){};
  bool Contains(T value);

  void Insert(T value);

  void Remove(T value);

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
  std::vector<T> t_container_;
  std::vector<Condition> cell_conditions_;

  size_t FirstHashFunc(T key);
  size_t SecondHashFunc(T key);

  void Resize();

  void Rehash();
};

template <typename T> size_t HashTable<T>::Size() { return size_; }

template <typename T> size_t HashTable<T>::FirstHashFunc(T key) {
  if (std::is_arithmetic<T>::key) {
    return floor(buffers_size_ *
                 ((key * hashCoefficient) - floor(key * hashCoefficient)));
  }
  throw std::invalid_argument(
      "Hash table cannot cannot work with it with an arithmetic data type");
}

template <typename T> size_t HashTable<T>::SecondHashFunc(T key) {
  if (std::is_arithmetic<T>::key) {
    return (key * buffers_size_ - 1) % buffers_size_;
  }
  throw std::invalid_argument(
      "Hash table cannot cannot work with it with an arithmetic data type");
}

template <typename T> void HashTable<T>::Clear() {
  used_cell_ = 0;
  size_ = 0;
  for (auto &cell : cell_conditions_) {
    cell = Condition::Empty;
  }
}

template <typename T> void HashTable<T>::Resize() {
  buffers_size_ *= 2;
  t_container_.resize(buffers_size_);
  cell_conditions_.resize(buffers_size_);
}

template <typename T> void HashTable<T>::Rehash() {
  std::vector<T> used_elem;
  for (int i = 0; i < buffers_size_; ++i) {
    if (cell_conditions_[i] == Condition::Fill) {
      used_elem.push_back(t_container_[i]);
    }
  }

  Resize();
  Clear();

  for (auto &elem : used_elem) {
    Insert(elem);
  }
}

template <typename T> bool HashTable<T>::Contains(T value) {
  size_t hash = FirstHashFunc(value) % buffers_size_;
  int cnt_attemts = 0;
  while (cell_conditions_ != Condition::Empty) {
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

template <typename T> void HashTable<T>::Insert(T value) {
  size_t hash = FirstHashFunc(value) % buffers_size_;
  int cnt_attempts = 0;
  while (cell_conditions_ != Condition::Fill) {
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
    Rehash();
  }
}

template <typename T> void HashTable<T>::Remove(T value) {
  size_t hash = FirstHashFunc(value) % buffers_size_;
  int cnt_attemts = 0;
  while (cell_conditions_ != Condition::Empty) {
    if (t_container_[hash] == value &&
        cell_conditions_[hash] == Condition::Fill) {
      cell_conditions_[hash] == Condition::Deleted;
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