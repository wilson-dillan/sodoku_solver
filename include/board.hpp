// board.hpp

#pragma once

#include <vector>
#include <memory>
#include <iostream>

using namespace std;

typedef vector<vector<int> > gameBoard; // typedef of board that stores the pieces

namespace constants
{
const int HEIGHT = 9;
const int WIDTH = 9;
}

class board{

  public:
    board(); // constructor for board. Default is board filled with zeros
    board(const gameBoard&); // accepts a game board to initialize the class
    ~board(); // destructor
    void printBoard(); // pretty prints the class's board
    bool isValidBoard(); // determines if the current board meets Sodoku's rules
    // used to implement an [][] indexing scheme into my object
    class boardRow{
      public:
        boardRow(board& parent, int x) : parent{parent}, x{x} {}
        board& parent;
        int x;
        
        int operator[](int y){
            return parent.get(x,y);
        };    
    };
    boardRow operator[](int x){
        boardRow tmp{*this, x};
        return tmp;
    };
    int get(int x, int y); // helper method for double operator indexing
    unique_ptr<gameBoard> solve();
  private:
    unique_ptr<gameBoard>  b_; // block of memory holding the board
    int height_; // height of board
    int width_; // width of board
    /*
      o------------------------------> x
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
      V
      y
     */
};

/*                       CELL NUMBERS
    ---------------------------------------------------------
    |                   |                   |               |
    |       1           |       2           |       3       |
    |                   |                   |               |
    |                   |                   |               |
    --------------------------------------------------------|
    |                   |                   |               |
    |       4           |       5           |       6       |
    |                   |                   |               |
    |                   |                   |               |
    --------------------------------------------------------|
    |                   |                   |               |
    |       7           |       8           |       9       |
    |                   |                   |               |
    |                   |                   |               |
    ---------------------------------------------------------
*/
