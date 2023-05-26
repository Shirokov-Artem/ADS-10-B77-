// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#include <vector>
#include <algorithm>

class Tree {
    struct Node {
        char value;
        std::vector<Node*> children;
        Node(char value) : value(value) {}
        ~Node() {
            for (auto child : children) {
                delete child;
            }
        }
    };
    Node* root = nullptr;

 public:
    explicit Tree(std::vector<char> values) {
        root = new Node(' ');
        for (auto value : values) {
            root->children.push_back(new Node(value));
        }
        build_tree(root->children, values);
    }
    Node* get_root() const {
        return root;
    }
    void generate_permutations(const Node* node, 
std::vector<char> current_perm, 
std::vector<std::vector<char>>& permutations) const {
        current_perm.push_back(node->value);
        if (node->children.empty()) {
            permutations.push_back(current_perm);
        }
        for (auto child : node->children) {
            generate_permutations(child, current_perm, 
permutations);
        }
    }

 private:
    void build_tree(std::vector<Node*>& current_nodes, 
std::vector<char> remaining) {
        for (auto node : current_nodes) {
            auto iter = std::find(remaining.begin(), remaining.end(), 
node->value);
            if (iter != remaining.end()) {
                remaining.erase(iter);
                for (auto value : remaining) {
                    node->children.push_back(new Node(value));
                }
                build_tree(node->children, remaining);
                remaining.insert(iter, node->value);
            }
        }
    }
};

#endif  // INCLUDE_TREE_H_
