#include <iostream>

using namespace std; //

int main() {
    bool a= false;
    bool b= true;
    bool c = false;

    if (a && b || c) {
        cout << "a && b || b && c" <<endl;
    }

    if (a || b || c) {
        cout << "a || b || c" << endl;
    }
 
    return 0;
}