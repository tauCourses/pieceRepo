#ifndef PIECEREPO_ABSTRACTPUZZLEKDPIECE_H
#define PIECEREPO_ABSTRACTPUZZLEKDPIECE_H

#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <string>

template <int K, unsigned int D>
class AbstractPuzzleKdPiece{
public:
    std::vector<int>::iterator begin();
    std::vector<int>::iterator end();

    std::ostream & operator<<(std::ostream & Str, AbstractPuzzleKdPiece const & v);

    int getKvalue();
    unsigned int getDimension();
    unsigned int getNumberOfFaces();
protected:
    void checkValues(); //throw exception if wrong value found;
    std::vector<int> values;
    int Kvalue = K;
    unsigned int dimension = D;
};



#endif //PIECEREPO_ABSTRACTPUZZLEKDPIECE_H
