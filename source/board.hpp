// board.hpp

#include <vector>
#include <memory>
#include <iostream>

using namespace std;

typedef vector<vector<int>> gameBoard; // typedef of board that stores the pieces

class board{

  public:
    board(); // constructor for board. Default is board filled with zeros
    ~board(); // destructor
    board(gameBoard); // Accepts a game board to initialize a board class
    void printBoard(board&); // pretty prints the given board

  private:
    unique_ptr<gameBoard> b; // block of memory holding the board
};
