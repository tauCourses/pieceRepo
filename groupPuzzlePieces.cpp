#include "groupPuzzlePieces.h"

const list<shared_ptr<PuzzlePiece>> groupPuzzlePieces::get(const Constrain &constrain) const {
    constrain.checkForConstants(this->K, this->D);
    auto search = constrainMap.find(constrain);
    if (search != constrainMap.end()) {
        return search->second;
    } else {
        return list<shared_ptr<PuzzlePiece>>();
    }
}
