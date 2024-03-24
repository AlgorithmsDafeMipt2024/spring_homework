#pragma once

// std libs:
#include <functional>
#include <optional>
#include <string>

// MEANS: узел в дереве
class Node {
 public:
  Node();

  Node(int key);

  Node(int key, const std::string& data);

  Node(Node* parent, Node* left_child, Node* right_child);

  // vars

  // MEANS: указатель на узел-родителя
  Node* parent;

  // MEANS: указатель на узел-родителя
  Node* left_child;

  // MEANS: указатель на узел-родителя
  Node* right_child;

  int key;

  // MEANS: значение строки в текущем узле
  std::string data;

  // ~vars
};

// MEANS: бинарное дерево поиска
class BinarySearchTree {
 public:
  // methods

  BinarySearchTree(Node* main_parent);

  // MEANS: функция, которая добавляет элемент в дерево
  // ARGS: [int]: ключ
  // ARGS: [const std::string&]: строка-элемент, которую нужно добавить
  // RETURNS: [bool]: факт успешного добавления
  bool Add(int key, const std::string& s);

  // MEANS: функция, которая находит элемент в дереве
  // ARGS: [int]: ключ
  // RETURNS: [std::optional<std::string>]: найденная строка элемента
  std::optional<std::string> Find(int key) const;

  // MEANS: функция, которая удаляет элемент из дерева
  // ARGS: [int]: ключ
  // RETURNS: [std::optional<std::string>]: удаленная строка элемента
  std::optional<std::string> Remove(int key);

  // DOES: применяет функцию ко всему дереву
  // ARGS: [std::function<void(int, const std::string&)>]: функция
  void ForEach(std::function<void(int, const std::string&)>);

  // ~methods

 private:
  // methods

  // MEANS: доп. функция, которая ищет минимум в дереве
  // ARGS: [Node*]: узел, с которого искать
  // RETURNS: [Node*]: узел-минимум
  inline Node* Minimum(Node* n) {
    if (n->left_child == nullptr) return n;
    return Minimum(n->left_child);
  }

  // MEANS: доп. функция, которая ищет максимум в дереве
  // ARGS: [Node*]: узел, с которого искать
  // RETURNS: [Node*]: узел-максимум
  inline Node* Maximum(Node* n) {
    if (n->right_child == nullptr) return n;
    return Maximum(n->right_child);
  }

  // MEANS: доп. функция, которая находит узел в дереве
  // ARGS: [Node*]: узел, с которого искать; [int]: ключ
  // RETURNS: [Node*]: найденный узел
  Node* Search(Node* n, int key) const;

  // MEANS: доп. функция, которая добавляет узел в дерево
  // ARGS: [Node*]: узел, который надо добавить
  // RETURNS: [bool]: факт успешного добавления
  bool Insert(Node* n);

  // MEANS: доп. функция, которая удаляет узел в дереве
  // ARGS: [Node*]: узел, который надо удалить; [int]: ключ
  // RETURNS: [Node*]: удаляемый узел
  Node* Delete(Node* n, int key);

  // ~methods

  // vars

  // MEANS: первый узел (корень)
  Node* main_parent_;

  // ~vars
};
