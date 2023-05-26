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
    tree.generate_permutations(tree.get_root(), {}, permutations);
    if (n > static_cast<int>(permutations.size())) {
        return {};
    }
    return permutations[n - 1];
}
