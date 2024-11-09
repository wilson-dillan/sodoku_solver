// solver.hpp
#pragma once

#include "board.hpp"
#include <set>

typedef vector<vector<set<int>>> setBundle;

using namespace std;
class solver {
  public:
    // solver() = delete;
    solver(unique_ptr<board>); // solver needs a board unique pointer
    unique_ptr<board> solve();
    bool isValidBoard(); // returns true if the solvedBoard_ is valid
    setBundle getSets();// returns a vector of sets for each row, column and cell. 27 total `
  private:
    unique_ptr<board> initialBoard_;
    unique_ptr<board> solvedBoard_;
    
    
}; 
