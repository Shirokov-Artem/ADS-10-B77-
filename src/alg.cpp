// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

int fact(int n) {
    int result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

std::vector<char> getPerm(const Tree& tree, int n, const std::vector<char>& data) {
    if (n <= 0 || n > fact(tree.getSize()))
        return {};

    std::vector<int> perm(tree.getSize());
    for (int i = 0; i < tree.getSize(); i++) {
        perm[i] = i;
    }

    std::vector<char> result(tree.getSize());
    int div = fact(tree.getSize() - 1);
    for (int i = 0; i < tree.getSize(); i++) {
        int index = n / div;
        result[i] = data[perm[index]];
        perm.erase(perm.begin() + index);
        n = n % div;
        if (i < tree.getSize() - 1) {
            div /= (tree.getSize() - 1 - i);
        }
    }

    return result;
}
