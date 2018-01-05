#ifndef PIECEREPO_PUZZLE2DPIECE_H
#define PIECEREPO_PUZZLE2DPIECE_H

#include "AbstractPuzzleKdPiece.h"

template <int N>
class Puzzle2dPiece : public AbstractPuzzleKdPiece<N, 2>{
public:
    Puzzle2dPiece(int x1, int x2, int x3, int x4);
};


#endif //PIECEREPO_PUZZLE2DPIECE_H
