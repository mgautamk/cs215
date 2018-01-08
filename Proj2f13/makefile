run : P2.out
	./P2.out 

P2.out : Proj2.o Puzzle.o
	g++ -o P2.out Proj2.o Puzzle.o -g

Proj2.o : Proj2.cpp Puzzle.h
	g++ -c Proj2.cpp -g

Puzzle.o : Puzzle.cpp Puzzle.h
	g++ -c Puzzle.cpp -g

clean :
	rm -f *.o P2.out
