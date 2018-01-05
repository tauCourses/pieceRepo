    #ifndef PIECEREPO_PUZZLE2DPIECE_H
#define PIECEREPO_PUZZLE2DPIECE_H

#include "AbstractPuzzleKdPiece.h"

template <int N>
class Puzzle2dPiece : public AbstractPuzzleKdPiece<N, 2>{
public:
    Puzzle2dPiece(const std::initializer_list<int> &v) : AbstractPuzzleKdPiece<N,2>::AbstractPuzzleKdPiece(v) {}
};

#endif //PIECEREPO_PUZZLE2DPIECE_H
