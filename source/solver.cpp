// solver.cpp


#include "../include/solver.hpp"
#include "../include/board.hpp"

#include <map>

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
    board& solvedBoardRef = *solvedBoard_;
    board& initialBoardRef = *initialBoard_;
    for(int i = 0; i < WIDTH; i++){
        for(int j = 0; j < HEIGHT; j++){
            point currPt{i,j};
            solvedBoardRef.set(currPt, initialBoardRef[i][j]);
        }
    }

}

int coordinateToCell(int,int);


/*
 * Return set of valid values for given targetX and targetY 
 * 
 */
set<int> solver::getCandidatesFromCoordinate(int targetX ,int targetY){
    board& boardRef = *initialBoard_.get();
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
    board& solvedBoardRef = *solvedBoard_;
    std::cout<< "NUMBER: " << solvedBoardRef[0][2] << endl;
    std::vector<board> q;
    std::set<board> seen;

    while(q.size() != 0){
        // std::vector<board> children = solver::getChildren(q.top) -> this should only return valid children
        // add all children that are not seen to the queue
        // remove the top element. 
        // continue until queue is empty. 
        // TODO: get children, and is valid board are what I need to do next
    }
}

// return yes or no if a cell was populated
bool solver::populateCell(int targetCell){
    // iterate over entire board
    // when I reach a coordinate inside the target cell
    // replace it with a valid number
    // If there are no valid numbers left, return false.
    // I don't have time to enhance the solver algorithm
    board& solvedBoardRef = *solvedBoard_;
    for(int i = 0; i < WIDTH; i++){
        for(int j = 0; j < HEIGHT; j++){
            if(coordinateToCell(i,j) == targetCell){
                // obtain set of valid coordinates
                set<int> candidates = getCandidatesFromCoordinate(i,j);
                // get random value
                int randVal = *select_random(candidates);
                point pt{i,j};
                solvedBoardRef.set(pt, randVal); // populate solved board with valid point
            }
        }
    }
    
    
    
    return true; 
}


bool solver::isValidBoard(){
  
    return false;
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
    board& solvedBoardRef = *solvedBoard_;
    solvedBoardRef.printBoard();
}
