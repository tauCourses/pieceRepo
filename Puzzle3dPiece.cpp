#include "Puzzle3dPiece.h"

template <int N>
Puzzle3dPiece<N>::Puzzle3dPiece(int x1, int x2, int x3, int x4, int x5, int x6) {
    this->values.emplace_back(x1);
    this->values.emplace_back(x2);
    this->values.emplace_back(x3);
    this->values.emplace_back(x4);
    this->values.emplace_back(x5);
    this->values.emplace_back(x6);
    this->checkValues();
}