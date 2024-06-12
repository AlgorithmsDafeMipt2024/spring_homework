#include <iostream>
#include <vector>

template <class T>
struct Node {
  Node(T value) : data(value), leftptr(nullptr), rightptr(nullptr) {}
  T data;
  Node* leftptr;
  Node* rightptr;
};

template <class T>
class BinaryTree {
 public:
  BinaryTree() : root(nullptr) {}
  ~BinaryTree() { destroyTree(root); }

  void insert(int value) { root = insertRecursive(root, value); }

  bool search(int value) { return searchRecursive(root, value); }

  std::vector<T> inorderTraversal();
  std::vector<T> preorderTraversal();
  std::vector<T> postorderTraversal();

 private:
  Node<T>* root;
  Node<T>* insertRecursive(Node<T>* node, int value);
  bool searchRecursive(Node<T>* node, int value);
  void inorderTraversalRecursive(Node<T>* node, std::vector<T>& ans);
  void preorderTraversalRecursive(Node<T>* node, std::vector<T>& ans);
  void postorderTraversalRecursive(Node<T>* node, std::vector<T>& ans);
  void destroyTree(Node<T>* node);
};

template <class T>
std::vector<T> BinaryTree<T>::inorderTraversal() {
  std::vector<T> ans;
  inorderTraversalRecursive(root, ans);
  return ans;
}

template <class T>
std::vector<T> BinaryTree<T>::preorderTraversal() {
  std::vector<T> ans;
  preorderTraversalRecursive(root, ans);
  return ans;
}

template <class T>
std::vector<T> BinaryTree<T>::postorderTraversal() {
  std::vector<T> ans;
  postorderTraversalRecursive(root, ans);
  return ans;
}

template <class T>
void BinaryTree<T>::inorderTraversalRecursive(Node<T>* node,
                                              std::vector<T>& ans) {
  if (node == nullptr) {
    return;
  }
  inorderTraversalRecursive(node->leftptr, ans);
  ans.push_back(node->data);
  inorderTraversalRecursive(node->rightptr, ans);
}

template <class T>
void BinaryTree<T>::preorderTraversalRecursive(Node<T>* node,
                                               std::vector<T>& ans) {
  if (node == nullptr) {
    return;
  }
  ans.push_back(node->data);
  preorderTraversalRecursive(node->leftptr, ans);
  preorderTraversalRecursive(node->rightptr, ans);
}

template <class T>
void BinaryTree<T>::postorderTraversalRecursive(Node<T>* node,
                                                std::vector<T>& ans) {
  if (node == nullptr) {
    return;
  }
  postorderTraversalRecursive(node->leftptr, ans);
  postorderTraversalRecursive(node->rightptr, ans);
  ans.push_back(node->data);
}

template <class T>
bool BinaryTree<T>::searchRecursive(Node<T>* node, int value) {
  if (node == nullptr) {
    return false;
  }

  if (value == node->data) {
    return true;
  }

  if (value < node->data) {
    return searchRecursive(node->leftptr, value);
  } else {
    return searchRecursive(node->rightptr, value);
  }
}

template <class T>
Node<T>* BinaryTree<T>::insertRecursive(Node<T>* node, int value) {
  if (node == nullptr) {
    return new Node(value);
  }

  if (value < node->data) {
    node->leftptr = insertRecursive(node->leftptr, value);
  } else if (value > node->data) {
    node->rightptr = insertRecursive(node->rightptr, value);
  }

  return node;
}

template <class T>
void BinaryTree<T>::destroyTree(Node<T>* node) {
  if (node == nullptr) {
    return;
  }

  destroyTree(node->leftptr);
  destroyTree(node->rightptr);
  delete node;
}