#ifndef PIECEREPO_GROUPPUZZLEPIECESWITHROTATE_H
#define PIECEREPO_GROUPPUZZLEPIECESWITHROTATE_H

#include <iostream>
#include <list>
#include <type_traits>

#include "AbstractPuzzleKdPiece.h"
#include "Constrain.h"

using namespace std;

class groupPuzzlePiecesWithRotate {
public:
    template<class T>
    groupPuzzlePiecesWithRotate(T start, T end) : K((*start).getKvalue()), D((*start).getDimension())
    {
        for(auto a=start; a != end ;a++)
        {
          //  *a->getAllConstrains();
        //    updateConstrains();
        }
    }

    void get(Constrain c){
        c.checkForConstants(K,D);
      //  return constrainMap(c);
    }

private:
    const int K,D;

};


#endif //PIECEREPO_GROUPPUZZLEPIECESWITHROTATE_H
