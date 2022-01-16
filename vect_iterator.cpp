// iterator example

#include <iostream>
#include <vector>
#include <time.h>
#include <random>
#include <algorithm>

using namespace std;



int main () {
    vector<int> num = {-20,-5,-1,0,2,5,6,7,10,24};
    int arr[10] = {-3,1,6,5,2,9,20,12,5,4};

    // int *arr_begin = num.begin();
    // int *arr_end = num.end();

    // auto it_begin = num.begin();
    // auto it_end = num.end();

    vector<int>::iterator myMin = min_element(num.begin(), num.end());
    //int *myMin = min_element(arr_begin, arr_end);

    cout << "minimum of a vector = " << *myMin << "\n";    

    return 0;
}