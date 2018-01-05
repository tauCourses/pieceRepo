CPP = g++-5

EXEC = ex4
CPP_COMP_FLAG = -std=c++14 -Wall -Wextra \
-Werror -pedantic-errors -DNDEBUG 

OBJS =  PuzzlePiece.o \
		Constrain.o \
		AbstractPuzzleKdPiece.o \
		Puzzle2dPiece.o \
		Puzzle3dPiece.o \
		groupPuzzlePiecesWithRotate.o \
		main.o

$(EXEC): $(OBJS)
	$(CPP) $(OBJS) -o $@

PuzzlePiece.o: PuzzlePiece.cpp
	$(CPP) $(CPP_COMP_FLAG) -c $*.cpp
Constrain.o: Constrain.cpp PuzzlePiece.h
	$(CPP) $(CPP_COMP_FLAG) -c $*.cpp
AbstractPuzzleKdPiece.o: AbstractPuzzleKdPiece.cpp Constrain.h PuzzlePiece.h
	$(CPP) $(CPP_COMP_FLAG) -c $*.cpp
Puzzle2dPiece.o: Puzzle2dPiece.cpp AbstractPuzzleKdPiece.h
	$(CPP) $(CPP_COMP_FLAG) -c $*.cpp
Puzzle3dPiece.o: Puzzle3dPiece.cpp AbstractPuzzleKdPiece.h
	$(CPP) $(CPP_COMP_FLAG) -c $*.cpp
groupPuzzlePiecesWithRotate.o: groupPuzzlePiecesWithRotate.cpp AbstractPuzzleKdPiece.h Constrain.h
	$(CPP) $(CPP_COMP_FLAG) -c $*.cpp
main.o: main.cpp Puzzle2dPiece.h Puzzle3dPiece.h groupPuzzlePiecesWithRotate.h
	$(CPP) $(CPP_COMP_FLAG) -c $*.cpp
clean:
	rm -f $(OBJS) $(EXEC)

