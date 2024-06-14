#include "hash_table.hpp"

#include <vector>

int HashFunctionHorner(const std::string& s, int table_size, const int key) {
  int hash_result = 0;
  for (int i = 0; i <= s.size(); ++i) {
    hash_result = (key * hash_result + s[i]) % table_size;
  }
  hash_result = (hash_result * 2 + 1) % table_size;
  return hash_result;
}

int HashTable::HashFunction1(const std::string& s, int table_size) {
  return HashFunctionHorner(s, table_size, table_size - 1);
}

int HashTable::HashFunction2(const std::string& s, int table_size) {
  return HashFunctionHorner(s, table_size, table_size + 1);
}

HashTable::HashTable()
    : size{0},
      buffer_size{default_size},
      cells_in_use{0},
      list{std::vector<Node*>(default_size, nullptr)} {}

HashTable::~HashTable() {
  for (int i = 0; i < buffer_size; ++i) {
    if (list[i] != nullptr) {
      delete list[i];
    }
  }
}

bool HashTable::Add(const str& value) {
  if (size + 1 > int(rehash_size * buffer_size)) {
    Increase_Size();
  } else if (cells_in_use > 2 * size) {
    Rehash();
  }

  int pos_h = HashFunction1(value, buffer_size);
  int step_h = HashFunction2(value, buffer_size);

  for (int i = 0; (list[pos_h] != nullptr) and i < buffer_size; i++) {
    if (list[pos_h]->value == value and list[pos_h]->state) {
      return false;  // value already in table
    }
    if (!list[pos_h]->state) {  // first pos that is empty (node was deleted)
      list[pos_h]->state = true;
      list[pos_h]->value = value;
      size++;
      return true;
    }
    pos_h = (pos_h + step_h) % buffer_size;
  }
  list[pos_h] = new Node(value);
  cells_in_use++;
  size++;
  return true;
}

bool HashTable::Remove(const str& value) {
  int pos_h = HashFunction1(value, buffer_size);
  int step_h = HashFunction2(value, buffer_size);

  for (int i = 0; (list[pos_h] != nullptr) and i < buffer_size; i++) {
    if (list[pos_h]->value == value and list[pos_h]->state) {
      list[pos_h]->state = false;
      size--;
      return true;
    }
    pos_h = (pos_h + step_h) % buffer_size;
  }
  return false;
}

bool HashTable::Find(const str& value) {
  int pos_h = HashFunction1(value, buffer_size);
  int step_h = HashFunction2(value, buffer_size);
  for (int i = 0; (list[pos_h] != nullptr) and i < buffer_size; i++) {
    if (list[pos_h]->value == value and list[pos_h]->state) {
      return true;
    }
    pos_h = (pos_h + step_h) % buffer_size;
  }
  return false;
}

void HashTable::Increase_Size() {
  int past_buffer_size = buffer_size;
  buffer_size *= 2;
  cells_in_use = 0;
  size = 0;

  std::vector<Node*> list2(buffer_size, nullptr);
  std::swap(list, list2);

  for (int i = 0; i < past_buffer_size; ++i) {
    if (list2[i] != nullptr) {
      if (list2[i]->state) {
        Add(list2[i]->value);
      }
      delete list2[i];
    }
  }
}

void HashTable::Rehash() {
  cells_in_use = 0;
  size = 0;

  std::vector<Node*> list2(buffer_size, nullptr);
  std::swap(list, list2);

  for (int i = 0; i < buffer_size; i++) {
    if (list2[i] != nullptr) {
      if (list2[i]->state) {
        Add(list2[i]->value);
      }
      delete list2[i];
    }
  }
}