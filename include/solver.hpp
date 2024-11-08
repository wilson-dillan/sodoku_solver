// solver.hpp
#pragma once

#include "board.hpp"
#include <set>

typedef vector<vector<set<int>>> setBundle;

using namespace std;
class solver {
  public:
    // solver() = delete;
    solver(board&); // solver needs a board reference
    void solve();
  private:
    setBundle getSets();// returns a vector of sets for each row, column and cell. 27 total `
    board& board_;
    
    
}; 
