/*
Calculate prime numbers with threads, given there are 2 inputs start and end

Method of calculating prime
1. even value cannot be prime
2. Prime number can only be divided by own and 1

This is the prime function with normal nested for loop approach 
*/

#include "myCustomHeader.h"

void FindPrimes(uint32_t start, uint32_t end, std::vector<uint32_t> &ans) {
    for (uint32_t x = start; x<end; x++) {
        //even numbers cannot be prime
        for (uint32_t y=2; y<x; y++) {
            //divisor, we loop y all the way to x
            if (x%y == 0) {
                //x is divisible by y, so x is not prime
                break;
            }
            else if ((y+1) == x) {
                // x is prime number
                ans.push_back(x);
            }
        }
    }
}

int main() {
    std::vector<uint32_t> ansBank;
    int start_time = clock();
    FindPrimes(4,40,ansBank);

    //print out all the values
    printList(ansBank);
    
    int end_time = clock();
    std::cout << "Execution time: " 
    << (end_time-start_time)/double(CLOCKS_PER_SEC)
    << "\n";
    
    return 0;
}