// board.cpp

#include <vector>
#include <memory>

#include "board.hpp"
using namespace std;
using namespace constants; 


// board constructor initializes an empty 9x9 sodoku board
board::board() : 
    b{make_unique<gameBoard>(9,vector<int>(9,0))},
    height{HEIGHT},
    width{WIDTH} {}

board::~board(){
    
}
    
// pretty prints the board
void board::printBoard(){
    int idx{HEIGHT};
    
    for(int i = 0; i < HEIGHT; i++){
        for(int j = 0; j < WIDTH; j++){
            
        }
    }
}

// called during board class construction
// to allocate stack memory

unique_ptr<gameBoard> initializeBoard(){
    unique_ptr<gameBoard> retBoard = make_unique<gameBoard>();
    return retBoard;
}


