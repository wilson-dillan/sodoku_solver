// solver.cpp


#include "../include/solver.hpp"

#include <map>

// holds data structures for analyzing and parsing through the board
using namespace constants;

typedef map<int,vector<int>> groupingData;
solver::solver(board& b) : b_{b} {}

// extracts a vector for each one
setBundle solver::getSets() {

    setBundle s{};
    groupingData row;
    groupingData col;
    groupingData cell;

    for(int i = 0; i < HEIGHT; i++){
        row[i+1] = vector<int>(9,0);
        col[i+1] = vector<int>(9,0);
        cell[i+1] = vector<int>(9,0);
    }
    
    for(int i = 0; i < HEIGHT; i++){
        for(int j = 0; j < WIDTH; j++){
            //            auto currVal = b_.at(i,j);
            
        }
    }
    
    return s;
}
