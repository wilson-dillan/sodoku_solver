// main.cpp

#include "../include/board.hpp"
#include "../include/solver.hpp"
#include <iostream>
#include <cassert>

// If parameter is not true, test fails
// This check function would be provided by the test framework
#define IS_TRUE(x) if(!(x)) std::cout <<"FAILURE: "<< __FUNCTION__ << " FAILED on line " << __LINE__ << std::endl;
#define IS_FALSE(x) if((x)) std::cout << "FAILURE: "<<__FUNCTION__ << " FAILED on line " << __LINE__ << std::endl;

// "test" class checks my testing behavior
using namespace constants;
using namespace std;

namespace {
    /*                       CELL NUMBERS
    ---------------------------------------------------------
    |                   |                   |               |
    |       1           |       2           |       3       |
    |                   |                   |               |
    |                   |                   |               |
    --------------------------------------------------------|
    |                   |                   |               |
    |       4           |       5           |       6       |
    |                   |                   |               |
    |                   |                   |               |
    --------------------------------------------------------|
    |                   |                   |               |
    |       7           |       8           |       9       |
    |                   |                   |               |
    |                   |                   |               |
    ---------------------------------------------------------
*/


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
    {9, 1, 3, 0, 0, 0, 1, 8, 3},
    {4, 6, 2, 0, 0, 0, 0, 0, 0},
    {5, 8, 7, 0, 0, 0, 0, 0, 6},
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



// check that method sets are correct
void examineGetSets(){
    
    solver s{make_unique<board>(bII)};
    set<int> candidates = s.getCandidatesFromCoordinate(7,7);
    set<int> expectedContents{5,7};
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

void checkGetNumbersInCell(){
    solver s{make_unique<board>(bII)};
    const board& boardRef = board(bII);

    set<int> actualVals = s.getNumbersInCell(boardRef, 3);

    set<int> expectedVals{1, 3, 4};

    IS_TRUE(expectedVals.size() == actualVals.size());

    for(int e:expectedVals){
        IS_TRUE(actualVals.find(e) != actualVals.end());
    }

}

// checks that the value numbers are returned for each cell
void checkGetNumbersInCell_II(){
    solver s{make_unique<board>(bII)};
    const board& boardRef = board(bII);
    
    set<int> actualVals = s.getNumbersInCell(boardRef,7);

    set<int> expectedVals{1,2,3,4,5,6,7,8,9};

    IS_TRUE(expectedVals.size() == actualVals.size());

    for(int e:expectedVals){
        IS_TRUE(actualVals.find(e) != actualVals.end());
    }

}

void checkRowAndCell(){
    solver s{make_unique<board>(bII)};
    const board& boardRef = board(bII);

    IS_TRUE(s.checkTargetNotInCol(boardRef,3,2));
    IS_TRUE(s.checkTargetNotInCol(boardRef,7,6));
    IS_TRUE(s.checkTargetNotInCol(boardRef,8,5));
    IS_TRUE(s.checkTargetNotInCol(boardRef,8,7));
    IS_TRUE(s.checkTargetNotInRow(boardRef,4,4));


    IS_FALSE(s.checkTargetNotInCol(boardRef,3,1));
    IS_FALSE(s.checkTargetNotInRow(boardRef,6,9));
    IS_FALSE(s.checkTargetNotInRow(boardRef,7,4));
}

void testChildren(){
    solver s{make_unique<board>(bII)};
    board b = board(bII);

    s.getChildren(b);

}

int main(){
    std::cout<<"Running tests"<<endl;

    checkCoordinateSimple();
    examineGetSets();
    checkSolverConstructor();
    checkBoardSet();
    checkGetNumbersInCell();
    checkGetNumbersInCell_II();
    checkRowAndCell();
    testChildren();

    std::cout<<"\n<<<<<<<<TESTS PASSED!>>>>>>>>>\n" << std::endl;
    return 0;

}
