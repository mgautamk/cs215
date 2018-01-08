L06.out : WordData.o test2.o
	g++ -o L06.out WordData.o test2.o

WordData.o : WordData.h WordData.cpp
	g++ -g -c WordData.cpp

test2.o : WordData.h test2.cpp
	g++ -g -c test2.cpp

clean :
	rm *.o L06.out
