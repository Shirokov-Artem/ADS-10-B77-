// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#include <vector>
#include <algorithm>

class Tree {
 private:
    struct Node {
        char value;
        std::vector<Node*> children;
        Node(char val) : value(val) {}
        ~Node() {
            for (auto child : children) {
                delete child;
            }
        }
    };

    std::vector<char> elements;
    std::vector<std::vector<char>> permutations;
    Node* root;

    void fillNode(Node* node, std::vector<char> values) {
        values.erase(std::remove(values.begin(), values.end(),
                                 node->value), values.end());
        for (auto value : values) {
            node->children.push_back(new Node(value));
        }
        for (auto child : node->children) {
            fillNode(child, values);
        }
    }

    void generatePermutations(Node* node, std::vector<char> permutation) {
        if (node->children.empty()) {
            permutation.push_back(node->value);
            permutations.push_back(permutation);
            permutation.pop_back();
        }
        else {
            permutation.push_back(node->value);
            for (auto child : node->children) {
                generatePermutations(child, permutation);
            }
            permutation.pop_back();
        }
    }

 public:
    Tree(const std::vector<char>& input) : elements(input), root(new Node(' ')) {
        for (auto value : elements) {
            root->children.push_back(new Node(value));
        }
        for (auto child : root->children) {
            fillNode(child, elements);
            generatePermutations(child, std::vector<char>());
        }
    }

    ~Tree() {
        delete root;
    }

    friend std::vector<char> getPerm(const Tree& tree, int n);
};


#endif  // INCLUDE_TREE_H_
