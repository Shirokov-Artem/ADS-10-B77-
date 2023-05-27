// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#include <vector>
#include <algorithm>

class Tree {
 public:
  explicit Tree(const std::vector<char>& elements) {
    for (char c : elements) {
      nodes_.push_back(Node{c});
    }
    buildTree(0, elements.size());
    generatePermutations();
  }

  const std::vector<char>& getPermutation(int n) const {
    if (n < 1 || n > permutations_.size()) {
      return empty_;
    }
    return permutations_[n-1];
  }

 private:
  struct Node {
    char c;
    std::vector<int> children;
  };

  void buildTree(int start, int end) {
    if (start >= end - 1) {
      return;
    }
    for (int i = start; i < end; ++i) {
      for (int j = i + 1; j < end; ++j) {
        nodes_[i].children.push_back(j);
        nodes_[j].children.push_back(i);
      }
      buildTree(i+1, end);
    }
  }

  void generatePermutations() {
    std::vector<char> current;
    generatePermutations(0, nodes_.size(), current);
  }

  void generatePermutations(int pos, int size, std::vector<char>& current) {
    if (pos == size) {
      permutations_.push_back(current);
      return;
    }
    for (int i : nodes_[pos].children) {
      if (std::find(current.begin(), current.end(), nodes_[i].c) == current.end()) {
        current.push_back(nodes_[i].c);
        generatePermutations(pos+1, size, current);
        current.pop_back();
      }
    }
  }

  std::vector<Node> nodes_;
  std::vector<std::vector<char>> permutations_;
  const std::vector<char> empty_;
};

#endif  // INCLUDE_TREE_H_
