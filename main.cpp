#include <iostream>
#include <list>

#include "Puzzle2dPiece.h"
#include "Puzzle3dPiece.h"
#include "groupPuzzlePiecesWithRotate.h"

#define free_space numeric_limits<int>::min()

int main() {
    std::list<Puzzle2dPiece<5>> pieces = {{0, -3, 2,  0},
                                          {2,  -1, 4,  1},
                                          {4,  -1, -3, 1},
                                          {-3, 4,  2,  -3},
                                          {0,  -1, 3,  -1},
                                          {-1, 2,  5,  3},
                                          {1,  -2, 1,  3},
                                          {0,  0,  2,  0},
                                          {0,  2,  0,  0},
                                          {2,  0,  0,  0}};

    std::list<Constrain> constrains = {{free_space, 2,  0, 0},
                                       {1,          -2, 1, 3},
                                       {free_space, free_space, free_space, free_space}};


    auto groups = groupPuzzlePiecesWithRotate(pieces.begin(), pieces.end());
    for (auto &constain:constrains) {
        auto &some_pieces = groups.get(constain);
        cout << "constrain: " << constain << endl;
        for (auto &piece_ptr : some_pieces) {
            std::cout << *piece_ptr << std::endl;
        }
        cout << endl;
    }
    
    std::list<Puzzle3dPiece<1>> pieces2 = {{0, 1,  1, 1, -1, -1},
                                           {0, -1, 1, 1, 1,  1}};
    auto groups2 = groupPuzzlePiecesWithRotate(pieces2.begin(), pieces2.end());
    cout << "constrain: 3d" << endl;
    auto &some_pieces2 = groups2.get({-1, 1, 1, 0, 1, 1});
    for (auto &piece_ptr : some_pieces2) {
        std::cout << *piece_ptr << std::endl; // will print nothing!
    }
    
}
