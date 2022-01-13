#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

int main() {
    srand(time(NULL));  //seed of random will refresh every start

    int s[5] = {2,1,4,7,4};
    vector<int> y = {2,1,4,3,5};
    
    for (int i=0; i<5; i++) {
        //y.push_back(rand()%10);
        y.push_back(s[i]);
        cout << y[i] << ", ";
    }
    cout << "\b\b  " << endl;

    for (auto x:y) {    //we can also use auto for type
        cout << x << endl;
    }

    return 0;
}