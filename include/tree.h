// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#include <vector>
#include <algorithm>

class Tree {
 private:
    struct Node {
        char data;
        std::vector<Node*> childNodes;
    };
    std::vector<std::vector<char>> permutations;
    Node* root;
    void buildTree(Node* node, std::vector<char> chars) {
        if (chars.empty()) {
            return;
        }
        node->childNodes.push_back(new Node{chars[0]});
        buildTree(node->childNodes.back(), {chars.begin() + 1, chars.end()});
    }
    std::vector<char> traverse(Node* node, std::vector<char> prevChars) {
        prevChars.push_back(node->data);
        if (node->childNodes.empty()) {
            return prevChars;
        }
        for (auto childNode : node->childNodes) {
            permutations.push_back(traverse(childNode, prevChars));
        }
        return prevChars;
    }

 public:
    explicit Tree(std::vector<char> chars) {
        root = new Node{chars[0]};
        buildTree(root, {chars.begin() + 1, chars.end()});
        std::vector<char> tmp;
        traverse(root, tmp);
    }
    std::vector<char> getPermutation(int n) const {
        if (n < 1 || permutations.size() < n) {
            return std::vector<char>();
        }
        return permutations[n - 1];
    }
};

#endif  // INCLUDE_TREE_H_
