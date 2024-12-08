// solver.hpp
#pragma once

#include "board.hpp"
#include <set>

typedef vector<set<int>> setBundle;
typedef shared_ptr<setBundle> setBundlePtr;

using namespace std;
class solver {
  public:
    // solver() = delete;
    solver(unique_ptr<board>); // solver needs a board unique pointer
    unique_ptr<board> solve();
    bool isValidBoard(); // returns true if the solvedBoard_ is valid
    set<int> getCandidatesFromCoordinate(int,int); // returns all valid coordinates for curr point
    board& getInitialBoardRef(); // returns reference to initialBoard_ memory
    bool populateCell(int); // fill the given cell with valid values
    bool testIfSolutionAndInitialMatch();
    void printSolvedBoard();
  private:
    unique_ptr<board> initialBoard_;
    unique_ptr<board> solvedBoard_;
    vector<int> order; // order in which cells to solve
    
    
}; 
