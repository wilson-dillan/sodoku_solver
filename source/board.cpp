// board.cpp

#include <vector>
#include <memory>

#include "board.hpp"
using namespace std;


// board constructor initializes an empty 9x9 sodoku board
board::board() : 
    b{make_unique<gameBoard>(9,vector<int>(9,0))}
    
{

   
    for(vector<int> v : *b){
        for(int i : v){
            cout<<i;
        }
        cout<<endl;
    }
}

board::~board(){
    
}
    
// pretty prints the board
void printBoard(){
    // auto myBoard = inputBoard;
}

// called during board class construction
// to allocate stack memory

unique_ptr<gameBoard> initializeBoard(){
    unique_ptr<gameBoard> retBoard = make_unique<gameBoard>();
    return retBoard;
}


