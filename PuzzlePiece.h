#ifndef PIECEREPO_PUZZLEPIECE_H
#define PIECEREPO_PUZZLEPIECE_H

#include <unordered_set>

#include "Constrain.h"

using namespace std;

class PuzzlePiece {
public:
    virtual const int *begin() const =0;

    virtual const int *end() const =0;

    virtual void toString(ostream &out) const =0;

    virtual unordered_set<Constrain, Constrain::ConstrainHasher> getAllConstrains(bool rotatable = false) =0;
};

inline ostream &operator<<(ostream &out, const PuzzlePiece &val) {
    val.toString(out);
    return out;
}

#endif //PIECEREPO_PUZZLEPIECE_H
