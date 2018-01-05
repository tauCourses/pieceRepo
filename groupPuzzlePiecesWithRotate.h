#ifndef PIECEREPO_GROUPPUZZLEPIECESWITHROTATE_H
#define PIECEREPO_GROUPPUZZLEPIECESWITHROTATE_H

#include <iostream>
#include <list>
#include <type_traits>
#include <map>
#include <memory>
#include <unordered_map>

#include "AbstractPuzzleKdPiece.h"
#include "Constrain.h"

using namespace std;

class groupPuzzlePiecesWithRotate {
public:
    template<class T>
    groupPuzzlePiecesWithRotate(T start, T end) : K(start->getKvalue()), D(start->getDimension()) {
        for (auto a = start; a != end; a++) {
            addPiece(*a);
        }
    }


//    const list<unique_ptr<const PuzzlePiece>> get(Constrain &constrain) const;


private:
    const int K, D;
    //unordered_map<Constrain, int, Constrain::ConstrainHasher> constrainMap;

    template<class T>
    void addPiece(T &piece) {
        for (auto &constrain : piece.getAllConstrain())
            addPieceToConstrain(piece, constrain);
    }

    class

    template<class T>
    void addPieceToConstrain(T &piece, const Constrain &constrain) {
        vector<PuzzlePiece> a(0);
        unordered_map<Constrain, vector<PuzzlePiece>, Constrain::KeyHasher> m6 = {
        };
        m6.insert(unordered_map<Constrain, list<unique_ptr<PuzzlePiece>>, Constrain::KeyHasher>::value_type(Constrain({1, 2, 12}), a));
//        auto search = constrainMap.find(constrain);
//        if (search == constrainMap.end()) {
//            int a;
//            search = constrainMap.insert({constrain, a});
//        } else {
//
//        }
    }
};


#endif //PIECEREPO_GROUPPUZZLEPIECESWITHROTATE_H
