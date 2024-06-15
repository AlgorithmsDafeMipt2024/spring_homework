#include <vector>

struct Node {
  int value;
  int Height;
  Node* left;
  Node* right;

  Node(int k) {
    value = k;
    left = right = 0;
    Height = 1;
  }
};

int Height(Node* p) { return p ? p->Height : 0; }

int Bfactor(Node* p) { return Height(p->right) - Height(p->left); }

void FixHeight(Node* p) {
  int hl = Height(p->left);
  int hr = Height(p->right);
  p->Height = (hl > hr ? hl : hr) + 1;
}

Node* Rotateright(Node* p) {
  Node* q = p->left;
  p->left = q->right;
  q->right = p;
  FixHeight(p);
  FixHeight(q);
  return q;
}

Node* Rotateleft(Node* q) {
  Node* p = q->right;
  q->right = p->left;
  p->left = q;
  FixHeight(q);
  FixHeight(p);
  return p;
}

Node* Balance(Node* p) {
  FixHeight(p);
  if (Bfactor(p) == 2) {
    if (Bfactor(p->right) < 0) p->right = Rotateright(p->right);
    return Rotateleft(p);
  }
  if (Bfactor(p) == -2) {
    if (Bfactor(p->left) > 0) p->left = Rotateleft(p->left);
    return Rotateright(p);
  }
  return p;
}

Node* Insert(Node* p, int k) {
  if (!p) return new Node(k);
  if (k < p->value)
    p->left = Insert(p->left, k);
  else
    p->right = Insert(p->right, k);
  return Balance(p);
}

Node* Find(Node* root, int value) {
  if (root == nullptr) {
    return nullptr;
  }

  if (value < root->value) {
    return Find(root->left, value);
  } else if (value > root->value) {
    return Find(root->right, value);
  } else {
    return root;
  }
}

Node* FindMin(Node* p) { return p->left ? FindMin(p->left) : p; }

Node* Removemin(Node* p) {
  if (p->left == 0) return p->right;
  p->left = Removemin(p->left);
  return Balance(p);
}

Node* Remove(Node* p, int k) {
  if (!p) return 0;
  if (k < p->value)
    p->left = Remove(p->left, k);
  else if (k > p->value)
    p->right = Remove(p->right, k);
  else {
    Node* q = p->left;
    Node* r = p->right;
    delete p;
    if (!r) return q;
    Node* min = FindMin(r);
    min->right = Removemin(r);
    min->left = q;
    return Balance(min);
  }
  return Balance(p);
}

void BuildBinarySearchTree(std::vector<int>& arr, Node*& root) {
  for (int i = 0; i < arr.size(); ++i) {
    root = Insert(root, arr[i]);
  }
}