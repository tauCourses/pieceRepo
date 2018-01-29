#include "ex4headers.h"

#define free_space numeric_limits<int>::min()

using namespace std;

int main() {
    list<Puzzle2dPiece<5>> Pieces2d = {{0, -3, 2,  0},
                                      {2,  -1, 4,  1},
                                      {1,  -2, 1,  3},
                                      {0,  0,  2,  0},
                                      {0,  2,  0,  0},
                                      {2,  0,  0,  0}};

    list<Constrain> constrains2d = {{free_space, 2,  0, 0},
                                  {free_space, free_space, 2, free_space}};

    list<Puzzle3dPiece<12>> Pieces3d = {{1, 5, -7, -8, 9, -12},
                                        {6, 1, 5, -3, 10,-1},
                                        {2, -3, 4, -5, 6, -9},
                                        {-11, -7, 0, -12, 9, 7},
                                        {-4, -11, -5, -11, 1, 5},
                                        {-12, -2, -8, 8, -6, 1},
                                        {-8, 10, 3, 12, 4, -11},
                                        {4, 9, 5, -3, -1, -7},
                                        {-4, 3, 5, 1, -10, 4},
                                        {-12, -3, -7, 12, 9, 7}};

    list<Constrain> constrains3d = {{ free_space  , free_space  , -7  , free_space  , 9  , free_space },
                                    { 1  , 5  , free_space  , free_space  , free_space  , free_space  }};

    cout << "2d without rotation:" << endl;
    auto groups2d = groupPuzzlePieces(Pieces2d.begin(), Pieces2d.end());
    for (auto &constain:constrains2d) {
        auto &some_pieces = groups2d.get(constain);
        cout << "constrain: " << constain << endl;
        for (auto &piece_ptr : some_pieces) {
            std::cout << "\t" << *piece_ptr << std::endl;
        }
    }

    cout << endl << "2d with rotation:" << endl;
    auto groups2dRotation = groupPuzzlePiecesWithRotate(Pieces2d.begin(), Pieces2d.end());
    for (auto &constain:constrains2d) {
        auto &some_pieces = groups2dRotation.get(constain);
        cout << "constrain: " << constain << endl;
        for (auto &piece_ptr : some_pieces) {
            std::cout << "\t" << *piece_ptr << std::endl;
        }
    }
    cout << endl << "3d without rotation:" << endl;
    auto groups3d = groupPuzzlePieces(Pieces3d.begin(), Pieces3d.end());
    for (auto &constain:constrains3d) {
        auto &some_pieces = groups3d.get(constain);
        cout << "constrain: " << constain << endl;
        for (auto &piece_ptr : some_pieces) {
            std::cout << "\t" << *piece_ptr << std::endl;
        }
    }

    cout << endl << "3d with rotation:" << endl;
    auto groups3dRotation = groupPuzzlePiecesWithRotate(Pieces3d.begin(), Pieces3d.end());
    for (auto &constain:constrains3d) {
        auto &some_pieces = groups3dRotation.get(constain);
        cout << "constrain: " << constain << endl;
        for (auto &piece_ptr : some_pieces) {
            std::cout << "\t" << *piece_ptr << std::endl;
        }
    }
    
}
