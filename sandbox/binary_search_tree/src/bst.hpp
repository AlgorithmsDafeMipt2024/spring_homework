#pragma once

// std libs:
#include <functional>
#include <optional>
#include <string>

class Node {
 public:
  Node(Node* parent, Node* left_child, Node* right_child);

 private:
  // vars

  // MEANS: указатель на узел-родителя
  Node* parent_ = nullptr;

  // MEANS: указатель на узел-родителя
  Node* left_child_ = nullptr;

  // MEANS: указатель на узел-родителя
  Node* right_child_ = nullptr;

  int key;

  // MEANS: значение строки в текущем узле
  std::string data;

  // ~vars
};

class BinarySearchTree {
 public:
  // methods

  BinarySearchTree(Node* parent);

  // MEANS: функция, которая добавляет элемент в дерево
  // ARGS: [int]: ключ
  // ARGS: [const std::string&]: строка-элемент, которую нужно добавить
  // RETURNS: [bool]: факт добавления строки
  bool Add(int key, const std::string& s);

  // MEANS: функция, которая находит элемент в дереве
  // ARGS: [int]: ключ
  // RETURNS: [std::optional<std::string>]: найденная строка
  std::optional<std::string> Find(int key) const;

  // MEANS: функция, которая удаляет элемент из дерева
  // ARGS: [int]: ключ
  // RETURNS: [std::optional<std::string>]: удаленная строка
  std::optional<std::string> Remove(int key);

  // DOES: применяет функцию ко всему дереву
  // ARGS: [std::function<void(int, const std::string&)>]: функция
  void ForEach(std::function<void(int, const std::string&)>);

  // ~methods

 private:
  // vars

  // MEANS: первый узел (корень)
  Node* main_parent_;

  // ~vars
};
