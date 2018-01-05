#include "AbstractPuzzleKdPiece.h"

int AbstractPuzzleKdPiece::getMaximumNumber() {
    return this->maximumNumber;
}

unsigned int AbstractPuzzleKdPiece::getDimension() {
    return this->dimension;
}

unsigned int AbstractPuzzleKdPiece::getNumberOfFaces() {
    return 2 * this->dimension;
}
