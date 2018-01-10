#include "Constrain.h"

Constrain::Constrain(std::initializer_list<int> v) : values(v) {}

Constrain::Constrain(vector<int> &v) : values(v) {}

bool Constrain::operator==(const Constrain &rhs) const {
    if (this->values.size() != rhs.values.size()) return false;
    for (auto l = this->values.begin(), r = rhs.values.begin();
         l != this->values.end(); ++l, ++r)
        if ((*l) != (*r)) return false;
    return true;
}

void Constrain::toString(ostream &out) const {
    for(auto i:this->values)
        out << i << " ";
}

std::size_t Constrain::ConstrainHasher::operator()(const Constrain &c) const {
        size_t res = 0;
        for (auto &i: c.values)
            res = res * 31 + hash<int>()(i);
        return res;
}