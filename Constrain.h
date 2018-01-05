#ifndef PIECEREPO_CONSTRAIN_H
#define PIECEREPO_CONSTRAIN_H

#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Constrain {
public :
    Constrain(initializer_list<int> v);

    Constrain(vector<int> &v);

    struct ConstrainHasher {
        std::size_t operator()(const Constrain &c) const {
            size_t res = 0;
            for (auto &i: c.values)
                res = res * 31 + hash<int>()(i);
            return res;
        }
    };

    void checkForConstants(int K, int D) const;

    bool operator==(const Constrain &rhs) const;

private:
    vector<int> values;
};

#endif //PIECEREPO_CONSTRAIN_H
