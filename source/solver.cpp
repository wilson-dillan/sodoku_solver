// solver.cpp


#include "../include/solver.hpp"
#include "../include/board.hpp"

#include <map>
#include <tuple>
#include <cassert>

// holds data structures for analyzing and parsing through the board
using namespace constants;
using namespace std;

typedef map<int,vector<int>> groupingMap;

template<typename S>
auto select_random(const S &s) {
    size_t n = rand() % s.size();
    auto it = std::begin(s);
    // 'advance' the iterator n times
    std::advance(it,n);
    return it;
}

solver::solver(unique_ptr<board> b) :
    initialBoard_{std::move(b)},
    solvedBoard_{make_unique<board>()},
    order{1, 2, 3, 4, 5, 6, 7, 8, 9}
{
    // i think there's a cleaner way via modification of the copy constructor,
    // but this is all feel to do as of now
    board& solvedBoardRef = *solvedBoard_.get();
    board& initialBoardRef = *initialBoard_.get();
    for(int i = 0; i < WIDTH; i++){
        for(int j = 0; j < HEIGHT; j++){
            point currPt{i,j};
            solvedBoardRef.set(currPt, initialBoardRef[i][j]);
        }
    }

}

int coordinateToCell(int,int);


set<int> getCandidatesFromCoordinateHelper(board& inputBoard, int targetX ,int targetY){
    board& boardRef = inputBoard;
    set<int> remainder = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int targetCell = coordinateToCell(targetX, targetY);
    for(int x = 0; x < WIDTH; x++){
        for(int y = 0; y < HEIGHT; y++){
            int currVal = boardRef[x][y];
            
            if(targetX == x || targetY == y || coordinateToCell(x,y) == targetCell){
                if(remainder.find(currVal) != remainder.end()){
                    remainder.erase(currVal);
                }
            }
        }
    }
    
    /*
      TODO:
      1. Given the existing (x,y), return a set of valid coordinates.
      2. Check if set is size 0.
      3. If yes, populate a different cell.
      5. Else, populatle the board with this random point.
      6. Repeat until the entire cell is filled in.
    */
   
    return remainder;
}

/*
 * Return set of valid values for given targetX and targetY 
 * 
 */


set<int> solver::getCandidatesFromCoordinate(int targetX ,int targetY){
    return getCandidatesFromCoordinateHelper(*initialBoard_.get(), targetX, targetY);
}

unique_ptr<board> solver::solve(){
    /*
     * TODO: 
     * 1. Do a BFS until I hit the final board
     * 2. If Queue is empty, no such board exists. 
     * 
     */


    // let's populate cell 6
    
    return solver::doBFS();
}

unique_ptr<board> solver::doBFS(){
    board& solvedBoardRef = *solvedBoard_.get();
    std::vector<board> q;
    std::set<board> seen;

    while(q.size() != 0){
        // std::vector<board> children = solver::getChildren(q.top) -> this should only return valid children
        // add all children that are not seen to the queue
        // remove the top element. 
        // continue until queue is empty. 
        // TODO: get children, and is valid board are what I need to do next
    }
    return nullptr;
}

vector<board> solver::getChildren(board& parentBoard){
    
    vector<board> childrenToReturn{}; // empty list to return

    for(int x = 0; x < WIDTH; x++){
        for(int y = 0; y < HEIGHT; y++){
            set<int> validTargetsForCurrCoordinate = getCandidatesFromCoordinateHelper(parentBoard,x,y);
            // append all these to the "children to return"
            // Note the children to return will all be conflicting
            // enter if current cell is empty
            if(parentBoard.get(x,y) == 0){
                for(int e:validTargetsForCurrCoordinate){
                    board newChildBoard = parentBoard;
                    point pt = std::make_tuple(x,y);
                    newChildBoard.set(pt,e);
                    childrenToReturn.push_back(newChildBoard);
                }
            }
        }
    }
    return childrenToReturn;
}

// checks if the targetNumber can be placed at the proposed coordinate or not
bool solver::isValidPlacement(board& inputBoard, point coordinate, int targetNumber){
    int x = get<0>(coordinate);
    int y = get<1>(coordinate);

    int cellNumOfTargetInt = coordinateToCell(x,y);

    return true;
}

bool solver::checkTargetNotInCol(const board& inputBoard, int currCol, int targetNumber) const{
    // return false if the number already exists
    assert(currCol<WIDTH);
    for(int y = 0; y < HEIGHT; y++){
        if(inputBoard.get(currCol,y) == targetNumber){
            return false;
        }
    }
    return true;
}

bool solver::checkTargetNotInRow(const board& inputBoard, int currRow, int targetNumber) const{
    assert(currRow<HEIGHT);
    for(int x = 0; x < WIDTH; x++){
        if(inputBoard.get(x,currRow) == targetNumber){
            return false;
        }
    }
    return true;
}



bool solver::isValidBoard(){
  
    return false;
}

/*
    @Brief: when an input board is passed in with a cell, return
    all the numbers in that specific cell

    @Return: a set of numbers in the given cell. Should not contain duplicates
    and should not be greater than 9.
*/
set<int> solver::getNumbersInCell(const board& inputBoard, int cell){
    set<int> retSet;

    for(int x = 0; x < WIDTH; x++){
        for(int y = 0; y < HEIGHT; y++){
            if(coordinateToCell(x,y) == cell){
                // we are in the cell
                int currVal = inputBoard.get(x,y);
                if(currVal != 0){
                    assert(retSet.count(currVal) == 0);
                    retSet.insert(currVal);
                }
                
                    // assert if element is seen in set, besides 0  
            }
        }
    }
    assert(retSet.size() < 10);
    return retSet;
}

// returns the cell number based on the
// given x and y input coordinate

int coordinateToCell(int x, int y){
    return (x/3 + 1) + (y/3 *3);
}


// ugly hack used only for testing purposes
bool solver::testIfSolutionAndInitialMatch(){
      // fill in logic here
    bool init = true;
    for(int i = 0; i < WIDTH; i++){
        for(int j = 0; j < HEIGHT; j++){
            init = (*initialBoard_)[i][j] == (*solvedBoard_)[i][j] && init;
        }
    }
    return init;
}

void solver::printSolvedBoard(){
    board& solvedBoardRef = *solvedBoard_.get();
    solvedBoardRef.printBoard();
}
