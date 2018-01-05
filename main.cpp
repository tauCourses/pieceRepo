;#include <iostream>
#include <limits>

int main() {
    {
        list <Puzzle2dPiece<5>> pieces = {{0, 3,  2, -5}, {0, -2, 2, -5}};
        auto groups = groupPuzzlePiecesWithRotate(pieces.begin(), pieces.end());
        auto &some_pieces = groups.get({0, std::numeric_limits<int>::min(), 2, -4});
        for (auto piece_ptr : some_pieces) {
            std::cout << *piece_ptr << std::endl; // will print both pieces!
        }
    }

    {
        list <Puzzle3dPiece<1>> pieces = {{0, 1,  1, 1, -1, -1}, {0, -1, 1, 1, 1,  1}};
        auto groups = groupPuzzlePiecesWithRotate(pieces.begin(), pieces.end());
        auto &some_pieces = groups.get({0, 1, 1, 1, 1, 1});
        for (auto piece_ptr : some_pieces) {
            std::cout << *piece_ptr << std::endl; // will print nothing!
        }
    }
}
