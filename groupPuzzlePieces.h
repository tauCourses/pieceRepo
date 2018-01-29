#ifndef PIECEREPO_GROUPPUZZLEPIECES_H
#define PIECEREPO_GROUPPUZZLEPIECES_H

#include <list>
#include <memory>
#include <unordered_map>

#include "AbstractPuzzleKdPiece.h"
#include "Constrain.h"

using namespace std;

class groupPuzzlePieces {
public:
    template<class Iterator>
    explicit groupPuzzlePieces(Iterator start, Iterator end, bool rotatable=false) :
            K(start->getKvalue()), D(start->getDimension()), rotatable(rotatable) {
        typedef typename std::iterator_traits<Iterator>::value_type Result;
        while(start != end)
            this->addPiece(make_shared<Result>(std::move(*start++)));

    }

    const list<shared_ptr<PuzzlePiece>> get(const Constrain &constrain) const;

protected:
    const int K;
    const unsigned int D;
    bool rotatable = false;
    unordered_map<Constrain, list<shared_ptr<PuzzlePiece>>, Constrain::ConstrainHasher> constrainMap;

    template<class T>
    void addPiece(shared_ptr<T> piece) {
        for (auto &constrain : piece->getAllConstrains(this->rotatable))
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


#endif //PIECEREPO_GROUPPUZZLEPIECES_H
