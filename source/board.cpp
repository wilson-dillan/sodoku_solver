// board.cpp

#include <vector>
#include <memory>
#include <set>

#include "../include/board.hpp"

using namespace std;
using namespace constants; 


// board constructor initializes an empty 9x9 sodoku board
board::board() : 
    b_{make_unique<gameBoard>(9,vector<int>(9,0))},
    solvedBoard_{make_unique<gameBoard>(9,vector<int>(9,0))},
    height_{HEIGHT},
    width_{WIDTH} {}

board::board(const gameBoard& input) :
    b_{make_unique<gameBoard>(input)},
    solvedBoard_{make_unique<gameBoard>(9,vector<int>(9,0))},
    height_{HEIGHT},
    width_{WIDTH} {}

board::~board(){
  // hello world    
}

int board::get(int x, int y){
    return (*b_)[y][x];
}
    
// pretty prints the board
void board::printBoard(){
    int idx{HEIGHT};

    for(int i = 0; i < HEIGHT; i++){
        if( (i%3) == 0){
            cout<<"\t------- ------- -------"<<endl;
        }
        cout<< idx-- <<  "|\t";

        for(int j = 0; j < WIDTH + 1; j++){
            if(j%3== 0){
                cout<< "| ";
            }
            if(j < WIDTH && i < HEIGHT){
                cout << (*b_)[i][j] << ' '; 
            }
        }
        cout<<endl;
    }
    cout<< "\t"<< "------- ------- -------"<<endl;
    cout << "\t";
    for(int i = 0; i < WIDTH; i++){
        if( (i%3) == 0){
            cout<<"  ";
        }
        cout<< i + 1 << ' '; 
    }
    
}

// returns if the board is valid or not
// obtain 27 sets

bool board::isValidBoard(){
    for(int i = 0; i < HEIGHT; i++){
        
    }
    return false;
}

unique_ptr<gameBoard> board::solve(){
    return move(solvedBoard_);
}

