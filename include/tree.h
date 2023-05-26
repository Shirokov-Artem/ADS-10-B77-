// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#include <vector>
#include <algorithm>

class Tree {
 public:
    Tree(std::vector<char> elements) {
        root = new Node(' ');
        std::vector<Node*> nodes;
        for (auto i : elements) {
            nodes.push_back(new Node(i));
        }
        root->buildTree(&nodes);
        root->generatePermutations(permutations, {});
    }
    std::vector<std::vector<char>> permutations;

 private:
    class Node {

     public:
        Node(char value) : value(value) {}
        void buildTree(std::vector<Node*>* nodes) {
            for (auto it = nodes->begin(); it != nodes->end();) {
                if ((*it)->value == value) {
                    children.push_back(*it);
                    it = nodes->erase(it);
                } else {
                    ++it;
                }
            }
            for (auto& child : children) {
                child->buildTree(nodes);
            }
        }
        void generatePermutations(std::vector<std::vector<char>>& permutations, std::vector<char> current) {
            current.push_back(value);
            if (children.empty()) {
                permutations.push_back(current);
            }
            for (auto& child : children) {
                child->generatePermutations(permutations, current);
            }
        }
        char value;
        std::vector<Node*> children;
    };
    Node* root;
};

#endif  // INCLUDE_TREE_H_
