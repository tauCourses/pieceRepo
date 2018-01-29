
#include "ex4headers.h"

#define free_space numeric_limits<int>::min()

using namespace std;

int main() {
    list<Puzzle2dPiece<5>> pieces = {{0, -3, 2,  0},
                                          {2,  -1, 4,  1},
                                          {1,  -2, 1,  3},
                                          {0,  0,  2,  0},
                                          {0,  2,  0,  0},
                                          {2,  0,  0,  0}};

    list<Constrain> constrains = {{free_space, 2,  0, 0},
                                  {free_space, 1, free_space, 1}};


    auto groups = groupPuzzlePieces(pieces.begin(), pieces.end());
    for (auto &constain:constrains) {
        auto &some_pieces = groups.get(constain);
        cout << "constrain: " << constain << endl;
        for (auto &piece_ptr : some_pieces) {
            std::cout << *piece_ptr << std::endl;
        }
        cout << endl;
    }

    auto groups2 = groupPuzzlePiecesWithRotate(pieces.begin(), pieces.end());
    for (auto &constain:constrains) {
        auto &some_pieces = groups2.get(constain);
        cout << "constrain: " << constain << endl;
        for (auto &piece_ptr : some_pieces) {
            std::cout << *piece_ptr << std::endl;
        }
        cout << endl;
    }
    
}
