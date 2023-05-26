// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#include <vector>
#include <algorithm>

class Tree {
    struct Node {
        char value = 0;
        std::vector<Node*> children;
    };
    Node* root = nullptr;

 public:
    Tree(std::vector<char> values) {
        root = new Node;
        for (auto value : values) {
            Node* child_node = new Node;
            child_node->value = value;
            root->children.push_back(child_node);
        }
        build_tree(values, root->children);
    }
    ~Tree() {
        delete_node(root);
    }
    Node* get_root() const {
        return root;
    }
    void generate_permutations(Node* node, std::vector<char> current_perm, 
std::vector<std::vector<char>>& permutations) const {
        current_perm.push_back(node->value);
        if (node->children.empty()) {
            permutations.push_back(current_perm);
        }
        for (auto child : node->children) {
            generate_permutations(child, current_perm, permutations);
        }
    }

 private:
    void delete_node(Node* node) {
        for (auto child : node->children) {
            delete_node(child);
        }
        delete node;
    }
    void build_tree(std::vector<char> remaining, std::vector<Node*>& current_nodes) {
        for (auto node : current_nodes) {
            auto iter = std::find(remaining.begin(), remaining.end(), node->value);
            if (iter != remaining.end()) {
                remaining.erase(iter);
                for (auto value : remaining) {
                    Node* child_node = new Node;
                    child_node->value = value;
                    node->children.push_back(child_node);
                }
                build_tree(remaining, node->children);
                remaining.insert(iter, node->value);
            }
        }
    }
};

#endif  // INCLUDE_TREE_H_
