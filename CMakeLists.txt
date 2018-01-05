cmake_minimum_required(VERSION 3.8)
project(pieceRepo)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp
        groupPuzzlePiecesWithRotate.cpp
        groupPuzzlePiecesWithRotate.h
        AbstractPuzzleKdPiece.h
        Puzzle2dPiece.h
        Puzzle3dPiece.h
        Constrain.cpp
        Constrain.h
        PuzzlePiece.h PuzzlePiece.cpp AbstractPuzzleKdPiece.cpp Puzzle3dPiece.cpp Puzzle2dPiece.cpp)
add_executable(pieceRepo ${SOURCE_FILES})