// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#include <vector>
#include <algorithm>
#include <stack>

class Tree {
 private:
    struct Node {
        char data;
        std::vector<Node*> children;
    };
    Node* root = nullptr;
    mutable std::vector<std::vector<char>> permutations;
    void generatePermutations(Node* node, std::vector<char>&
currentPerm) const {
        currentPerm.push_back(node->data);
        if (node->children.empty()) {
            permutations.push_back(currentPerm);
        } else {
            for (auto child : node->children) {
                generatePermutations(child, currentPerm);
            }
        }
        currentPerm.pop_back();
    }

 public:
    explicit Tree(const std::vector<char>& elements) {
        root = new Node{' ', {}};
        std::stack<Node*> nodes;
        nodes.push(root);
        for (auto i : elements) {
            bool nodeFound = false;
            for (auto& child : nodes.top()->children) {
                if (child->data == i) {
                    nodes.push(child);
                    nodeFound = true;
                    break;
                }
            }
            if (!nodeFound) {
                Node* newNode = new Node{i, {}};
                nodes.top()->children.push_back(newNode);
                nodes.push(newNode);
            }
        }
        std::vector<char> currentPerm;
        generatePermutations(root, currentPerm);
        std::sort(permutations.begin(), permutations.end());
    }
    ~Tree() {
        if (root != nullptr) {
            deleteSubtree(root);
        }
    }
    std::vector<char> getPerm(int n) const {
        if (n <= 0 || n > permutations.size()) {
            return std::vector<char>{};
        }
        return permutations[n - 1];
    }

 private:
    void deleteSubtree(Node* node) {
        for (auto child : node->children) {
            deleteSubtree(child);
        }
        delete node;
    }
};

#endif  // INCLUDE_TREE_H_
