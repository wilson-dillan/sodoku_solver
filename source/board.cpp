// board.cpp

#include <vector>
#include <memory>
#include <set>

#include "../include/board.hpp"

using namespace std;
using namespace constants; 


// board constructor initializes an empty 9x9 sudoku board
board::board() : 
    b_{make_unique<gameBoard>(9,vector<int>(9,0))},
    height_{HEIGHT},
    width_{WIDTH} {}


board::board(const gameBoard& input) :
    b_{make_unique<gameBoard>(input)},
    height_{HEIGHT},
    width_{WIDTH} {}

board::~board(){}

board::board(const board& otherBoard){
    // copy constructor to allocate memory for new board object
    const gameBoard& gb = *otherBoard.b_.get();
    b_ = make_unique<gameBoard>(gb); // block of memory holding the board
    
    height_ = otherBoard.height_; // height of board
    width_ = otherBoard.width_; // width of board
}// copy constructor

int board::get(int x, int y) const{
    return (*b_)[y][x];
}
int board::get(point pt) const{
    int x = std::get<0>(pt);
    int y = std::get<1>(pt);

    return (*b_)[y][x];
}
void board::set(point pt, int val){
    using std::get;
    (*b_)[get<1>(pt)][get<0>(pt)] = val;
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
    cout<<endl;
    
}





