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
    groupPuzzlePiecesWithRotate(std::_List_iterator<T> start, std::_List_iterator<T> end) : K(start->getKvalue()),
                                                                                            D(start->getDimension()) {
        for (auto a = start; a != end; a++) {
            addPiece(shared_ptr<PuzzlePiece>(new T(*a)));
        }
    }

    const list<shared_ptr<PuzzlePiece>> get(const Constrain &constrain) const;

private:
    const int K, D;
    unordered_map<Constrain, list<shared_ptr<PuzzlePiece>>, Constrain::ConstrainHasher> constrainMap;

    template<class T>
    void addPiece(shared_ptr<T> piece) {
        for (auto &constrain : piece->getAllConstrain())
            addPieceToConstrain(piece, constrain);
    }

    template<class T>
    void addPieceToConstrain(shared_ptr<T> piece, const Constrain &constrain) {
        auto search = constrainMap.find(constrain);
        if (search == constrainMap.end())
            search = constrainMap.insert({constrain, list<shared_ptr<PuzzlePiece>>()}).first;
        search->second.push_back(piece);
    }
};


#endif //PIECEREPO_GROUPPUZZLEPIECESWITHROTATE_H
