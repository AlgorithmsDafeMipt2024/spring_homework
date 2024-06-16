#pragma once

#include <algorithm>
#include <cstddef>

template <typename T>
struct Node {
  T key;
  unsigned int height = 1;
  Node* left = nullptr;
  Node* right = nullptr;
  Node(T k) : key{k} {};
};

template <typename T>
class Tree {  // AVl-tree
 public:
  void Push(int k);
  void Pop(int k);
  bool Contains(int k);

 private:
  unsigned int Height(Node<T>* node_ptr);
  int BFactor(Node<T>* node_ptr);
  void FixHeight(Node<T>* node_ptr);
  Node<T>* RotateRight(Node<T>* node_ptr);
  Node<T>* RotateLeft(Node<T>* node_ptr);
  Node<T>* Balance(Node<T>* node_ptr);
  Node<T>* Insert(Node<T>* node_ptr, T k);
  Node<T>* FindMin(Node<T>* node_ptr);
  Node<T>* RemoveMin(Node<T>* node_ptr);
  Node<T>* Remove(Node<T>* node_ptr, int k);
  Node<T>* Find(Node<T>* node_ptr, int k);
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
unsigned int Tree<T>::Height(Node<T>* node_ptr) {
  return node_ptr ? node_ptr->height : 0;
}

template <typename T>
int Tree<T>::BFactor(Node<T>* node_ptr) {
  return Height(node_ptr->right) - Height(node_ptr->left);
}

template <typename T>
void Tree<T>::FixHeight(Node<T>* node_ptr) {
  unsigned int hl = Height(node_ptr->left);
  unsigned int hr = Height(node_ptr->right);
  node_ptr->height = std::max(hl, hr) + 1;
}

template <typename T>
Node<T>* Tree<T>::RotateRight(Node<T>* node_ptr) {
  Node<T>* q = node_ptr->left;
  node_ptr->left = q->right;
  q->right = node_ptr;
  FixHeight(node_ptr);
  FixHeight(q);
  return q;
}

template <typename T>
Node<T>* Tree<T>::RotateLeft(Node<T>* node_ptr) {
  Node<T>* q = node_ptr->right;
  node_ptr->right = q->left;
  q->left = node_ptr;
  FixHeight(q);
  FixHeight(node_ptr);
  return q;
}

template <typename T>
Node<T>* Tree<T>::Balance(Node<T>* node_ptr) {
  FixHeight(node_ptr);
  if (BFactor(node_ptr) == 2) {
    if (BFactor(node_ptr->right) < 0)
      node_ptr->right = RotateRight(node_ptr->right);
    return RotateLeft(node_ptr);
  }
  if (BFactor(node_ptr) == -2) {
    if (BFactor(node_ptr->left) > 0)
      node_ptr->left = RotateLeft(node_ptr->left);
    return RotateRight(node_ptr);
  }
  return node_ptr;
}

template <typename T>
Node<T>* Tree<T>::Insert(Node<T>* node_ptr, T k) {
  if (!node_ptr) return new Node(k);
  if (k < node_ptr->key)
    node_ptr->left = Insert(node_ptr->left, k);
  else
    node_ptr->right = Insert(node_ptr->right, k);
  return Balance(node_ptr);
}

template <typename T>
Node<T>* Tree<T>::FindMin(Node<T>* node_ptr) {
  return node_ptr->left ? FindMin(node_ptr->left) : node_ptr;
}

template <typename T>
Node<T>* Tree<T>::RemoveMin(Node<T>* node_ptr) {
  if (node_ptr->left == nullptr) {
    return node_ptr->right;
  }
  node_ptr->left = RemoveMin(node_ptr->left);
  return Balance(node_ptr);
}

template <typename T>
Node<T>* Tree<T>::Remove(Node<T>* node_ptr, int k) {
  if (!node_ptr) {
    return nullptr;
  }
  if (k < node_ptr->key) {
    node_ptr->left = Remove(node_ptr->left, k);
  } else if (k > node_ptr->key) {
    node_ptr->right = Remove(node_ptr->right, k);
  } else {
    Node<T>* l = node_ptr->left;
    Node<T>* r = node_ptr->right;
    delete node_ptr;
    if (!r) {
      return l;
    }
    Node<T>* m = FindMin(r);
    m->right = RemoveMin(r);
    m->left = l;
    return Balance(m);
  }
  return Balance(node_ptr);
}

template <typename T>
Node<T>* Tree<T>::Find(Node<T>* node_ptr, int k) {
  if (node_ptr == nullptr || node_ptr->key == k) {
    return node_ptr;
  }
  if (k < node_ptr->key) {
    return Find(node_ptr->left, k);
  }
  if (k > node_ptr->key) {
    return Find(node_ptr->right, k);
  }
}