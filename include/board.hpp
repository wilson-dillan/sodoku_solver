// board.hpp

#pragma once

#include <vector>
#include <memory>
#include <iostream>

using namespace std;
/* Handles storage of a physical Sudoku board, as well as board visualization, and get/set */

typedef vector<vector<int> > gameBoard; // typedef of board that stores the pieces
typedef tuple<int,int> point;
typedef tuple<point,int> target; // that simplifies target points

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
    board(const board&); // copy constructor
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
    void operator=(const board & other){
      for(int x = 0; x < constants::WIDTH; x++){
        for(int y = 0; y < constants::HEIGHT; y++){
          this->set(make_tuple(x,y), other.get(x,y));
        }
      }
    }

    bool operator<(const board& other) const {
      for(int x = 0; x < constants::WIDTH; x++){
        for(int y = 0; y < constants::HEIGHT; y++){
          if(this->get(x,y) < other.get(x,y)){
            return true;
          }
        }
      }
      return false;
    }

    void set(point,int);
    int get(int x, int y) const; // helper method for double operator indexing
    int get(point pt) const; // helper method, accepts a point
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
