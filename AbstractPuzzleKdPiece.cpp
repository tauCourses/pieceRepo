#include "AbstractPuzzleKdPiece.h"

int AbstractPuzzleKdPiece::getKvalue() {
    return this->Kvalue;
}

unsigned int AbstractPuzzleKdPiece::getDimension() {
    return this->dimension;
}

unsigned int AbstractPuzzleKdPiece::getNumberOfFaces() {
    return 2 * this->dimension;
}

void AbstractPuzzleKdPiece::checkValues() {
    if (std::any_of(this->values.begin(), this->values.end(), [](int i){return abs(i) > this->Kvalue;}) )
        throw std::string("The absolut value of one values is above K");
}

std::vector<int>::iterator AbstractPuzzleKdPiece::begin() {
    return this->values.begin();
}

std::vector<int>::iterator AbstractPuzzleKdPiece::end() {
    return this->values.end();
}

std::ostream &AbstractPuzzleKdPiece::operator<<(std::ostream &Str, AbstractPuzzleKdPiece const &v) {
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
}
