#pragma once
#include <math.h>

#include <memory>
#include <stdexcept>
#include <vector>

using namespace std;

template <typename T>
class HashTable {
 public:
  HashTable() : size_{0}, states_size_{0}, buffer_size_{8} {
    data_ = vector<T>(buffer_size_);
    states_ = vector<State>(buffer_size_, State::Free);
  }

  HashTable(const std::initializer_list<T> &data)
      : size_{data.size()}, states_size_{data.size()}, buffer_size_{8} {
    data_ = data;
    states_ = vector<State>(buffer_size_, State::Occupied);
  }

  void Insert(T value);

  void Remove(T value);

  bool Contains(T value);

  void Clear();

  size_t Size() const { return size_; }

  bool Empty() const { return size_ == 0; }

 private:
  constexpr static const double hash_coef = 0.74920592;
  constexpr static const double rehash_coef = 0.6;

  enum class State { Deleted, Occupied, Free };

  size_t buffer_size_;
  size_t size_;
  size_t states_size_;

  vector<T> data_;
  vector<State> states_;

  size_t FirstHashFunction(T key);
  size_t SecondHashFunction(T key);

  void Resize();

  void Rehash();
};

template <typename T>
void HashTable<T>::Insert(T value) {
  size_t hash = FirstHashFunction(value) % buffer_size_;
  size_t counter = 0;

  while (states_[hash] == State::Occupied) {
    if (data_[hash] == value) return;
    counter++;
    hash = (FirstHashFunction(value) + counter * SecondHashFunction(value)) %
           buffer_size_;
  }

  data_[hash] = value;
  states_[hash] = State::Occupied;
  states_size_++;
  size_++;

  double states_coefficient = double(states_size_) / double(buffer_size_);
  if (states_coefficient >= rehash_coef) Rehash();
}

template <typename T>
void HashTable<T>::Remove(T value) {
  size_t hash = FirstHashFunction(value) % buffer_size_;
  size_t counter = 0;

  while (states_[hash] != State::Free) {
    if (data_[hash] == value && states_[hash] == State::Occupied) {
      states_[hash] = State::Deleted;
      size_--;
      break;
    }
    if (data_[hash] == value && states_[hash] == State::Deleted) break;

    counter++;
    hash = (FirstHashFunction(value) + SecondHashFunction(value) * counter) %
           buffer_size_;
  }
}

template <typename T>
bool HashTable<T>::Contains(T value) {
  size_t hash = FirstHashFunction(value) % buffer_size_;
  size_t counter = 0;

  while (states_[hash] != State::Free) {
    if (data_[hash] == value && states_[hash] == State::Occupied) return true;
    counter++;
    hash = (FirstHashFunction(value) + counter * SecondHashFunction(value)) %
           buffer_size_;
  }
  return false;
}

template <typename T>
void HashTable<T>::Clear() {
  states_size_ = 0;
  size_ = 0;
  for (auto &cell : states_) cell = State::Free;
}

template <typename T>
size_t HashTable<T>::FirstHashFunction(T key) {
  return floor(buffer_size_ *
               ((double(key) * hash_coef) - floor(double(key) * hash_coef)));
}

template <typename T>
size_t HashTable<T>::SecondHashFunction(T key) {
  return int(key * buffer_size_ - 1) % (buffer_size_);
}

template <typename T>
void HashTable<T>::Resize() {
  buffer_size_ *= 2;
  data_.resize(buffer_size_);
  states_.resize(buffer_size_);
}

template <typename T>
void HashTable<T>::Rehash() {
  vector<T> sub_data;
  for (size_t i = 0; i < buffer_size_; i++)
    if (states_[i] == State::Occupied) sub_data.push_back(data_[i]);

  Resize();
  Clear();
  for (auto &elem : sub_data) Insert(elem);
}
