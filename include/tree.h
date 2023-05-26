// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#include <vector>
#include <algorithm>
#include <unordered_map>

class Tree {
 public:
    Tree(const std::vector<char>& input) {
        root = new Node;
        for (char c : input) {
            Node* child = new Node;
            child->val = c;
            root->children.push_back(child);
        }
        buildTree(input, root->children);
    }
    std::vector<char> getPerm(int n) {
        std::vector<char> permutation;
        findPermutation(root, permutation, n);
        return permutation;
    }
    ~Tree() {
        deleteTree(root);
    }

 private:
    struct Node {
        char val;
        std::vector<Node*> children;
        Node() {}
        Node(char v) : val(v) {}
    };
    Node* root;
    void buildTree(std::vector<char> input, std::vector<Node*>& children) {
        if (input.empty()) {
            return;
        }
        for (Node* child : children) {
            std::vector<char> newInput(input);
            newInput.erase(std::remove(newInput.begin(), newInput.end(), child->val), newInput.end());
            buildTree(newInput, child->children);
        }
    }
    void findPermutation(Node* node, std::vector<char>& permutation, int& n) {
        if (node) {
            for (Node* child : node->children) {
                int numPerms = countPermutations(child);
                if (n <= numPerms) {
                    permutation.push_back(child->val);
                    findPermutation(child, permutation, n);
                    break;
                }
                n -= numPerms;
            }
        }
    }
    int countPermutations(Node* node) {
        if (node->children.empty()) {
            return 1;
        }
        int count = 0;
        for (Node* child : node->children) {
            count += countPermutations(child);
        }
        return count;
    }
    void deleteTree(Node* node) {
        if (!node) {
            return;
        }
        for (Node* child : node->children) {
            deleteTree(child);
            delete child;
        }
    }
};

#endif  // INCLUDE_TREE_H_
