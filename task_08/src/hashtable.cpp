#include "hashtable.h"

#include <math.h>

#include <memory>
#include <stdexcept>

size_t HashTable::FirstHashFunc(std::size_t key) {
  return floor(buf_size * ((key * hash_coef) - floor(key * hash_coef)));
}

size_t HashTable::SecondHashFunc(std::size_t key) {
  return (key * buf_size - 1) % buf_size;
}

void HashTable::Clear() {
  cells = 0;
  size = 0;
  for (auto &cell : cell_states) cell = State::Vacant;
}

void HashTable::Resize() {
  buf_size *= 2;
  data.resize(buf_size);
  cell_states.resize(buf_size);
}

void HashTable::Rehash() {
  std::vector<std::size_t> subdata;
  for (std::size_t i{0}; i < buf_size; i++)
    if (cell_states[i] == State::Occupied) subdata.push_back(data[i]);

  Resize();
  Clear();
  for (auto &elem : subdata) Insert(elem);
}

bool HashTable::Contains(std::size_t value) {
  size_t hash = FirstHashFunc(value) % buf_size;
  std::size_t count = 0;
  while (cell_states[hash] != State::Vacant) {
    if (data[hash] == value && cell_states[hash] == State::Occupied)
      return true;
    count++;
    hash = (FirstHashFunc(value) + count * SecondHashFunc(value)) % buf_size;
  }
  return false;
}

void HashTable::Insert(std::size_t value) {
  size_t hash = FirstHashFunc(value) % buf_size;
  std::size_t count = 0;
  while (cell_states[hash] == State::Occupied) {
    if (data[hash] == value) return;
    count++;
    hash = (FirstHashFunc(value) + count * SecondHashFunc(value)) % buf_size;
  }

  data[hash] = value;
  cell_states[hash] = State::Occupied;
  cells++;
  size++;

  double cells_coefficient = double(cells) / buf_size;
  if (cells_coefficient >= rehash_coef) Rehash();
}

void HashTable::Remove(std::size_t value) {
  size_t hash = FirstHashFunc(value) % buf_size;
  std::size_t count = 0;
  while (cell_states[hash] != State::Vacant) {
    if (data[hash] == value && cell_states[hash] == State::Occupied) {
      cell_states[hash] = State::Deleted;
      size--;
      break;
    }
    if (data[hash] == value && cell_states[hash] == State::Deleted) break;

    count++;
    hash = (FirstHashFunc(value) + SecondHashFunc(value) * count) % buf_size;
  }
}