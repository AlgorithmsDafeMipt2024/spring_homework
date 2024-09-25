#pragma once

#include <functional>
#include <string>
#include <vector>

using str = std::string;

int HashFunctionHorner(const str& s, int table_size, const int key);

class HashTable {
  static const int default_size = 8;
  constexpr static const double rehash_size = 0.75;

 public:
  HashTable();
  ~HashTable();
  bool Add(const str& value);
  bool Remove(const str& value);
  bool Find(const str& value);

 private:
  struct Node {
    std::string value;
    bool state;
    Node(const std::string& val) : value{val}, state{true} {}
    Node() : state{false} {}
  };

  std::vector<Node*> list;
  int size;          // amount of values in table
  int buffer_size;   // self explanatory
  int cells_in_use;  // amount of cells that are filled (even deleted values)

  int HashFunction1(const std::string& s, int table_size);
  int HashFunction2(const std::string& s, int table_size);

  void Increase_Size();
  void Rehash();
};