// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#include <vector>
#include <algorithm>

class Tree {
 private:
    std::vector<char> data;
    int size;

 public:
    explicit Tree(const std::vector<char>& vec) : data(vec), size(vec.size()) {}

    int getSize() const {
        return size;
    }

    char getSymb() const {
        return '*';
    }

    char operator[](int n) const {
        return data[n];
    }
};

#endif  // INCLUDE_TREE_H_
