// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include <vector>
#include <algorithm>
#include  "tree.h"

std::vector<char> getPerm(const Tree& tree, int n) {
    std::vector<std::vector<char>> permutations;
    tree.generate_permutations(tree.get_root(), std::vector<char>(), permutations);
    if (n > permutations.size()) {
        return std::vector<char>();
    }
    return permutations[n - 1];
}
