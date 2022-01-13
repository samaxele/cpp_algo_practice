#include <iostream>
#include <vector>

using namespace std;

int main() {
    int ans=0;
    int testcase = -1427800;
    vector<int> v1;
    while (testcase > 0) {
        v1.push_back(testcase%10);
        testcase /= 10;
    }

    auto it = v1.begin();

    while (it != v1.end()) {
        cout << *it << ", "; 
        it++;
    }

    cout << "\nans = " << ans <<endl; 

    auto it2 = v1.begin();
    while (it2 != v1.end()) {
        cout << *it2 << ", "; 
        ans = ans*10 + *it2;
        it2++;
        cout << "accu \"ans\"= " << ans << endl; 
    }

    it = v1.end();
    cout << *it << " and " << *(it-1) << " and " << *(it-2) << endl;
    cout << "ans = " << ans; 
 
    return 0;
}