# Sudoku Solver #
**By Dillan Wilson**

This software implements a Sudoku solver. 

This solution has been designed to have a "board" object utilize a "solver" object to complete the board. 

**board** class responsibilities:
* get/set board elements,
* visualizing the board 
* set/get board dimensions
* creating a "board" object from a base 2d vector of ints, aka "gameboard"

**solver** class responsibilities: 
* handles all logic associated with the sudoku game
* implementation of solver algorithm (currently only BFS and backtracking are implemented)
* checks if a board is valid
* checks if a board is solved