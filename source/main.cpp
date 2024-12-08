// main.cpp

#include <iostream>
#include "../include/board.hpp"
#include "../include/solver.hpp"

using namespace constants; 
using namespace std;

int main(){
    gameBoard b{
        {1, 1, 1, 1, 1, 1, 1, 1, 1},
        {2, 2, 2, 2, 2, 2, 2, 2, 2},
        {3, 3, 3, 3, 3, 3, 3, 3, 3},
        {4, 4, 4, 4, 4, 4, 4, 4, 4},
        {5, 5, 5, 54, 55, 5, 5, 5, 5},
        {6, 6, 6, 6, 6, 6, 6, 6, 6},
        {7, 7, 7, 7, 7, 7, 7, 7, 7},
        {8, 8, 8, 8, 8, 8, 8, 8, 8},
        {9, 9, 9, 9, 9, 9, 9, 9, 9}        
    };
    
    solver mySolver{make_unique<board>(b)};
    unique_ptr<board> solvedBoard = mySolver.solve();


    // the best way for me to access the unique_ptr resource is to create a reference to it via get()
    
    return 0;
}
