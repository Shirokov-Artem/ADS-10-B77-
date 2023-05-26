// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#include <vector>
#include <algorithm>

class Tree {
    private:
        struct Node {
            char symb;
            std::vector<Node*> children;
            Node(char ch) : symb(ch) {}
        };
        Node *root;
        void createNode(Node* node, const std::vector<char>& vec) {
            for (int i = 0; i < vec.size(); i++) {
                std::vector<char> temp = vec;
                node->children.push_back(new Node(temp[i]));
                temp.erase(temp.begin() + i);
                createNode(node->children.back(), temp);
            }
        }

    public:
        Tree(const std::vector<char>& vec) {
            root = new Node('*');
            createNode(root, vec);
        }
        ~Tree() {
            clear(root);
        }
        int getSize() const {
            return root->children.size();
        }
        char getSymb() const {
            return root->symb;
        }
        Node* getChild(int n) const {
            return root->children[n];
        }
        void clear(Node *node) {
            if (node == nullptr) return;
            for (auto child : node->children) clear(child);
            delete node;
        }
};

#endif  // INCLUDE_TREE_H_
