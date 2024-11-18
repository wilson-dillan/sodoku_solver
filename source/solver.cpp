// solver.cpp


#include "../include/solver.hpp"
#include "../include/board.hpp"

#include <map>

// holds data structures for analyzing and parsing through the board
using namespace constants;
using namespace std;

typedef map<int,vector<int>> groupingMap;

solver::solver(unique_ptr<board> b) :
    initialBoard_{move(b)},
    solvedBoard_{move(make_unique<board>())}
{}

int coordinateToCell(int,int);
// extracts a vector for each one

setBundlePtr solver::getValidNumForCurrCoordinate(int targetX ,int targetY){
    board& boardRef = *initialBoard_.get();
    int x = boardRef[3][2];
    cout<<x;
    set col = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    set row{col};
    set cell{col};

    for(int x = 0; x < WIDTH; x++){
        for(int y = 0; y < HEIGHT; y++){
            
            if(targetX == x){
                
            }
            if(targetY == y){

            }
            if(coordinateToCell(targetY, targetX)){

            }
            
        }
    }
    
    
    /*
      TODO:
      1. Given the existing (x,y), examine the entire column, and remove those
      existing entries from the set.
      2. Repeat for row and cell.
      3. The remaining set will contain the valid points for that coordinate.
      4. If the set is empty. return an error. Let's hope it's not empty.
      5. Else, populatle the board with this random point
      6. Repeat until the entire cell is filled in
    */
    setBundlePtr p = make_shared<setBundle>(vector{row, col, cell});
    return p;
}

unique_ptr<board> solver::solve(){
    // call funcitons to resolve the board
    getValidNumForCurrCoordinate(1,1);
    return move(solvedBoard_);
}

bool solver::isValidBoard(){
    // fill in logic here
    return false;
}

// returns the cell number based on the
// given x and y input coordinate

int coordinateToCell(int x, int y){
    return (x/3 + 1) + (y/3 *3);
}
