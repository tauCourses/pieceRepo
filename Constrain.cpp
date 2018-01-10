#include "Constrain.h"

Constrain::Constrain(std::initializer_list<int> v) : values(v) {}

Constrain::Constrain(vector<int> &v) : values(v) {}


void Constrain::checkForConstants(int K, unsigned int D) const {
    if (this->values.size() != 2 * D) {
        cerr << "Constrain does not fit pieces dimensions";
        throw std::runtime_error("Constrain does not fit pieces dimensions");
    }
    for (auto &v : values)
        if (v != std::numeric_limits<int>::min() && (v < -K || v > K)) {
            cerr << "Constrain does not fit pieces type";
            throw std::runtime_error("Constrain does not fit pieces values range");
        }
}

bool Constrain::operator==(const Constrain &rhs) const {
    if (this->values.size() != rhs.values.size()) return false;
    for (auto l = this->values.begin(), r = rhs.values.begin();
         l != this->values.end(); ++l, ++r)
        if ((*l) != (*r)) return false;
    return true;
}

void Constrain::toString(ostream &out) const {
    for(auto i:this->values) {
        if(i == numeric_limits<int>::min())
            out << "free ";
        else
            out << i << " ";
    }
}

std::size_t Constrain::ConstrainHasher::operator()(const Constrain &c) const {
        size_t res = 0;
        for (auto &i: c.values)
            res = res * 31 + hash<int>()(i);
        return res;
}