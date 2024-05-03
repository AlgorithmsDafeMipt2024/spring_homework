#pragma once

#include <algorithm>
#include <cstddef>

template <typename T>
struct Node {
  T key;
  unsigned int height = 1 ;
  Node* left = nullptr;
  Node* right = nullptr;
  Node(T k):key{k}{};
};

template <typename T>
class Tree {  // AVl-tree
 public:
  void Push(int k);
  void Pop(int k);
  bool Contains(int k);

 private:
  unsigned int Height(Node<T>* n);
  int BFactor(Node<T>* n);
  void FixHeight(Node<T>* n);
  Node<T>* RotateRight(Node<T>* n);
  Node<T>* RotateLeft(Node<T>* n);
  Node<T>* Balance(Node<T>* n);
  Node<T>* Insert(Node<T>* n, T k);
  Node<T>* FindMin(Node<T>* n);
  Node<T>* RemoveMin(Node<T>* n);
  Node<T>* Remove(Node<T>* n, int k);
  Node<T>* Find(Node<T>* n, int k);
  Node<T>* root_ = nullptr;
};

template <typename T>
void Tree<T>::Push(int k) {
  root_ = Insert(root_, k);
}
template <typename T>
void Tree<T>::Pop(int k) {
  root_ = Remove(root_, k);
}
template <typename T>
bool Tree<T>::Contains(int k) {
  return Find(root_, k) ? true : false;
}

template <typename T>
unsigned int Tree<T>::Height(Node<T>* n) { return n ? n->height : 0; }

template <typename T>
int Tree<T>::BFactor(Node<T>* n) { return Height(n->right) - Height(n->left); }

template <typename T>
void Tree<T>::FixHeight(Node<T>* n) {
  unsigned int hl = Height(n->left);
  unsigned int hr = Height(n->right);
  n->height = std::max(hl, hr) + 1;
}

template <typename T>
Node<T>* Tree<T>::RotateRight(Node<T>* n) {
  Node<T>* q = n->left;
  n->left = q->right;
  q->right = n;
  FixHeight(n);
  FixHeight(q);
  return q;
}

template <typename T>
Node<T>* Tree<T>::RotateLeft(Node<T>* n) {
  Node<T>* q = n->right;
  n->right = q->left;
  q->left = n;
  FixHeight(q);
  FixHeight(n);
  return q;
}

template <typename T>
Node<T>* Tree<T>::Balance(Node<T>* n) {
  FixHeight(n);
  if (BFactor(n) == 2) {
    if (BFactor(n->right) < 0) n->right = RotateRight(n->right);
    return RotateLeft(n);
  }
  if (BFactor(n) == -2) {
    if (BFactor(n->left) > 0) n->left = RotateLeft(n->left);
    return RotateRight(n);
  }
  return n;
}

template <typename T>
Node<T>* Tree<T>::Insert(Node<T>* n, T k) {
  if (!n) return new Node(k);
  if (k < n->key)
    n->left = Insert(n->left, k);
  else
    n->right = Insert(n->right, k);
  return Balance(n);
}

template <typename T>
Node<T>* Tree<T>::FindMin(Node<T>* n) { return n->left ? FindMin(n->left) : n; }

template <typename T>
Node<T>* Tree<T>::RemoveMin(Node<T>* n) {
  if (n->left == nullptr) {
    return n->right;
  }
  n->left = RemoveMin(n->left);
  return Balance(n);
}

template <typename T>
Node<T>* Tree<T>::Remove(Node<T>* n, int k) {
  if (!n) {
    return nullptr;
  }
  if (k < n->key) {
    n->left = Remove(n->left, k);
  } else if (k > n->key) {
    n->right = Remove(n->right, k);
  } else {
    Node<T>* l = n->left;
    Node<T>* r = n->right;
    delete n;
    if (!r) {
      return l;
    }
    Node<T>* m = FindMin(r);
    m->right = RemoveMin(r);
    m->left = l;
    return Balance(m);
  }
  return Balance(n);
}

template <typename T>
Node<T>* Tree<T>::Find(Node<T>* n, int k) {
  if (n == nullptr || n->key == k) {
    return n;
  }
  if (k < n->key) {
    return Find(n->left, k);
  }
  if (k > n->key) {
    return Find(n->right, k);
  }
}