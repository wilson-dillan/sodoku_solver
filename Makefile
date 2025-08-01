target : source/main.cpp test/main.cpp
	g++ source/*.cpp  -o source/output.o  -std=c++20 -Wall
	g++ test/*.cpp source/board.cpp source/solver.cpp -o test/test.o -std=c++20 -Wall
	
	source/./output.o 
	test/./test.o
clean : 
	rm source/output.o
	rm test/test.o

