#include <iostream>
#include "../include/board.hpp"
#include "../include/solver.hpp"

using namespace constants; 
using namespace std;
/*
Sudoku solver
Dillan Wilson
August 18, 2025

The way system is designed to have a "board" object utilize a "solver" object to solve the board. 

board class responsibilities:
- get/set board elements,
- visualizing the board 
- set/get board dimensions
- creating a "board" object from a base 2d vector of ints, aka "gameboard"

solver class responsibilities: 
- handles all logic associated with the sudoku game
- implementation of solver algorithm (currently only BFS and backtracking are implemented)
- checks if a board is valid
- checks if a board is solved

*/
int main(){
    std::cout<<"Running source"<<std::endl;
    gameBoard b{
        {0, 0, 0, 0, 0, 0, 0, 0, 1},
        {9, 0, 5, 3, 0, 0, 6, 0, 0},
        {0, 0, 3, 1, 0, 0, 0, 4, 0},
        {0, 0, 2, 0, 8, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 0, 6},
        {7, 0, 0, 0, 0, 0, 5, 8, 0},
        {0, 0, 0, 0, 0, 3, 0, 0, 0},
        {8, 7, 0, 0, 2, 6, 0, 0, 4},
        {0, 4, 0, 0, 0, 0, 7, 0, 0}        
    };
    


    solver mySolver{make_unique<board>(b)};
    if(mySolver.solve()){
        cout<<"SOLVED THE BOARD"<<endl;
        mySolver.printSolvedBoard();
    } else{
        cout<<"Did not solve the board"<<endl;
    }
    
    return 0;
}
