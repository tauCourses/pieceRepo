#ifndef PIECEREPO_CONSTRAIN_H
#define PIECEREPO_CONSTRAIN_H

#include <iostream>
#include <iterator>
#include <utility>
#include <vector>
#include <algorithm>
#include <string>
#include <stdexcept>


using namespace std;

class Constrain {
public :
    Constrain(initializer_list<int> v);

    explicit Constrain(vector<int> &v);

    struct ConstrainHasher {
        std::size_t operator()(const Constrain &c) const;
    };

    bool operator==(const Constrain &rhs) const;

    void toString(ostream &out) const;

private:
    vector<int> values;
};

inline ostream &operator<<(ostream &out, const Constrain &val) {
    val.toString(out);
    return out;
}
#endif //PIECEREPO_CONSTRAIN_H

