cmake_minimum_required(VERSION 3.8)
project(pieceRepo)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp
        groupPuzzlePiecesWithRotate.cpp
        groupPuzzlePiecesWithRotate.h
        AbstractPuzzleKdPiece.cpp
        AbstractPuzzleKdPiece.h
        Puzzle2dPiece.cpp
        Puzzle2dPiece.h
        Puzzle3dPiece.cpp
        Puzzle3dPiece.h Constrain.cpp Constrain.h PuzzlePiece.h)
add_executable(pieceRepo ${SOURCE_FILES})