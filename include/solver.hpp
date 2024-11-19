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
    setBundlePtr getSetsFromRowColCell(int,int);// returns a vector of sets for each row, column and cell. 27
    board& getInitialBoardRef(); // returns reference to initialBoard_ memory
  private:
    unique_ptr<board> initialBoard_;
    unique_ptr<board> solvedBoard_;
    
    
}; 
