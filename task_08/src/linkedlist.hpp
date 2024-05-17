#pragma once

#include <cmath>
#include <cstddef>
#include <initializer_list>
#include <iostream>
#include <stdexcept>
#include <vector>

template <typename T>
struct Node {
  Node() : next{nullptr}, data{} {}
  Node(T data_) : next{nullptr}, data{data_} {}
  void AddNode(T data_);
  Node* next;
  T data;
};

template <typename T>
void Node<T>::AddNode(T data_) {
  next = new Node(data_);
}

template <typename T>
struct LinkedList {
  LinkedList() : head{nullptr}, tail{nullptr}, size_{0} {}
  LinkedList(std::initializer_list<T> initializer_list);
  ~LinkedList();
  LinkedList(const LinkedList& ll);

  void PushBack(T elem);

  bool Empty() const { return size_ == 0; }
  size_t Size() const { return size_; }

  T& operator[](size_t index);
  T& Back();
  T& Pop(size_t index);

  void Print();

 private:
  Node<T>* head;
  Node<T>* tail;
  size_t size_;
};

template <typename T>
LinkedList<T>::~LinkedList() {
  if (size_ != 0) {
    Node<T>* curr = head;
    Node<T>* deletable = curr;
    for (size_t i = 0; i < size_; i++) {
      curr = curr->next;
      delete deletable;
      deletable = curr;
    }
  }
}

template <typename T>
LinkedList<T>::LinkedList(std::initializer_list<T> initializer_list) {
  size_ = initializer_list.size();
  if (size_ == 0) {
    head = nullptr;
    tail = nullptr;
  } else {
    head = new Node<T>{*initializer_list.begin()};
    Node<T>* curr = head;
    bool first_iteration_flag = 1;
    for (const T& value : initializer_list) {
      if (first_iteration_flag)
        first_iteration_flag = 0;
      else {
        curr->AddNode(value);
        curr = curr->next;
      }
    }
    tail = curr;
  }
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList& ll) {
  size_ = ll.Size();
  head = new Node(head->data);
  Node<T>* curr = ll.head;
  Node<T>* curr_copy = head;
  for (size_t i = 1; i < ll.Size(); i++) {
    curr = curr->next;
    curr_copy->AddNode(curr->data);
    curr_copy = curr_copy->next;
  }
  tail = curr_copy;
}

template <typename T>
void LinkedList<T>::PushBack(T elem) {
  if (tail != nullptr) {
    tail->AddNode(elem);
    tail = tail->next;
  } else {
    tail = new Node<T>(elem);
    head = tail;
  }
  size_++;
}

template <typename T>
T& LinkedList<T>::operator[](size_t index) {
  if (index >= size_) throw std::runtime_error("index is out of range");
  Node<T>* curr = head;
  for (size_t i = 0; i < index; i++) {
    curr = curr->next;
  }
  return curr->data;
}

template <typename T>
T& LinkedList<T>::Back() {
  if (tail == nullptr)
    throw std::runtime_error(
        "can't use method \"Back()\": the linked list is empty");
  return tail->data;
}

template <typename T>
T& LinkedList<T>::Pop(size_t index) {
  if (index >= size_) throw std::runtime_error("index out of range");

  if (size_ == 1) {
    T& value = head->data;
    delete head;
    head = nullptr;
    tail = nullptr;
    size_--;
    return value;
  }

  if (index == 0) {
    T& value = head->data;
    Node<T>* prev = head;
    head = head->next;
    delete prev;
    size_--;
    return value;
  }

  Node<T>* prev = nullptr;
  Node<T>* curr = head;

  for (size_t i = 0; i < index; i++) {
    prev = curr;
    curr = curr->next;
  }

  prev->next = curr->next;
  T& value = curr->data;
  delete curr;
  curr = nullptr;
  size_--;
  return value;
}

template <typename T>
void LinkedList<T>::Print() {
  Node<T>* curr = head;
  while (curr != nullptr) {
    std::cout << curr->data << ' ';
    curr = curr->next;
  }
}