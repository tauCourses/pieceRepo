#ifndef PIECEREPO_ABSTRACTPUZZLEKDPIECE_H
#define PIECEREPO_ABSTRACTPUZZLEKDPIECE_H

#include <iostream>
#include <iterator>
#include <vector>

template <int K, unsigned int D>
class AbstractPuzzleKdPiece{
public:
    virtual std::iterator begin() = 0;
    virtual std::iterator end() = 0;

    std::ostream & operator<<(std::ostream & Str, AbstractPuzzleKdPiece const & v) = 0;

    int getMaximumNumber();
    unsigned int getDimension();
    unsigned int getNumberOfFaces();
protected:
    std::vector<int> values;
    int maximumNumber = K;
    unsigned int dimension = D;
};



#endif //PIECEREPO_ABSTRACTPUZZLEKDPIECE_H
