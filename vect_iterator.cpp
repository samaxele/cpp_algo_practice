// iterator example

#include <iostream>
#include <vector>
#include <time.h>
#include <random>

using namespace std;



int main () {
    vector<int> num = {1,2,5,6,7,10,24};
    auto it = num.begin();
    
    cout << "begin of vector = " << *(2+it) << endl;
    

    return 0;
}