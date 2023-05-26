// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#include <vector>
#include <algorithm>

class Tree {
 private:
    struct Node {
        char ch;
        std::vector<Node*> children;
    };
    std::vector<std::vector<char>> permutations;
    Node* root;
    void createTree(Node* node, std::vector<char> chars) {
        if (chars.empty()) {
            return;
        }
        node->children.push_back(new Node{chars[0]});
        createTree(node->children.back(), {chars.begin() + 1, chars.end()});
    }
    std::vector<char> traverse(Node* node, std::vector<char> prevChars) {
        prevChars.push_back(node->ch);
        if (node->children.empty()) {
            return prevChars;
        }
        for (auto child : node->children) {
            permutations.push_back(traverse(child, prevChars));
        }
        return prevChars;
    }

 public:
    explicit Tree(std::vector<char> chars) {
        root = new Node{chars[0]};
        createTree(root, {chars.begin() + 1, chars.end()});
        std::vector<char> tmp;
        traverse(root, tmp);
    }
    std::vector<char> getPermutation(int n) const {
        if (permutations.size() < n || n < 1) {
            return std::vector<char>();
        }
        return permutations[n - 1];
    }
};

#endif  // INCLUDE_TREE_H_
