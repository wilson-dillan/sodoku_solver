// main.cpp

#include "../include/board.hpp"
#include "../include/solver.hpp"
#include <iostream>

// If parameter is not true, test fails
// This check function would be provided by the test framework
#define IS_TRUE(x) if(!(x)) std::cout << __FUNCTION__ << " failed on line " << __LINE__ << std::endl;
#define IS_FALSE(x) if((x)) std::cout << __FUNCTION__ << " failed on line " << __LINE__ << std::endl;

// "test" class checks my testing behavior
using namespace constants;
using namespace std;

namespace {
gameBoard b{
    {1, 2, 3, 4, 5, 6, 7, 8, 9},
    {1, 2, 3, 4, 5, 6, 7, 8, 9},
    {9, 8, 7, 6, 5, 4, 3, 2, 1},
    {1, 2, 3, 4, 5, 6, 7, 8, 9},
    {1, 2, 3, 4, 5, 6, 7, 8, 9},
    {9, 8, 7, 6, 5, 4, 3, 2, 1},
    {1, 2, 3, 4, 4, 6, 7, 8, 9},
    {1, 2, 3, 8, 2, 6, 7, 8, 9},
    {1, 2, 3, 4, 5, 6, 7, 8, 9}
};

gameBoard bII{
    {0, 0, 0, 0, 0, 0, 0, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 3, 0},
    {0, 0, 0, 0, 0, 0, 0, 4, 0},
    {0, 0, 0, 1, 2, 3, 0, 9, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 9, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 8, 3},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 5, 0},
};

}

// checks the coordinate on the board is as expected
void checkCoordinateSimple()
{
    board myBoard{b};
    IS_TRUE(myBoard[3][2] == 6);
    IS_TRUE(myBoard[4][7] == 2);
}

// check board.set()

void checkBoardSet(){
    board myBoard{bII};
    point pt{2, 5};
    myBoard.set(pt, 1000);
    IS_TRUE(myBoard[2][5] == 1000);
}

// ensures the board copied into the solver is correct
void checkSolverConstructor(){
     solver s{make_unique<board>(b)};
     IS_TRUE(s.testIfSolutionAndInitialMatch());
}

// single cell must be filled in valid
void checkOneCellIsValid(){
     solver s{make_unique<board>(bII)};
     s.populateCell(2);
     s.printSolvedBoard();

}

// check that method sets are correct
void examineGetSets(){
    
    solver s{make_unique<board>(bII)};
    set<int> candidates = s.getCandidatesFromCoordinate(7,7);
    set<int> expectedContents{2, 6, 7};
    IS_TRUE(candidates.size() == expectedContents.size());
    for(int e:candidates){
        IS_TRUE(expectedContents.find(e) != expectedContents.end());
    }

    candidates = s.getCandidatesFromCoordinate(3, 5);
    expectedContents = {4, 5, 6, 7, 8};

    IS_TRUE(candidates.size() == expectedContents.size());
    for(int e:candidates){
        IS_TRUE(expectedContents.find(e) != expectedContents.end());
    }
    
    
}
int main(){


    checkCoordinateSimple();
    examineGetSets();
    checkSolverConstructor();
    checkOneCellIsValid();
    checkBoardSet();
    
    return 0;

}
