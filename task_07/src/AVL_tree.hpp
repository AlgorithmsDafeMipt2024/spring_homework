#pragma once

#include <algorithm>
#include <stdexcept>

class AVL_tree {
 public:
  void push(int value);
  void pop(int value);
  bool contains(int value);

  struct Node {
    int value;
    unsigned int height = 1;

    Node* left = nullptr;
    Node* right = nullptr;
    Node(int val) : value{val} {};
  };

 private:
  Node* root = nullptr;

  unsigned int height(Node* node);
  int balance_coeff(Node* node);
  void update_height(Node* node);
  Node* rotate_right(Node* node);
  Node* rotate_left(Node* node);
  Node* balance(Node* node);
  Node* insert(Node* node, int val);
  Node* find_min(Node* node);
  Node* remove_min(Node* node);
  Node* find(Node* node, int val);
  Node* remove(Node* node, int val);
};