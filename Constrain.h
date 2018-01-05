#ifndef PIECEREPO_CONSTRAIN_H
#define PIECEREPO_CONSTRAIN_H

#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Constrain {
public:
    Constrain(initializer_list<int> v);

    void checkForConstants(int K, int D);

//    bool operator()( Constrain const& lhs, Constrain const& rhs ) const;

private:
    vector<int> values;
};


#endif //PIECEREPO_CONSTRAIN_H
