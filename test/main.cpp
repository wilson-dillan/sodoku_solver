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
    {9, 1, 3, 0, 0, 0, 2, 8, 4},
    {4, 6, 2, 0, 0, 0, 0, 0, 0},
    {5, 8, 7, 0, 0, 0, 0, 0, 6},
};

gameBoard childrenTesting{
    {1, 2, 3, 4, 5, 6, 7, 8, 9},
    {1, 2, 0, 3, 5, 6, 7, 8, 9}, // 4 as candidates
    {9, 8, 7, 6, 5, 4, 3, 2, 1},
    {1, 2, 3, 4, 5, 6, 7, 8, 9},
    {1, 2, 3, 4, 5, 6, 0, 8, 9}, // no candidates
    {9, 8, 7, 6, 5, 4, 3, 2, 1},
    {1, 2, 3, 4, 4, 6, 7, 2, 2},
    {1, 2, 3, 4, 2, 6, 0, 2, 2}, // 5, 8, 9 as candidates
    {1, 2, 3, 4, 5, 6, 7, 2, 2}
};

gameBoard childrenTestingII{
    {1, 2, 3, 4, 5, 6, 7, 8, 0}, // none
    {1, 2, 3, 4, 5, 6, 7, 8, 9},
    {9, 8, 7, 6, 5, 4, 3, 2, 1},
    {1, 2, 3, 4, 5, 6, 7, 8, 9},
    {1, 1, 3, 0, 5, 6, 1, 8, 9}, // 7, 2
    {9, 8, 7, 6, 5, 4, 3, 2, 1},
    {1, 2, 3, 4, 4, 6, 7, 8, 9},
    {1, 2, 3, 8, 2, 6, 7, 8, 9},
    {0, 2, 3, 4, 1, 1, 7, 8, 9} // 5, 6
};

gameBoard mostlyFilled{
    {8, 2, 7, 1, 5, 4, 3, 9, 6}, 
    {9, 6, 5, 3, 2, 7, 1, 4, 0},
    {3, 4, 1, 6, 8, 9, 7, 5, 2},
    {5, 9, 3, 4, 6, 8, 2, 7, 1},
    {4, 7, 2, 5, 1, 3, 6, 8, 9}, 
    {6, 1, 8, 9, 7, 2, 4, 3, 5},
    {7, 8, 6, 2, 3, 5, 9, 1, 4},
    {1, 5, 4, 7, 9, 6, 8, 2, 3},
    {2, 3, 9, 8, 4, 1, 5, 6, 7} 
};

gameBoard solvedAndFilled{
    {8, 2, 7, 1, 5, 4, 3, 9, 6}, 
    {9, 6, 5, 3, 2, 7, 1, 4, 8},
    {3, 4, 1, 6, 8, 9, 7, 5, 2},
    {5, 9, 3, 4, 6, 8, 2, 7, 1},
    {4, 7, 2, 5, 1, 3, 6, 8, 9}, 
    {6, 1, 8, 9, 7, 2, 4, 3, 5},
    {7, 8, 6, 2, 3, 5, 9, 1, 4},
    {1, 5, 4, 7, 9, 6, 8, 2, 3},
    {2, 3, 9, 8, 4, 1, 5, 6, 7} 
};

gameBoard sparslyFilled{
    {8, 0, 0, 1, 5, 0, 3, 0, 6}, 
    {0, 0, 5, 3, 0, 0, 0, 0, 0},
    {3, 4, 0, 0, 0, 9, 0, 0, 0},
    {0, 0, 3, 0, 6, 8, 2, 7, 1},
    {4, 0, 0, 0, 0, 0, 0, 0, 0}, 
    {6, 1, 8, 9, 7, 0, 4, 0, 5},
    {0, 0, 0, 0, 0, 5, 0, 1, 0},
    {1, 5, 0, 0, 0, 0, 0, 2, 3},
    {2, 3, 9, 0, 4, 1, 0, 6, 7} 
};

