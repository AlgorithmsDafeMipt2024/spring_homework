#include "hash_table.hpp"

#include <math.h>

#include <memory>
#include <stdexcept>

size_t HashTable::FirstHashFunc(std::size_t key) {
  if constexpr (std::is_arithmetic<std::size_t>::value)
    return floor(buffers_size *
                 ((key * hashCoefficient) - floor(key * hashCoefficient)));
  throw std::invalid_argument("Invalid data type!");
}

size_t HashTable::SecondHashFunc(std::size_t key) {
  if constexpr (std::is_arithmetic<std::size_t>::value)
    return (key * buffers_size - 1) % buffers_size;
  throw std::invalid_argument("Invalid data type!");
}

void HashTable::Clear() {
  cells = 0;
  size = 0;
  for (auto &cell : cell_conditions) cell = Condition::Empty;
}

void HashTable::ReSize() {
  buffers_size *= 2;
  t_container.resize(buffers_size);
  cell_conditions.resize(buffers_size);
}

void HashTable::ReHash() {
  std::vector<std::size_t> subdata;
  for (std::size_t i{0};
       i < buffers_size && cell_conditions[i] == Condition::Fill; i++)
    subdata.push_back(t_container[i]);

  ReSize();
  Clear();
  for (auto &elem : subdata) Insert(elem);
}

bool HashTable::Contains(std::size_t value) {
  size_t hash = FirstHashFunc(value) % buffers_size;
  std::size_t count = 0;
  while (cell_conditions[hash] != Condition::Empty) {
    if (t_container[hash] == value && cell_conditions[hash] == Condition::Fill)
      return true;
    count++;
    hash =
        (FirstHashFunc(value) + count * SecondHashFunc(value)) % buffers_size;
  }
  return false;
}

void HashTable::Insert(std::size_t value) {
  size_t hash = FirstHashFunc(value) % buffers_size;
  std::size_t count = 0;
  while (cell_conditions[hash] == Condition::Fill) {
    if (t_container[hash] == value) return;
    count++;
    hash =
        (FirstHashFunc(value) + count * SecondHashFunc(value)) % buffers_size;
  }

  t_container[hash] = value;
  cell_conditions[hash] = Condition::Fill;
  cells++;
  size++;

  double cellss_coefficient = double(cells) / buffers_size;
  if (cellss_coefficient >= rehashCoefficient) ReHash();
}

void HashTable::Remove(std::size_t value) {
  size_t hash = FirstHashFunc(value) % buffers_size;
  std::size_t count = 0;
  while (cell_conditions[hash] != Condition::Empty) {
    if (t_container[hash] == value &&
        cell_conditions[hash] == Condition::Fill) {
      cell_conditions[hash] = Condition::Deleted;
      size--;
      break;
    }
    if (t_container[hash] == value &&
        cell_conditions[hash] == Condition::Deleted)
      break;

    count++;
    hash =
        (FirstHashFunc(value) + SecondHashFunc(value) * count) % buffers_size;
  }
}