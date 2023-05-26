// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

int fact(int n) {
    if (n <= 1) return 1;
    return fact(n-1) * n;
}

std::vector<char> getPerm(const Tree& tree, int n) {
    std::vector<char> result;
    getPerm(tree, n, result);
    return result;
}

void getPerm(const Tree& tree, int n, std::vector<char>& result) {
    if (tree.getSize() == 0 || n > fact(tree.getSize())) return;

    if (tree.getSymb() == '*') n--;

    int temp = fact(tree.getSize()-1);
    result.push_back(tree.getChild(n/temp)->symb);
    getPerm(Tree(tree.getChild(n/temp)->children), n%temp, result);
}
