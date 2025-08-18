// solver.hpp
#pragma once

#include "board.hpp"
#include <set>

typedef vector<set<int>> setBundle;
typedef shared_ptr<setBundle> setBundlePtr;

using namespace std;
class solver {
  public:
    solver(unique_ptr<board>); // solver needs a board unique pointer
    bool solve();
    void doBFS();
    bool doBFSHelper(board& input);
    void doBackTracking();
    bool isSolvedBoard();
    set<int> getCandidatesFromCoordinate(int,int); // returns all valid coordinates for curr point
    board& getInitialBoardRef(); // returns reference to initialBoard_ memory
    vector<board> getChildren(board&);
    set<int> getCandidatesFromCoordinateHelper(board& inputBoard, int targetX ,int targetY);
    int coordinateToCell(int x, int y);
    bool isValidBoard(board&);
    bool isSolvedBoard(board& b);
    set<int> getNumbersInCell(const board& inputBoard, int cell);
    bool checkTargetNotInRow(const board& inputBoard, int currRow, int targetNumber) const;
    bool testIfSolutionAndInitialMatch();
    void printSolvedBoard();
    bool getSolvedBool();
    board& getSolvedBoardRef();// returns const ref to solved board
    enum class solverType{BFS, BACKTRACKING}; // specify the solver type to be used
    solverType currSolver{solverType::BACKTRACKING};
  private:
    const unique_ptr<board> initialBoard_{nullptr};
    shared_ptr<board> solvedBoard_{nullptr};
    vector<int> order; // order in which cells to solve
    bool doBackTrackingHelper(board& input);
    bool solved_{false}; // true if the board has been solved successfully
    
}; 
