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
        vector<int> shifted_values(values_length);
        for (unsigned int shift = 0; shift < values_length; ++shift) {
            for (int mask = 0; mask < 1 << values_length; ++mask) {
                for (unsigned int i = 0, bit = 1; i < values_length; ++i, bit <<= 1)
                    shifted_values[i] =
                            (bit & mask) ? values[(i + shift) % values_length] : std::numeric_limits<int>::min();

                res.emplace(shifted_values);
            }
        }
        return res;
    }

private:
    const unsigned int values_length = D * 2;
    int values[D * 2] = {};
};

#endif //PIECEREPO_ABSTRACTPUZZLEKDPIECE_H
