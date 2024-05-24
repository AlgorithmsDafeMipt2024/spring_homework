#pragma once

#include <algorithm>
#include <cstddef>

template <typename T>
struct Node {
  T key;
  std::size_t height = 1;
  Node* left = nullptr;
  Node* right = nullptr;
  Node(T key) : key(key){};
};

template <typename T>
class AVL_Tree {
 public:
  void Push(int k) { root = Insert(root, k); }
  void Pop(int k) { root = Remove(root, k); }
  bool Contains(int k) { return Find(root, k) ? true : false; }

 private:
  std::size_t Height(Node<T>* n) { return n ? n->height : 0; }
  int BFactor(Node<T>* n) { return Height(n->right) - Height(n->left); }

  void SetHeight(Node<T>* n) {
    n->height = std::max(Height(n->left), Height(n->right)) + 1;
  }

  Node<T>* RotateRight(Node<T>* n) {
    Node<T>* q = n->left;
    n->left = q->right;
    q->right = n;
    SetHeight(n);
    SetHeight(q);
    return q;
  }

  Node<T>* RotateLeft(Node<T>* n) {
    Node<T>* q = n->right;
    n->right = q->left;
    q->left = n;
    SetHeight(q);
    SetHeight(n);
    return q;
  }

  Node<T>* Balance(Node<T>* n) {
    SetHeight(n);
    switch (BFactor(n)) {
      case 2:
        if (BFactor(n->right) < 0) n->right = RotateRight(n->right);
        return RotateLeft(n);
      case -2:
        if (BFactor(n->left) > 0) n->left = RotateLeft(n->left);
        return RotateRight(n);
      default:
        return n;
    }
  }

  Node<T>* Insert(Node<T>* n, T k) {
    {
      if (!n) return new Node(k);
      if (k < n->key)
        n->left = Insert(n->left, k);
      else
        n->right = Insert(n->right, k);
      return Balance(n);
    }
  }

  Node<T>* FindMin(Node<T>* n) { return n->left ? FindMin(n->left) : n; }

  Node<T>* RemoveMin(Node<T>* n) {
    {
      if (!n->left) {
        return n->right;
      }
      n->left = RemoveMin(n->left);
      return Balance(n);
    }
  }

  Node<T>* Remove(Node<T>* n, int k) {
    if (!n) {
      return nullptr;
    }
    if (k == n->key) {
      if (!n->right) {
        return n->left;
      }
      FindMin(n->right)->right = RemoveMin(n->right);
      FindMin(n->right)->left = n->left;
      return Balance(FindMin(n->right));
    }
    k < n->key ? n->left = Remove(n->left, k) : n->right = Remove(n->right, k);
    return Balance(n);
  }

  Node<T>* Find(Node<T>* n, int k) {
    if (n == nullptr || n->key == k) {
      return n;
    }
    return k < n->key ? Find(n->left, k) : Find(n->right, k);
  }

  Node<T>* root = nullptr;
};