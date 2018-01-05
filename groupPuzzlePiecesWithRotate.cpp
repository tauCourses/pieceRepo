#include "groupPuzzlePiecesWithRotate.h"

const list<shared_ptr<PuzzlePiece>> groupPuzzlePiecesWithRotate::get(const Constrain &constrain) const {
    constrain.checkForConstants(K, D);
    auto search = constrainMap.find(constrain);
    if (search != constrainMap.end()) {
        return search->second;
    } else {
        return list<shared_ptr<PuzzlePiece>>();
    }
}
