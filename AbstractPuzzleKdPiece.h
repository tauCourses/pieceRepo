#ifndef PIECEREPO_ABSTRACTPUZZLEKDPIECE_H
#define PIECEREPO_ABSTRACTPUZZLEKDPIECE_H

#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <string>

#include "Constrain.h"

template <int K, unsigned int D>
class AbstractPuzzleKdPiece{
private:
    int values[D*2] = {};
public:
    AbstractPuzzleKdPiece(std::initializer_list<int> v) {
        int i = 0;
        for(auto& a : v) {
            if(a < -K || a > K)
                throw std::string("bad value!");
            values[i++] = a;
        }
        if(i!=2*D)
            throw std::string("Not enough values!");
    }

    const int* begin() const {
        return values;
    }
    const int* end() const {
        return values + 2*D;
    }

    int getKvalue() const { return K; }
    unsigned int getDimension() const {return D; }
    unsigned int getNumberOfFaces() const {return 2 * D;}
    void toString(std::ostream& out) const {
        bool first = true;
        for(int i : this->values)
        {
            if(first)
                out << i;
            else
                out << ", " << i;
            first = false;
        }
    }
};

template <int K, unsigned int D>
inline std::ostream& operator<<(std::ostream& out, const AbstractPuzzleKdPiece<K,D>& val){
   val.toString(out);
    return out;
}

#endif //PIECEREPO_ABSTRACTPUZZLEKDPIECE_H
