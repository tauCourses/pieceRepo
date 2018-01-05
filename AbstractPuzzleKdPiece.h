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
    std::vector<int>::iterator begin() {
        return this->values.begin();
    }
    std::vector<int>::iterator end()  {
        return this->values.end();
    }

    int getKvalue() const { return this->Kvalue; }
    unsigned int getDimension() const {return this->dimension; }
    unsigned int getNumberOfFaces() const {return 2 * this->dimension;}
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

protected:
    void checkValues() { //throw exception if wrong value found;
        if (std::any_of(this->values.begin(), this->values.end(), [](int i){return abs(i) > K;}) )
            throw std::string("The absolut value of one values is above K");
    }
    std::vector<int> values;
    int Kvalue = K;
    unsigned int dimension = D;
};

template <int K, unsigned int D>
inline std::ostream& operator<<(std::ostream& out, const AbstractPuzzleKdPiece<K,D>& val){
   val.toString(out);
    out << val.getDimension();
    return out;
}

#endif //PIECEREPO_ABSTRACTPUZZLEKDPIECE_H
