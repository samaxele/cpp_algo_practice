#include <iostream>
#include <string>

using namespace std;

int main() {
    string testcase="abcabcefgb";
    string testcase2 = "";
    auto it = testcase.begin();
    //cout << testcase << endl;
    
    // while (it != testcase.end()) {
    //     cout << *it << endl;
    //     if (*it == 'e') {
    //         cout << "found " << *it << " at ";
    //         cout << testcase.find(*it) << endl;
    //         it -= 4;
    //         }
    //     it++;
    // }

    //find one char

    int index = testcase.find('z');
    //if (testcase.find('z') <= 0) {cout << "'z' not found" << endl;}

    cout << "index of Z = " << index << endl;
    cout << "function of Z =" << testcase.find('z') << endl;
    return 0;
}