#ifndef PIECEREPO_ABSTRACTPUZZLEKDPIECE_H
#define PIECEREPO_ABSTRACTPUZZLEKDPIECE_H

#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>

#include "Constrain.h"
#include "PuzzlePiece.h"

template<int K, unsigned int D>
class AbstractPuzzleKdPiece : public PuzzlePiece {
public:
    AbstractPuzzleKdPiece(std::initializer_list<int> v) {
        if (v.size() != values_length) throw std::runtime_error("Not enough values!");
        unsigned int i = 0;
        for (auto &a : v) {
            if (a < -K || a > K)
                throw std::runtime_error("bad value!");
            values[i++] = a;
        }
    }

    const int *begin() const override {
        return values;
    }

    const int *end() const override {
        return values + 2 * D;
    }

    int getKvalue() const { return K; }

    unsigned int getDimension() const { return D; }

    unsigned int getNumberOfFaces() const { return 2 * D; }

    void toString(std::ostream &out) const override {
        bool first = true;
        for (int i : this->values) {
            if (first)
                out << i;
            else
                out << ", " << i;
            first = false;
        }
    }

    unordered_set<Constrain, Constrain::ConstrainHasher> getAllConstrain() override {
        unordered_set<Constrain, Constrain::ConstrainHasher> res;
        vector<int> current_constrain(this->values_length);
        for (int mask = 0; mask < 1 << this->values_length; ++mask) {
            for (unsigned int i = 0, bit = 1; i < this->values_length; ++i, bit <<= 1)
                current_constrain[i] = (bit & mask) ? this->values[i] : std::numeric_limits<int>::min();
            for (auto &constrain: all_rotations(current_constrain))
                res.emplace(constrain);
        }
        return res;
    }

protected:
    virtual vector<vector<int>> all_rotations(vector<int> current_constrain) = 0;

    const unsigned int values_length = D * 2;
    int values[D * 2] = {};
};

#endif //PIECEREPO_ABSTRACTPUZZLEKDPIECE_H
