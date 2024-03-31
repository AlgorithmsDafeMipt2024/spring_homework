#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <vector>

template <typename T>
struct Node {
  Node() : next{nullptr}, data{} {}
  ~Node() {}
  Node(T data_) : next{nullptr}, data{data_} {}
  void add_node(T data_);
  Node* next;
  T data;
};

template <typename T>
void Node<T>::add_node(T data_) {
  next = new Node(data_);
}

template <typename T>
struct LinkedList {
  LinkedList() : head{nullptr}, tail{nullptr}, sz{0} {}
  LinkedList(std::vector<T> v);
  ~LinkedList();
  LinkedList(const LinkedList& ll);
  void push_back(T elem);
  bool empty() const { return sz == 0; }
  bool find(T elem) const;
  int size() const { return sz; }
  T& operator[](int index);
  T& back();
  T& pop(int index);

 private:
  Node<T>* head;
  Node<T>* tail;
  int sz;
};

template <typename T>
LinkedList<T>::~LinkedList() {
  if (sz != 0) {
    Node<T>* curr = head;
    Node<T>* deletable = curr;
    for (int i = 0; i < sz; i++) {
      curr = curr->next;
      delete deletable;
      deletable = curr;
    }
  }
}

template <typename T>
LinkedList<T>::LinkedList(std::vector<T> v) {
  sz = v.size();
  if (v.empty()) {
    head = nullptr;
    tail = nullptr;
  } else {
    head = new Node<T>{v[0]};
    Node<T>* curr = head;
    for (int i = 1; i < sz; i++) {
      curr = curr->next;
      curr = new Node<T>{v[i]};
    }
    tail = curr;
  }
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList& ll) {
  sz = ll.size();
  head = new Node(head->data);
  Node<T>* curr = ll.head;
  Node<T>* curr_copy = head;
  for (int i = 1; i < ll.size(); i++) {
    curr = curr->next;
    curr_copy->add_node(curr->data);
    curr_copy = curr_copy->next;
  }
  tail = curr_copy;
}

template <typename T>
void LinkedList<T>::push_back(T elem) {
  if (tail != nullptr) {
    tail->add_node(elem);
    tail = tail->next;
  } else {
    tail = new Node<T>(elem);
    head = tail;
  }
  sz++;
}

template <typename T>
T& LinkedList<T>::operator[](int index) {
  if (index >= sz) throw std::runtime_error("index is out of range");
  Node<T>* curr = head;
  for (int i = 0; i < index; i++) {
    curr = curr->next;
  }
  return curr->data;
}

template <typename T>
T& LinkedList<T>::back() {
  if (tail == nullptr)
    throw std::runtime_error(
        "can't use method \"back()\": the linked list is empty");
  return tail->data;
}

template <typename T>
T& LinkedList<T>::pop(int index) {
  if (index >= sz) throw std::runtime_error("index out of range");

  if (sz == 1) {
    T& value = head->data;
    delete head;
    head = nullptr;
    tail = nullptr;
    sz--;
    return value;
  }

  if (index == 0) {
    T& value = head->data;
    Node<T>* prev = head;
    head = head->next;
    delete prev;
    sz--;
    return value;
  }

  Node<T>* prev = nullptr;
  Node<T>* curr = head;

  for (int i = 0; i < index; i++) {
    prev = curr;
    curr = curr->next;
  }

  prev->next = curr->next;
  T& value = curr->data;
  delete curr;
  curr = nullptr;
  sz--;
  return value;
}