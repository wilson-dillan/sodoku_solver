// main.cpp

#include <iostream>
#include "board.hpp"

using namespace std;
int main(){

    cout<<"HELLO WORLD\n"<<endl;
    
    board myBoard{};
    unique_ptr<gameBoard> p = make_unique<gameBoard>(9,vector<int>(9,0));

   
    
    
    return 0;
}
