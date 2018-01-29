CPP = g++-5

EXEC = ex4
CPP_COMP_FLAG = -std=c++14 -Wall -Wextra \
-Werror -pedantic-errors -DNDEBUG 

OBJS =  Constrain.o \
		PuzzlePiece.o \
		AbstractPuzzleKdPiece.o \
		Puzzle2dPiece.o \
		Puzzle3dPiece.o \
		groupPuzzlePieces.o \
		groupPuzzlePiecesWithRotate.o \
		main.o

$(EXEC): $(OBJS)
	$(CPP) $(OBJS) -o $@


Constrain.o: Constrain.cpp 
	$(CPP) $(CPP_COMP_FLAG) -c $*.cpp
PuzzlePiece.o: PuzzlePiece.cpp Constrain.h
	$(CPP) $(CPP_COMP_FLAG) -c $*.cpp
AbstractPuzzleKdPiece.o: AbstractPuzzleKdPiece.cpp Constrain.h PuzzlePiece.h
	$(CPP) $(CPP_COMP_FLAG) -c $*.cpp
Puzzle2dPiece.o: Puzzle2dPiece.cpp AbstractPuzzleKdPiece.h
	$(CPP) $(CPP_COMP_FLAG) -c $*.cpp
Puzzle3dPiece.o: Puzzle3dPiece.cpp AbstractPuzzleKdPiece.h
	$(CPP) $(CPP_COMP_FLAG) -c $*.cpp
groupPuzzlePieces.o: groupPuzzlePieces.cpp AbstractPuzzleKdPiece.h Constrain.h
	$(CPP) $(CPP_COMP_FLAG) -c $*.cpp
groupPuzzlePiecesWithRotate.o: groupPuzzlePiecesWithRotate.cpp groupPuzzlePieces.h
	$(CPP) $(CPP_COMP_FLAG) -c $*.cpp
main.o: main.cpp 
	$(CPP) $(CPP_COMP_FLAG) -c $*.cpp
clean:
	rm -f $(OBJS) $(EXEC)

