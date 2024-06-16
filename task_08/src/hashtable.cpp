#include "hashtable.hpp"

#include <cmath>

unsigned HashTable::HashFunction1(int key) {
  return floor(buffer_size_ * ((key * HashCoeff) - floor(key * HashCoeff)));
}

unsigned HashTable::HashFunction2(int key) {
  return (key * buffer_size_ - 1) % buffer_size_;
}

void HashTable::Resize() {
  buffer_size_ *= 2;
  table_.resize(buffer_size_);
  cell_status_.resize(buffer_size_);
}

void HashTable::Clear() {
  size_ = 0;
  used_cell_size_ = 0;
  for (int i = 0; i < buffer_size_; i++) {
    cell_status_[i] = Status::Empty;
  }
}
void HashTable::Rehash() {
  std::vector<int> temp;
  for (int i = 0; i < buffer_size_; i++) {
    if (cell_status_[i] == Status::Fill) {
      temp.push_back(table_[i]);
    }
  }
  Resize();
  Clear();
  for (int i = 0; i < temp.size(); i++) {
    Insert(temp[i]);
  }
}

void HashTable::Insert(int key) {
  unsigned hash = HashFunction1(key) % buffer_size_;
  int counter = 0;
  while (cell_status_[hash] == Status::Fill) {
    if (table_[hash] == key) {
      return;
    }
    counter++;
    hash = (HashFunction1(key) + counter * HashFunction2(key)) % buffer_size_;
  }
  table_[hash] = key;
  cell_status_[hash] = Status::Fill;
  used_cell_size_++;
  size_++;

  double fill_coeff = double(used_cell_size_) / buffer_size_;
  if (fill_coeff >= RehashSize) Rehash();
}

void HashTable::Remove(int key) {
  unsigned hash = HashFunction1(key) % buffer_size_;
  int counter = 0;
  while (cell_status_[hash] != Status::Empty) {
    if (table_[hash] == key && cell_status_[hash] == Status::Deleted) {
      return;
    }
    if (table_[hash] == key && cell_status_[hash] == Status::Fill) {
      size_--;
      cell_status_[hash] = Status::Deleted;
      return;
    }
    counter++;
    hash = (HashFunction1(key) + counter * HashFunction2(key)) % buffer_size_;
  }
}

bool HashTable::Contains(int key) {
  unsigned hash = HashFunction1(key) % buffer_size_;
  int counter = 0;
  while (cell_status_[hash] != Status::Empty) {
    if (table_[hash] == key && cell_status_[hash] == Status::Fill) {
      return true;
    }
    counter++;
    hash = (HashFunction1(key) + counter * HashFunction2(key)) % buffer_size_;
  }
  return false;
}

unsigned HashTable::Size() { return size_; }