// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#include <vector>
#include <algorithm>

class TreeNode {
 public:
    char val;
    std::vector<TreeNode*> children;

    explicit TreeNode(char c) : val(c), children() {}
};

class Tree {
 private:
    std::vector<std::vector<char>> permutations;
    TreeNode* root;
    TreeNode* buildTreeHelper(const std::vector<char>& chars) {
        if (chars.empty()) {
            return nullptr;
        }
        TreeNode* node = new TreeNode(chars[0]);
        for (int i = 1; i < chars.size(); ++i) {
            std::vector<char> subChars = chars;
            subChars.erase(subChars.begin());

            TreeNode* child = buildTreeHelper(subChars);
            node->children.push_back(child);
        }
        return node;
    }
    void getPermutationHelper(TreeNode* node, std::vector<char>& path) {
        path.push_back(node->val);
        if (node->children.empty()) {
            permutations.push_back(path);
        } else {
            for (TreeNode* child : node->children) {
                getPermutationHelper(child, path);
            }
        }
        path.pop_back();
    }

 public:
    explicit Tree(const std::vector<char>& chars) : permutations(), root(nullptr) {
        root = buildTreeHelper(chars);
        std::vector<char> path;
        getPermutationHelper(root, path);
    }
    std::vector<char> getPermutation(int n) const {
        if (permutations.size() <= n) {
            return std::vector<char>();
        }
        return permutations[n];
    }
};

#endif  // INCLUDE_TREE_H_
