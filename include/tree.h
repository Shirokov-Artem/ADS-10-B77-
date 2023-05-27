// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#include <vector>
#include <algorithm>

class Node {
 public:
  explicit Node(char val) : value(val) {}

  char value = ' ';
  std::vector<Node*> children;
};

class Tree {
 public:
  explicit Tree(const std::vector<char>& input) : elements(input), root(new Node(' ')) {
    for (char el : input) {
      insert(el);
    }
  }

  ~Tree() {
    remove(root);
  }

  bool search(const std::string& word) const {
    Node* current = root;
    for (char c : word) {
      bool found = false;
      for (Node* child : current->children) {
        if (child->value == c) {
          current = child;
          found = true;
          break;
        }
      }
      if (!found) {
        return false;
      }
    }
    return true;
  }

 private:
  void insert(char val) {
    Node* current = root;
    for (Node* child : current->children) {
      if (child->value == val) {
        current = child;
        return;
      }
    }
    Node* new_node = new Node(val);
    current->children.push_back(new_node);
    current = new_node;
  }

  void remove(Node* node) {
    for (Node* child : node->children) {
      remove(child);
    }
    delete node;
  }

  const std::vector<char> elements;
  Node* root;
};

#endif  // INCLUDE_TREE_H_
