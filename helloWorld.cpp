#include <iostream>
#include "myCustomHeader.h" 

/*
First Ubuntu code!
*/

int main() {
    std::vector<int> testcase = {2,3,5,3,2};
    std::cout<< "Hello World\n";
    std::cout << "My vector is ";
    printList(testcase);
    std::cout << std::endl;

    return 0;
}
