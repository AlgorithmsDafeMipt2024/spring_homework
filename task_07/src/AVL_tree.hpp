#pragma once

#include <cstddef>
struct Node {
  Node(int k) : key{k} {}
  int key;
  unsigned height = 1;
  Node* left = nullptr;
  Node* right = nullptr;
};

class AVL_Tree {
 public:
  void Insert(int value);
  void Remove(int value);
  bool Contains(int value) const;

 private:
  Node* root_ = nullptr;

  Node* Insert(Node* root, int value);
  Node* Remove(Node* root, int value);
  bool Contains(Node* node, int value) const;

  Node* FindMin(Node* root) const;
  Node* RemoveMin(Node* root);

  Node* Balance(Node* node);

  Node* RightRotate(Node* node);
  Node* LeftRotate(Node* node);

  unsigned Height(Node* node) const;
  int Difference(Node* node) const;
  void FixHeight(Node* node);
};