// solver.cpp


#include "../include/solver.hpp"
#include "../include/board.hpp"

#include <map>
#include <tuple>
#include <cassert>
#include <deque>

// holds data structures for analyzing and parsing through the board
using namespace constants;
using namespace std;

enum class boundaryType{ROW, COL, CELL}; // Cells are treated differently. For Cell, we nee to use the cell grouping
typedef unordered_map<int, std::set<int>> grouping; // each row, col and cell can be stored in a "grouping"
typedef unordered_map<boundaryType, grouping> boardGroupings; // maps what type of boundary we are looking at. Either cell or row/col

solver::solver(unique_ptr<board> b) :
    initialBoard_{std::move(b)},
    solvedBoard_{make_unique<board>()}
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

set<int> solver::getCandidatesFromCoordinateHelper(board& inputBoard, int targetX ,int targetY){
    board& boardRef = inputBoard;
    set<int> remainder = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int targetCell = solver::coordinateToCell(targetX, targetY);
    for(int x = 0; x < WIDTH; x++){
        for(int y = 0; y < HEIGHT; y++){
            int currVal = boardRef[x][y];
            if(targetX == x || targetY == y || solver::coordinateToCell(x,y) == targetCell){
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


bool solver::solve(){
    if(currSolver == solverType::BACKTRACKING){
        doBackTracking(); 
    } else if(currSolver == solverType::BFS){
        doBFS();
    } else{
        assert(true);
    }
    return getSolvedBool();
}

void solver::doBackTracking(){
    board& initialBoard = *solvedBoard_.get();
    solved_ = doBackTrackingHelper(initialBoard); // true if solved
}
board& solver::getSolvedBoardRef(){
    return *solvedBoard_.get();
}
bool solver::doBackTrackingHelper(board& input){
    for(int x = 0; x < WIDTH; x++){
        for(int y = 0; y < HEIGHT; y++){
            // only enter into blank tiles
            if(input.get(make_tuple(x,y)) == 0){
                for(int e = 1; e < 10; e++){
                    input.set(make_tuple(x,y),e);
                    if(isValidBoard(input)){
                        if(doBackTrackingHelper(input)){
                            return true;
                        }
                    }
                }
                // since we did not find the element, we backtrack and set the existing element to zero 
                input.set(make_tuple(x,y), 0);
                return false;
            }
        }
    }
    return true;
}

void solver::doBFS(){
    board& initial = *solvedBoard_.get();
    solved_ = doBFSHelper(initial);
}

bool solver::doBFSHelper(board& input){
    std::deque<board> q;
    std::set<board> seen;
    q.push_front(input);
    while(q.size() != 0){
        board& topElem = q.front();        
        vector<board> childBoards = getChildren(topElem);
        for(board& b : childBoards){
            // add to queue if the board is valid and we have not seen this yet
            if(isSolvedBoard(b)){
                solvedBoard_ = make_shared<board>(b);
                return true;
            } else if(isValidBoard(b) && seen.count(b) == 0 && getChildren(b).size() > 0){
                q.push_front(b);
                seen.insert(b);
            }
        }
        q.pop_front();
    }
    // queue is empty, we have not seen the board
    return false;
}

vector<board> solver::getChildren(board& parentBoard){
    
    vector<board> childrenToReturn{}; // empty list to return

    for(int x = 0; x < WIDTH; x++){
        for(int y = 0; y < HEIGHT; y++){
            set<int> validTargetsForCurrCoordinate = getCandidatesFromCoordinateHelper(parentBoard,x,y);
            // append all these to the "children to return"
            // Note the children to return could all be conflicting
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


bool solver::checkTargetNotInRow(const board& inputBoard, int currRow, int targetNumber) const{
    assert(currRow<HEIGHT);
    for(int x = 0; x < WIDTH; x++){
        if(inputBoard.get(x,currRow) == targetNumber){
            return false;
        }
    }
    return true;
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

int solver::coordinateToCell(int x, int y){
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

// when no arguments are used, assume we check solvedBoard_;
bool solver::isSolvedBoard(){
    return isSolvedBoard(getSolvedBoardRef());
}

// returns if the board is valid or not
// ensures each number only appears once
// in each row, col and cell

bool solver::isValidBoard(board& board){
    grouping cellsMap;
    grouping rowsMap;
    grouping colsMap;

    boardGroupings bg = {
        {boundaryType::ROW, rowsMap},
        {boundaryType::COL, colsMap},
        {boundaryType::CELL, cellsMap}
    };

    // pass over each board grouping
    for(auto& kv : bg){
        for(int x = 0; x < WIDTH; x++){
            for(int y = 0; y < HEIGHT; y++){
                
                int currNumber = board.get(x,y);
                grouping& currGrouping = kv.second;

                int currIdentifier = -1; // this will be either a row, col or cell number used to access
                // determine boundary type accessor based on groupingType

                if(kv.first == boundaryType::ROW){ 
                    currIdentifier = y;
                } else if(kv.first == boundaryType::COL){
                    currIdentifier = x;
                } else if(kv.first == boundaryType::CELL){
                    // for cell, we behave differently
                    currIdentifier = coordinateToCell(x,y); // grouping is a cell
                } else{
                    // should not enter this case
                    assert(false);
                }
   

                assert(currIdentifier != -1);
                // first check if number is new
                if(currNumber != 0 && 
                    currGrouping[currIdentifier].find(currNumber) == currGrouping[currIdentifier].end()
                ){
                    // if number is new, add it to the set
                    currGrouping[currIdentifier].insert(currNumber);
                } else if(currNumber != 0){
                    // return false since that means we have seen this before;
                    return false;
                }
            }
        }
    }
    return true;
}

// returns the internal boolean on if the board was solved successfully
bool solver::getSolvedBool(){
    return solved_;
}

bool solver::isSolvedBoard(board& b){
    // solved board if it's valid and if there's no empty spaces in it
    for(int x = 0; x < HEIGHT; x++){
        for(int y = 0; y < WIDTH; y++){
            if(b.get(x,y) == 0){
                return false;
            }
        }
    }
    return isValidBoard(b); 
}