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

template <typename T>
class AVLTree {
 public:
  AVLTree() : root{nullptr} {}

  bool Contains(int k) const { return Find(root, k) ? true : false; }

  void Push(int k) { root = Insert(root, k); }

  void Pop(int k) { root = Remove(root, k); }

  ~AVLTree() { delete root; }

 private:
  AVLTreeNode<T>* root;

  AVLTreeNode<T>* RotateRight(AVLTreeNode<T>* n) {
    AVLTreeNode<T>* l = n->left;
    n->left = l->right;
    l->right = n;
    UpdateHeight(n);
    UpdateHeight(l);

    return l;
  }

  AVLTreeNode<T>* RotateLeft(AVLTreeNode<T>* n) {
    AVLTreeNode<T>* r = n->right;
    n->right = r->left;
    r->left = n;
    UpdateHeight(r);
    UpdateHeight(n);

    return r;
  }

  AVLTreeNode<T>* Balance(AVLTreeNode<T>* n) {
    UpdateHeight(n);

    switch (BalanceFactor(n)) {
      case 2:
        if (BalanceFactor(n->right) < 0) n->right = RotateRight(n->right);
        return RotateLeft(n);

      case -2:
        if (BalanceFactor(n->left) > 0) n->left = RotateLeft(n->left);
        return RotateRight(n);

      default:
        return n;
    }
  }

  AVLTreeNode<T>* Insert(AVLTreeNode<T>* n, T k) {
    if (!n) return new AVLTreeNode(k);

    if (k < n->key)
      n->left = Insert(n->left, k);
    else
      n->right = Insert(n->right, k);

    return Balance(n);
  }

  AVLTreeNode<T>* FindMin(AVLTreeNode<T>* n) {
    return n->left ? FindMin(n->left) : n;
  }

  AVLTreeNode<T>* RemoveMin(AVLTreeNode<T>* n) {
    if (!n->left) return n->right;

    n->left = RemoveMin(n->left);
    return Balance(n);
  }

  AVLTreeNode<T>* Remove(AVLTreeNode<T>* n, T k) {
    if (!n) return nullptr;

    if (k == n->key) {
      if (!n->right) return n->left;

      FindMin(n->right)->right = RemoveMin(n->right);
      FindMin(n->right)->left = n->left;
      return Balance(FindMin(n->right));
    }

    k < n->key ? n->left = Remove(n->left, k) : n->right = Remove(n->right, k);
    return Balance(n);
  }

  AVLTreeNode<T>* Find(AVLTreeNode<T>* n, T k) const {
    if (n == nullptr || n->key == k) return n;

    return k < n->key ? Find(n->left, k) : Find(n->right, k);
  }

  long long BalanceFactor(AVLTreeNode<T>* n) {
    return n->right->SubtreeHeight() - n->left->SubtreeHeight();
  }

  void UpdateHeight(AVLTreeNode<T>* n) {
    n->height =
        std::max(n->left->SubtreeHeight(), n->right->SubtreeHeight()) + 1;
  }
};
