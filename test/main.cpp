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
    {1, 2, 3, 8, 55, 6, 7, 8, 9},
    {1, 2, 3, 4, 5, 6, 7, 8, 9}
};
board myBoard{b};

}

// checks the coordinate on the board is as expected
void checkCoordinateSimple()
{
    IS_TRUE(myBoard[3][2] == 6);
    IS_TRUE(myBoard[4][7] == 55);
}


// check that method sets are correct
void examineGetSets(){
    
    solver s{make_unique<board>(b)};
    setBundlePtr bundle = s.getSetsFromRowColCell(3,6);
    auto& col  = (*bundle.get())[0];
    auto& row  = (*bundle.get())[1];
    auto& cell  = (*bundle.get())[2];

    
    
    vector<int> colContents{1, 2, 3, 5, 7, 9};
    vector<int> rowContents{5};
    vector<int> cellContents{1, 2, 3, 7, 9};
    IS_TRUE(col.size() == 6);
    IS_TRUE(row.size() == 1);
    IS_TRUE(cell.size() == 5);

    for(int e: colContents){
        IS_TRUE(col.find(e) != col.end());
    }
    for(int e: rowContents){
        IS_TRUE(row.find(e) != row.end());
    }
    for(int e: cellContents){
        IS_TRUE(cell.find(e) != cell.end());
    }
    
}
int main(){


    checkCoordinateSimple();
    examineGetSets();
    cout<<"Test Functions Have Passed" << endl;
    return 0;

}
