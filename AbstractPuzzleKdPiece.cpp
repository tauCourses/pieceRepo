#include "AbstractPuzzleKdPiece.h"

template <int K, unsigned int D>
int AbstractPuzzleKdPiece<K, D>::getKvalue() {
    return this->Kvalue;
}

template <int K, unsigned int D>
unsigned int AbstractPuzzleKdPiece<K, D>::getDimension() {
    return this->dimension;
}

template <int K, unsigned int D>
unsigned int AbstractPuzzleKdPiece<K, D>::getNumberOfFaces() {
    return 2 * this->dimension;
}

template <int K, unsigned int D>
void AbstractPuzzleKdPiece<K, D>::checkValues() {
    const int myKValue = this->Kvalue;
    if (std::any_of(this->values.begin(), this->values.end(), [](int i){return abs(i) > myKValue;}) )
        throw std::string("The absolut value of one values is above K");
}

template <int K, unsigned int D>
std::vector<int>::iterator AbstractPuzzleKdPiece<K, D>::begin() {
    return this->values.begin();
}

template <int K, unsigned int D>
std::vector<int>::iterator AbstractPuzzleKdPiece<K, D>::end() {
    return this->values.end();
}

/*std::ostream &AbstractPuzzleKdPiece::operator<<(std::ostream &Str, AbstractPuzzleKdPiece const &v) {
    bool first = true;
    for(int i : v.values)
    {
        if(first)
            Str << i;
        else
            Str << ", " << i;
        first = false;
    }
    return Str;
}*/
