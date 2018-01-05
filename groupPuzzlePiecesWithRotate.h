#ifndef PIECEREPO_GROUPPUZZLEPIECESWITHROTATE_H
#define PIECEREPO_GROUPPUZZLEPIECESWITHROTATE_H

#include <list>
#include <type_traits>

#include "AbstractPuzzleKdPiece.h"

template<class T>
class groupPuzzlePiecesWithRotate {
public:
    groupPuzzlePiecesWithRotate(std::_List_iterator <T> start, std::_List_iterator <T> end) :
        l(std::list<T>(start,end)){
    }

    std::list<T> & get(){
        //if()
        //    throw std::string("WTF");
        return this->l;
    }

private:
    std::list<T> l;
};


#endif //PIECEREPO_GROUPPUZZLEPIECESWITHROTATE_H
