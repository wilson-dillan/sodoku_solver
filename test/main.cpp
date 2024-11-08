// main.cpp

#include "../include/board.hpp"
#include "../include/solver.hpp"
#include <iostream>

// If parameter is not true, test fails
// This check function would be provided by the test framework
#define IS_TRUE(x) { !(x) ? std::cout << __FUNCTION__ << " failed on line " << __LINE__ << std::endl : std::cout<< __FUNCTION__ << " PASSED" << endl; }

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
    {1, 2, 3, 4, 5, 6, 7, 8, 9},
    {1, 2, 3, 4, 55, 6, 7, 8, 9},
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

int main(){


    checkCoordinateSimple();
    cout<<"Test Functions Have Passed" << endl;
    return 0;

}
