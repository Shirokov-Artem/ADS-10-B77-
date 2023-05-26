// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#include <vector>
#include <algorithm>

class Tree {
 public:
    explicit Tree(const std::vector<char>& elements) {
        root = new Node;
        for (const char& element : elements) {
            Node* child = new Node{element};
            root->children.push_back(child);
        }
        buildPermutations(root);
    }
    std::vector<char> getPerm(int n) const {
        return permutations[n - 1];
    }
    ~Tree() {
        clearTree(root);
    }

 private:
    struct Node {
        char val;
        std::vector<Node*> children;
        Node() {}
        Node(char v) : val(v) {}
    };
    Node* root = nullptr;
    std::vector<std::vector<char>> permutations{};
    void buildPermutations(Node* node) {
        if (node->children.empty()) {
            std::vector<char> perm{};
            while (node) {
                perm.push_back(node->val);
                node = node->parent;
            }
            permutations.push_back(perm);
            return;
        }
        for (Node* child : node->children) {
            child->parent = node;
            buildPermutations(child);
        }
    }
    void clearTree(Node* node) {
        for (Node* child : node->children) {
            clearTree(child);
            delete child;
        }
    }
};
#endif  // INCLUDE_TREE_H_
