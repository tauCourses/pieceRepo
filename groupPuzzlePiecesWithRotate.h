#ifndef PIECEREPO_GROUPPUZZLEPIECESWITHROTATE_H
#define PIECEREPO_GROUPPUZZLEPIECESWITHROTATE_H

#include "groupPuzzlePieces.h"

class groupPuzzlePiecesWithRotate : public groupPuzzlePieces{
public:
    template<class Iterator>
    explicit groupPuzzlePiecesWithRotate(Iterator start, Iterator end) :
            groupPuzzlePieces(start,end, true) //enable rotatable
    {}

};


#endif //PIECEREPO_GROUPPUZZLEPIECESWITHROTATE_H
