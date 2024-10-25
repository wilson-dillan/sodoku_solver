// board.hpp

#include <vector>
#include <memory>

using namespace std;

typedef vector<vector<int>> gameBoard; // typedef of board that stores the pieces

class board{
  public:
    board();
    void printBoard(board& );
    board* initializeBoard(); // returns a pointer to an empty board
    unique_ptr<gameBoard> b; // block of memory holding the board
    
};
