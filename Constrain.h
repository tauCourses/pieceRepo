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
    Constrain(initializer_list<int> v) : values(v) {}

    Constrain(vector<int> v) : values(v) {}

    struct ConstrainHasher {
        std::size_t operator()(const Constrain &c) const {
            size_t res = 0;
            for (auto &i: c.values)
                res = res * 31 + hash<int>()(i);
            return res;
        }
    };

    bool operator==(const Constrain &rhs) const {
        if (this->values.size() != rhs.values.size()) return false;
        for (auto l = this->values.begin(), r = rhs.values.begin();
             l != this->values.end(); ++l, ++r)
            if ((*l) != (*r)) return false;
        return true;
    }

private:
    vector<int> values;
};

//
//#include <iostream>
//#include <iterator>
//#include <vector>
//#include <algorithm>
//#include <string>
//
//using namespace std;
//
//class Constrain {
//public:
//    Constrain(initializer_list<int> v);
//
//    void checkForConstants(int K, int D) const;
//
//
//    size_t hash() const {
////        size_t res = 0;
////        for (auto &i: c.values)
////            res = res * 31 + hash<int>()(i);
////        return res;
//        return 0;
//    }
//
//private:
//    vector<int> values;
//};
//
//// custom hash can be a standalone function object:
//struct ConstrainHasher {
//    size_t operator()(const Constrain &c) const {
//        return c.hash();
//    }
//};
//
#endif //PIECEREPO_CONSTRAIN_H
