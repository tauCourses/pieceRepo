#ifndef PIECEREPO_PUZZLE2DPIECE_H
#define PIECEREPO_PUZZLE2DPIECE_H

#include "AbstractPuzzleKdPiece.h"

template<int N>
class Puzzle2dPiece : public AbstractPuzzleKdPiece<N, 2> {
public:
    Puzzle2dPiece(const std::initializer_list<int> &v) : AbstractPuzzleKdPiece<N, 2>::AbstractPuzzleKdPiece(v) {}
protected:
    vector<vector<int>> all_rotations(vector<int> current_constrain) override {
        vector<vector<int>> ret;
        vector<int> rotated_constrain(4);
        for (int shift = 0; shift < 4; ++shift) {
            for (int i = 0; i < 4; i++)
                rotated_constrain[i] = current_constrain[(i + shift) % 4];
            ret.emplace_back(rotated_constrain);
        }
        return ret;
    }
};

#endif //PIECEREPO_PUZZLE2DPIECE_H
