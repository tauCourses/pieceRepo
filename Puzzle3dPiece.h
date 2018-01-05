#ifndef PIECEREPO_PUZZLE3DPIECE_H
#define PIECEREPO_PUZZLE3DPIECE_H

#include "AbstractPuzzleKdPiece.h"

template <int N>
class Puzzle3dPiece : public AbstractPuzzleKdPiece<N, 3>{
public:
    explicit Puzzle3dPiece(int x1, int x2, int x3, int x4, int x5, int x6);

};


#endif //PIECEREPO_PUZZLE3DPIECE_H
