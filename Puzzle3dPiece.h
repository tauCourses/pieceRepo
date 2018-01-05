#ifndef PIECEREPO_PUZZLE3DPIECE_H
#define PIECEREPO_PUZZLE3DPIECE_H

#include "AbstractPuzzleKdPiece.h"

template <int N>
class Puzzle3dPiece : public AbstractPuzzleKdPiece<N, 3>{
public:
    Puzzle3dPiece(int x1, int x2, int x3, int x4, int x5, int x6) {
        this->values.emplace_back(x1);
        this->values.emplace_back(x2);
        this->values.emplace_back(x3);
        this->values.emplace_back(x4);
        this->values.emplace_back(x5);
        this->values.emplace_back(x6);
        this->checkValues();
    }
};




#endif //PIECEREPO_PUZZLE3DPIECE_H
