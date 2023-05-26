// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include <vector>
#include <algorithm>
#include  "tree.h"

std::vector<char> getPerm(const Tree& tree, int n) {
    return tree.getPermutation(n);
}
