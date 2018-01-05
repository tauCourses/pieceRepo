#ifndef PIECEREPO_PUZZLE3DPIECE_H
#define PIECEREPO_PUZZLE3DPIECE_H

#include "AbstractPuzzleKdPiece.h"

template <int N>
class Puzzle3dPiece : public AbstractPuzzleKdPiece<N, 3>{
public:
    Puzzle3dPiece(const std::initializer_list<int> &v) : AbstractPuzzleKdPiece<N,3>::AbstractPuzzleKdPiece(v) {}
};

#endif //PIECEREPO_PUZZLE3DPIECE_H
