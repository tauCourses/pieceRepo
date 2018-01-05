#ifndef PIECEREPO_PUZZLE2DPIECE_H
#define PIECEREPO_PUZZLE2DPIECE_H

#include "AbstractPuzzleKdPiece.h"

template <int N>
class Puzzle2dPiece : public AbstractPuzzleKdPiece<N, 2>{
public:
    explicit Puzzle2dPiece(int x1, int x2, int x3, int x4);

};

Puzzle2dPiece::Puzzle2dPiece(int x1, int x2, int x3, int x4) {
    this->values.emplace_back(x1);
    this->values.emplace_back(x2);
    this->values.emplace_back(x3);
    this->values.emplace_back(x4);
    checkValues();
}


#endif //PIECEREPO_PUZZLE2DPIECE_H
