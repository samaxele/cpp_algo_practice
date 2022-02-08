/*
Calculate prime numbers with threads, given there are 2 inputs start and end

Method of calculating prime
1. even value cannot be prime
2. Prime number can only be divided by own and 1
*/

#include "myCustomHeader.h"

std::mutex vectorLock;
std::vector<uint32_t> ansBank;

void FindPrimes(uint32_t start, uint32_t end) {
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
                vectorLock.lock();
                ans.push_back(x);
                vectorLock.unlock();
            }
        }
    }
}

void FindPrimesWithThreads(uint32_t start, uint32_t end, uint32_t numThreads) {
    
}

int main() {
    int start_time = clock();
    FindPrimes(1,100000,ansBank);

    //print out all the values
    printList(ansBank);
    
    int end_time = clock();
    std::cout << "Execution time: " 
    << (end_time-start_time)/double(CLOCKS_PER_SEC)
    << "\n";

    return 0;
}