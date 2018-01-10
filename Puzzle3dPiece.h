#ifndef PIECEREPO_PUZZLE3DPIECE_H
#define PIECEREPO_PUZZLE3DPIECE_H

#include "AbstractPuzzleKdPiece.h"

template<int N>
class Puzzle3dPiece : public AbstractPuzzleKdPiece<N, 3> {
public:
    Puzzle3dPiece(const std::initializer_list<int> &v) : AbstractPuzzleKdPiece<N, 3>::AbstractPuzzleKdPiece(v) {}

protected:
    vector<vector<int>> all_rotations(vector<int> current_constrain) override {
        vector<vector<int>> ret;
        vector<int> rotated_constrain(6);
        for (int front = 0; front < 6; ++front) {
            rotated_constrain[4] = current_constrain[front];
            rotated_constrain[5] = current_constrain[on_the_other_side[front]];
            for (int shift = 0; shift < 4; ++shift) {
                for (int i = 0; i < 4; i++)
                    rotated_constrain[i] = current_constrain[neighbors[front][(i + shift) % 4]];
                ret.emplace_back(rotated_constrain);
            }
        }
        return ret;
    }

private:
    static constexpr int neighbors[6][4] = {{5, 1, 4, 3},   //  neighbors of 0;
                                            {0, 5, 2, 4},   //  neighbors of 1;
                                            {3, 4, 1, 5},   //  neighbors of 2;
                                            {2, 5, 0, 4},   //  neighbors of 3;
                                            {0, 1, 2, 3},   //  neighbors of 4;
                                            {3, 2, 1, 0}};  //  neighbors of 5;
    static constexpr int on_the_other_side[6] = {2, 3, 0, 1, 5, 4};
};

template<int N> constexpr int Puzzle3dPiece<N>::neighbors[6][4];
template<int N> constexpr int Puzzle3dPiece<N>::on_the_other_side[6];


#endif //PIECEREPO_PUZZLE3DPIECE_H
