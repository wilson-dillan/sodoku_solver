// board.cpp

#include <vector>
#include "board.hpp"
using namespace std;


// board constructor returns an empty 9x9 sodoku board

board::board(){
    make_unique<gameBoard>() myBoard{};
}

    
// pretty prints the board
void printBoard(){
    auto myBoard = inputBoard;
}


board* board::initializeBoard(){
    // initializes an empty 9x9 board
    make_unique<board> myBoard{};
    myBoard.reserve(9);

    for(int i = 0; i < 9; i++){
        vector<int> innerBoard{};
        innerBoard.reserve(9);

        myBoard[i] = innerBoard;

    }
    return &myBoard;
}


