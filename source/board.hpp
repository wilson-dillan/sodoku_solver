// board.hpp

#include <vector>
#include <memory>
#include <iostream>

using namespace std;

typedef vector<vector<int>> gameBoard; // typedef of board that stores the pieces

namespace constants
{
const int HEIGHT{9};
const int WIDTH{9};
}

class board{

  public:
    board(); // constructor for board. Default is board filled with zeros
    ~board(); // destructor
    board(gameBoard); // Accepts a game board to initialize a board class
    void printBoard(); // pretty prints the class's board
  private:
    unique_ptr<gameBoard> b; // block of memory holding the board
    int height; // height of board
    int width; // width of board
    /*
      y
      ^
      |
      |
      |
      |
      |
      |
      |
      |
      |
      o------------------------------> x
     */
};
