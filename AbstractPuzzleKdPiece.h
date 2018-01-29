#ifndef PIECEREPO_ABSTRACTPUZZLEKDPIECE_H
#define PIECEREPO_ABSTRACTPUZZLEKDPIECE_H

#include "Constrain.h"
#include "PuzzlePiece.h"

template<int K, unsigned int D>
class AbstractPuzzleKdPiece : public PuzzlePiece {
public:
    AbstractPuzzleKdPiece(std::initializer_list<int> v) {
        if (v.size() != values_length)
            throw std::runtime_error(string("Excepted %d values but got %d",values_length,v.size()));
        unsigned int i = 0;
        for (auto& a : v) {
            if (a < -K || a > K)
                throw std::runtime_error(string("bad value! %d is out of range",a));
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

    unordered_set<Constrain, Constrain::ConstrainHasher> getAllConstrains(bool rotatable = false) override {
        unordered_set<Constrain, Constrain::ConstrainHasher> res;
        vector<int> current_constrain(this->values_length);
        for (int mask = 0; mask < 1 << this->values_length; ++mask) { //for every mask
            for (unsigned int i = 0, bit = 1; i < this->values_length; ++i, bit <<= 1) //create constrain
                current_constrain[i] = (bit & mask) ? this->values[i] : std::numeric_limits<int>::min();
            if(rotatable)
                for (auto &constrain: all_rotations(current_constrain))
                    res.emplace(constrain);
            else
                res.emplace(current_constrain);
        }

        return res;
    }

protected:
    virtual vector<vector<int>> all_rotations(vector<int> current_constrain) = 0;

    const unsigned int values_length = D * 2;
    int values[D * 2] = {};
};

#endif //PIECEREPO_ABSTRACTPUZZLEKDPIECE_H
