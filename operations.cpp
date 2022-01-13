#include <iostream>
#include <time.h>
#include <iomanip>

using namespace std;

int main() {
    //seed the random
    srand((unsigned)time(NULL));
    cout<< setprecision(4) << fixed;

    // double a = rand()/RAND_MAX;
    // double d = (double)rand()/RAND_MAX;
    //a += 3 + b;

    // for (int i=0; i<5; i++) {
    //     //cout << (double)rand()/RAND_MAX << endl;
    //     double a = (double)rand()/RAND_MAX;
    //     int d = (double)rand()/RAND_MAX;
    //     cout << "a = " << a <<"\nd = " << d << endl;
    // }
    double x=15,y=10;
    double n = x/y;
    cout << setprecision(4)
    << "n = " << n << endl;
    return 0;
}