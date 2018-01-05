//#include "Constrain.h"
//
//Constrain::Constrain(std::initializer_list<int> v) : values(v) {}
//
//void Constrain::checkForConstants(int K, int D) const{
//    if (values.size() != 2 * D) {
//        cerr << "Constrain does not fit pieces dimensions";
//        throw std::runtime_error("Constrain does not fit pieces dimensions");
//    }
//    for (auto &v : values)
//        if (v != std::numeric_limits<int>::min() && (v < -K || v > K)) {
//            cerr << "Constrain does not fit pieces type";
//            throw std::runtime_error("Constrain does not fit pieces type");
//        }
//}