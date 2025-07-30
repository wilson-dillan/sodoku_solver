

target : source/main.cpp test/main.cpp
	g++ source/*.cpp  -o source/output.o  -std=c++17 -Wall
	g++ test/*.cpp source/board.cpp source/solver.cpp -o test/test.o -std=c++17 -Wall
	

	source/./output.o # running sources

	test/./test.o # running tests

