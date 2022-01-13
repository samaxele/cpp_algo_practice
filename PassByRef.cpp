#include <iostream>
#include <vector>

using namespace std;

void arrRemover(vector<int> &n) {
    //input is reference
    n[2] = 0;
    cout <<"nums[2] = " <<n[2] <<endl;

}

void arrRemover2(vector<int> n) {
    //input arg is not reference
    n[4] = 33;
    cout <<"nums[4] = " <<n[4] <<endl;
}

int main() {
    vector<int> n = {1,5,4,6};
    cout << "original: ";
    for (int y:n) {
        cout << y <<",";
    }
    cout << endl;
    
    arrRemover(n);
    for (int y:n) {
        cout << y <<",";
    }
    cout << endl;

    arrRemover2(n);
    for (int y:n) {
        cout << y <<",";
    }
    cout << endl;

    
    return 0;
}