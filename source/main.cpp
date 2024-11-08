// main.cpp

#include <iostream>
#include "../include/board.hpp"

using namespace constants; 
using namespace std;
int main(){
    
    gameBoard b{
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 1, 1, 1, 1, 1, 1, 1, 1},
        {2, 2, 2, 2, 2, 2, 2, 2, 2},
        {3, 3, 3, 3, 3, 3, 3, 3, 3},
        {4, 4, 4, 4, 4, 4, 4, 4, 4},
        {5, 5, 5, 54, 55, 5, 5, 5, 5},
        {6, 6, 6, 6, 6, 6, 6, 6, 6},
        {7, 7, 7, 7, 7, 7, 7, 7, 7},
        {8, 8, 8, 8, 8, 8, 8, 8, 8}
    };
    
    board myBoard{};
    board otherBoard{b};

    cout<<"VALUE\t" << otherBoard[3][4]<< endl;

    cout<<"Source Files Ran"<< endl;
    
    return 0;
}
