#include <iostream>
#include <list>
//#include <limits>
//#include <list>

#include "Puzzle2dPiece.h"
#include "groupPuzzlePiecesWithRotate.h"

#define free numeric_limits<int>::min()
int main() {
    std::list<Puzzle2dPiece<5>> pieces = {{ -5  , -3  , 3  , 0  }
            ,{ 2  , -1  , 4  , 1  }
            ,{ 4  , -1  , -3  , 1  }
            ,{ -3  , 4  , 2  , -3  }
            ,{ 0  , -1  , 3  , -1  }
            ,{ -1  , 2  , 5  , 3  }
            ,{ 1  , -2  , 1  , 3  }
            ,{ -3  , -1  , -4  , 0  }
            ,{ 0  , 2  , 0  , 0  }
            ,{ -2  , -2  , 5  , -3  }
};
    auto groups = groupPuzzlePiecesWithRotate(pieces.begin(), pieces.end());
    auto &some_pieces = groups.get({free, -1, free, 1});
    for (auto& piece_ptr : some_pieces) {
        std::cout << *piece_ptr << std::endl;
    }// will print both pieces!
/*

    {
        std::list <Puzzle3dPiece<1>> pieces = {{0, 1, 1, 1, -1, -1}, {0, -1, 1, 1, 1,  1}};
    //    auto groups = groupPuzzlePiecesWithRotate(pieces.begin(), pieces.end());
     //   auto &some_pieces = groups.get({0, 1, 1, 1, 1, 1});
        for (auto piece_ptr : some_pieces) {
            std::cout << *piece_ptr << std::endl; // will print nothing!
        }
    }
    std::list <int> pieces = {1,2,3};
    auto groups = groupPuzzlePiecesWithRotate(pieces.begin(), pieces.end());*/
}
