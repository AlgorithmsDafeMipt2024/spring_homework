#pragma once

#include <algorithm>
#include <cstddef>

template <typename T>
struct AVLTreeNode {
  AVLTreeNode(T key = T()) : key{key} {}

  AVLTreeNode(T key, AVLTreeNode* left, AVLTreeNode* right)
      : key{key}, left{left}, right{right} {}

  T key;

  size_t height = 1;

  AVLTreeNode* left = nullptr;
  AVLTreeNode* right = nullptr;

  size_t SubtreeHeight() { return this ? this->height : 0; }

  ~AVLTreeNode() {
    delete left;
    delete right;
  }
};
