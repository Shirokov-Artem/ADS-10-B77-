// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

std::vector<char> getPerm(const Tree& tree, int n) {
    if (n <= 0 || n > tree.permutations.size()) {
        return std::vector<char>();
        // возвращаем пустой вектор в случае, если номер не корректный
    }
    return tree.permutations[n - 1];
    // возвращаем перестановку с соответствующим номером
}
