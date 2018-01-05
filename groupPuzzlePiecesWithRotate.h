#ifndef PIECEREPO_GROUPPUZZLEPIECESWITHROTATE_H
#define PIECEREPO_GROUPPUZZLEPIECESWITHROTATE_H

#include <list>
#include <type_traits>

#include "AbstractPuzzleKdPiece.h"

template<class T>
class groupPuzzlePiecesWithRotate {
public:
    static_assert(std::is_base_of<AbstractPuzzleKdPiece, T>::value, "T must be a descendant of AbstractPuzzleKdPiece");
    groupPuzzlePiecesWithRotate(std::_List_iterator <T> iterator, std::_List_iterator <T> list_iterator);

    std::list<AbstractPuzzleKdPiece> & get(T t);
};


#endif //PIECEREPO_GROUPPUZZLEPIECESWITHROTATE_H
