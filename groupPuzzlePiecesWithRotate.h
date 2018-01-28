#ifndef PIECEREPO_GROUPPUZZLEPIECESWITHROTATE_H
#define PIECEREPO_GROUPPUZZLEPIECESWITHROTATE_H

#include "groupPuzzlePieces.h"

class groupPuzzlePiecesWithRotate : public groupPuzzlePieces{
public:
    template<class T> explicit groupPuzzlePiecesWithRotate(std::_List_iterator<T> start, std::_List_iterator<T> end)
            : groupPuzzlePieces(start,end, true) //enable rotatable
    {};
};


#endif //PIECEREPO_GROUPPUZZLEPIECESWITHROTATE_H
