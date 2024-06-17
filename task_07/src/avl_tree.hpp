#include <algorithm>
#include <memory>
#include <stdexcept>

template <typename T>
struct Node {
  explicit Node(T k) : key{k}, left{nullptr}, right{nullptr}, height{1} {}
  T key;
  size_t height;
  Node<T>* left;
  Node<T>* right;
};

template <typename T>
class AVLTree {
 public:
  AVLTree() : root_{nullptr} {}

  void Insert(T value);

  void Remove(T value);

  bool Contains(T value) const;

 private:
  Node<T>* root_;

  Node<T>* Insert(Node<T>* node, T value);

  Node<T>* Remove(Node<T>* node, T value);

  bool Contains(const Node<T>* node, T value) const;

  Node<T>* Balance(Node<T>* node);

  Node<T>* FindMin(Node<T>* node) const;

  Node<T>* RemoveMin(Node<T>* node);

  Node<T>* LeftRotate(Node<T>* node);

  Node<T>* RightRotate(Node<T>* node);

  size_t Height(Node<T>* node) const;

  void UpdateHeight(Node<T>* node);

  int Difference(Node<T>* node) const;
};

template <typename T>
void AVLTree<T>::Insert(T value) {
  root_ = Insert(root_, value);
}

template <typename T>
void AVLTree<T>::Remove(T value) {
  root_ = Remove(root_, value);
}

template <typename T>
bool AVLTree<T>::Contains(T value) const {
  return Contains(root_, value);
}

template <typename T>
Node<T>* AVLTree<T>::Insert(Node<T>* node, T value) {
  if (!node) return new Node<T>(value);
  if (value < node->key)
    node->left = Insert(node->left, value);
  else if (value > node->key)
    node->right = Insert(node->right, value);
  return Balance(node);
}

template <typename T>
Node<T>* AVLTree<T>::Remove(Node<T>* node, T value) {
  if (!node) return nullptr;
  if (value < node->key)
    node->left = Remove(node->left, value);
  else if (value > node->key)
    node->right = Remove(node->right, value);
  else if (value == node->key) {
    Node<T>* new_node_1 = node->left;
    Node<T>* new_node_2 = node->right;
    delete node;
    if (!new_node_2) return new_node_1;
    Node<T>* min = FindMin(new_node_2);
    min->right = RemoveMin(new_node_2);
    min->left = new_node_1;
    return Balance(min);
  }
  return Balance(node);
}

template <typename T>
bool AVLTree<T>::Contains(const Node<T>* node, T value) const {
  if (!node) return false;
  if (value < node->key) return Contains(node->left, value);
  if (value > node->key) return Contains(node->right, value);
  return true;
}

template <typename T>
Node<T>* AVLTree<T>::Balance(Node<T>* node) {
  UpdateHeight(node);
  if (Difference(node) == 2) {
    if (Difference(node->right) < 0) node->right = RightRotate(node->right);
    return LeftRotate(node);
  }
  if (Difference(node) == -2) {
    if (Difference(node->left) > 0) node->left = LeftRotate(node->left);
    return RightRotate(node);
  }
  return node;
}

template <typename T>
Node<T>* AVLTree<T>::FindMin(Node<T>* node) const {
  if (!node->left) return node;
  return FindMin(node->left);
}

template <typename T>
Node<T>* AVLTree<T>::RemoveMin(Node<T>* node) {
  if (!node->left) return node->right;
  node->left = RemoveMin(node->left);
  return Balance(node);
}

template <typename T>
Node<T>* AVLTree<T>::LeftRotate(Node<T>* node) {
  Node<T>* new_node = node->right;
  node->right = new_node->left;
  new_node->left = node;
  UpdateHeight(node);
  UpdateHeight(new_node);
  return new_node;
}

template <typename T>
Node<T>* AVLTree<T>::RightRotate(Node<T>* node) {
  Node<T>* new_node = node->left;
  node->left = new_node->right;
  new_node->right = node;
  UpdateHeight(node);
  UpdateHeight(new_node);
  return new_node;
}

template <typename T>
size_t AVLTree<T>::Height(Node<T>* node) const {
  return node ? node->height : 0;
}

template <typename T>
void AVLTree<T>::UpdateHeight(Node<T>* node) {
  size_t left_height = Height(node->left);
  size_t right_height = Height(node->right);
  node->height = std::max(left_height, right_height) + 1;
}

template <typename T>
int AVLTree<T>::Difference(Node<T>* node) const {
  return Height(node->right) - Height(node->left);
}