gameBoard hardSodoku{
    {0, 0, 6, 5, 0, 0, 0, 0, 0}, 
    {7, 0, 5, 0, 0, 2, 3, 0, 0},
    {0, 3, 0, 0, 0, 0, 0, 8, 0},
    {0, 5, 0, 0, 9, 6, 0, 7, 0},
    {1, 0, 4, 0, 0, 0, 0, 0, 8}, 
    {0, 0, 0, 8, 2, 0, 0, 0, 0},
    {0, 2, 0, 0, 0, 0, 0, 9, 0},
    {0, 0, 7, 2, 0, 0, 4, 0, 0},
    {0, 0, 0, 0, 0, 7, 5, 0, 0} 
};

}
void checkCoordinateToCell(){
    board myBoard{bII};
    solver s{make_unique<board>(myBoard)};
    IS_TRUE(s.coordinateToCell(0,0) == 1);
    IS_TRUE(s.coordinateToCell(3,3) == 5);
    IS_TRUE(s.coordinateToCell(6,3) == 6);
    IS_TRUE(s.coordinateToCell(4,5) == 5);
    IS_TRUE(s.coordinateToCell(5,8) == 8);
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


bool boardListContainsExpectedPoints(set<target> expectedPoints, vector<board> boardList);

void testChildren(){
    solver s{make_unique<board>(b)};
    board testBoard = board(childrenTesting);

    auto boardList = s.getChildren(testBoard);

    set<target> expectedPoints = { 
        make_tuple(make_tuple(2,1),4),
        make_tuple(make_tuple(6,4),0), // this should not produce an additional child
        make_tuple(make_tuple(6,7),5),
        make_tuple(make_tuple(6,7),8),
        make_tuple(make_tuple(6,7),9)
    };
    
    IS_TRUE(expectedPoints.size() - 1 == boardList.size()); // number of returned children boards must match
    IS_TRUE(boardListContainsExpectedPoints(expectedPoints,boardList));

}

void testChildrenII(){
    solver s{make_unique<board>(b)};
    board testBoard = board(childrenTestingII);

    auto boardList = s.getChildren(testBoard);

    set<target> expectedPoints = { 
        make_tuple(make_tuple(8,0),0), // this should not produce an additional child
        make_tuple(make_tuple(3,4),7),
        make_tuple(make_tuple(3,4),2),
        make_tuple(make_tuple(0,8),5),
        make_tuple(make_tuple(0,8),6)
    };

    IS_TRUE(expectedPoints.size() - 1 == boardList.size()); // number of returned children boards must match
    IS_TRUE(boardListContainsExpectedPoints(expectedPoints,boardList));
}

void isValidBoard(){
    solver s{make_unique<board>(b)};
    board testBoard = board(b);
    board testBoardII = board(bII);
    board testBoardIII = board(childrenTesting);
    board mf = board(mostlyFilled);

    IS_FALSE(s.isValidBoard(testBoard));
    IS_TRUE(s.isValidBoard(testBoardII));
    IS_FALSE(s.isValidBoard(testBoardIII));
    IS_TRUE(s.isValidBoard(mf));

    // intentionally modify the board to show that it will fail
    testBoardII.set(make_tuple<int,int>(8,8), 4);
    IS_FALSE(s.isValidBoard(testBoardII));
}

void checkIsSolvedBoard(){
    solver s{make_unique<board>(solvedAndFilled)};
    board saf{solvedAndFilled};
    IS_TRUE(s.isSolvedBoard(saf));

    saf.set(make_tuple(0,0),7);

    IS_FALSE(s.isSolvedBoard(saf));
}


void checkBFS(){
    solver s{make_unique<board>(mostlyFilled)};

    board solved = s.doBFS();
    IS_TRUE(s.isSolvedBoard(solved));
}

// checking BFS on a less filled board
void checkBFSII(){
    solver s{make_unique<board>(sparslyFilled)};

    board solved = s.doBFS();
    IS_TRUE(s.isSolvedBoard(solved));
}

int main(){
    std::cout<<"Running tests"<<endl;

    // checkCoordinateToCell();
    // checkCoordinateSimple();
    // examineGetSets();
    // checkSolverConstructor();
    // checkBoardSet();
    // checkGetNumbersInCell();
    // checkGetNumbersInCell_II();
    // checkRowAndCell();
    // testChildren();
    // testChildrenII();
    // isValidBoard();
    // checkBFS();
    // checkIsSolvedBoard();

    checkBFSII();



    std::cout<<"\n<<<<<<<<TESTS PASSED!>>>>>>>>>\n" << std::endl;
    return 0;
}

bool boardListContainsExpectedPoints(set<target> expectedPoints, vector<board> boardList){
    bool outerBool = false;
    set<target> duplicatesList = expectedPoints;// used for set removal
    for(const target& e : expectedPoints){
        bool innerBool = false;
        for(const board& b: boardList){

            point currPt = get<0>(e);
            int targetValue = get<1>(e);
            innerBool = b.get(currPt) == targetValue || innerBool;
            if(b.get(currPt) == targetValue){
                target targetToErase = make_tuple(currPt,targetValue);
                duplicatesList.erase(targetToErase);
            }
        }
        outerBool = outerBool || innerBool;
    }
    return outerBool && duplicatesList.size() == 0;
}