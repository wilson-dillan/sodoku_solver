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
    unique_ptr<board> doBFS();
    bool isValidBoard(); // returns true if the solvedBoard_ is valid
    set<int> getCandidatesFromCoordinate(int,int); // returns all valid coordinates for curr point
    board& getInitialBoardRef(); // returns reference to initialBoard_ memory
    vector<board> getChildren(board&);
    bool isValidPlacement(board& inputBoard, point coordinate, int targetNumber);
    set<int> getNumbersInCell(const board& inputBoard, int cell);
    bool checkTargetNotInCol(const board& inputBoard, int currCol, int targetNumber) const;
    bool checkTargetNotInRow(const board& inputBoard, int currRow, int targetNumber) const;
    bool testIfSolutionAndInitialMatch();
    void printSolvedBoard();
  private:
    const unique_ptr<board> initialBoard_{nullptr};
    shared_ptr<board> solvedBoard_{nullptr};
    vector<int> order; // order in which cells to solve
    
    
}; 
