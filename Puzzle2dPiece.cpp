#include "Puzzle2dPiece.h"

template <int N>
Puzzle2dPiece<N>::Puzzle2dPiece(int x1, int x2, int x3, int x4) {
    this->values.emplace_back(x1);
    this->values.emplace_back(x2);
    this->values.emplace_back(x3);
    this->values.emplace_back(x4);
    this->checkValues();
}