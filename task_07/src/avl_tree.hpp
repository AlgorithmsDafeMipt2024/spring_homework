#pragma once
struct TreeNode {
  int value;
  int height;
  TreeNode *left;
  TreeNode *right;

  explicit TreeNode(int value)
      : value(value), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree {
 public:
  AVLTree() : root(nullptr) {}

  ~AVLTree();

  void Insert(int value);

  [[nodiscard]] bool Find(int value) const;

  void Remove(int value);

 private:
  TreeNode *root;

  int Height(TreeNode *node) const;

  int BalanceFactor(TreeNode *node) const;

  void Update(TreeNode *node);

  TreeNode *RotateRight(TreeNode *old_node);

  TreeNode *RotateLeft(TreeNode *old_node);

  TreeNode *ReBalance(TreeNode *node);

  TreeNode *SearchMin(TreeNode *node);

  TreeNode *Insert(int value, TreeNode *&node);

  TreeNode *Remove(int value, TreeNode *&node);

  bool Find(int value, const TreeNode *node) const;

  void Clear(TreeNode *node);
};