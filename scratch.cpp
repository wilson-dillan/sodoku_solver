#include <iostream>
#include <memory>
#include <vector>

using namespace std;

typedef unique_ptr<vector<int>> dillanVector;
dillanVector getVec();

int main(){
    dillanVector myVec = getVec();
    auto tmp = *myVec;
    
    for(int i = 0; i < 10; i++){
        cout<<"Vector Value:\t"<< tmp[i] << endl;
    }
    return 0;
}

dillanVector getVec(){

    vector<int> v{};
    v.reserve(10);
   

    auto newVec = make_unique<vector<int>>(v);
    return newVec;
}
