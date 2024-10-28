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

board::board(const gameBoard& input) :
    b{make_unique<gameBoard>(input)},
      height{HEIGHT},
      width{WIDTH} {}

board::~board(){
  // hello world    
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
                cout << (*b)[i][j] << ' '; 
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

// called during board class construction
// to allocate stack memory

unique_ptr<gameBoard> initializeBoard(){
    unique_ptr<gameBoard> retBoard = make_unique<gameBoard>();
    return retBoard;
}


