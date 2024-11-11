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
setBundle solver::getSets() {
    setBundle s{};
    groupingMap row;
    groupingMap col;
    groupingMap cell;

    board& tmpBoard = (*initialBoard_.get());
    for(int i = 0; i < HEIGHT; i++){
        row[i] = vector<int>();
        col[i] = vector<int>();
        cell[i] = vector<int>();
    }
    
    for(int x = 0; x < WIDTH; x++){
        for(int y = 0; y < HEIGHT; y++){
            row[y].push_back(tmpBoard[x][y]); // push back all the same values at this y coordinate
            col[x].push_back(tmpBoard[x][y]);
            cell[coordinateToCell(x,y)].push_back(tmpBoard[x][y]);
        }
    }
    
    return s;
}

unique_ptr<board> solver::solve(){
    // call funcitons to resolve the board
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
