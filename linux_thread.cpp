#include "myCustomHeader.h"

/*
include posix thread that is specific to Linux
*/
//#include <pthread>
std::mutex terminal_key;

bool callEnd = false;
bool zeroFlag = false;  //is true when term is updated
int buffer=0;


void print_zero(int count) {
    //print zero for every buffer upate
    while (buffer <= count) {
        if (zeroFlag) {
            terminal_key.lock();
            std::cout << "0";
            zeroFlag = false;
            terminal_key.unlock();
        }

        if (0 == buffer) {
            terminal_key.lock();
            std::cout << "0";
            buffer++;
            terminal_key.unlock();
        }
    }
    callEnd = true;
    std::cout << "\n\n";
}

void print_odds() {
    while (!callEnd) {
        if (buffer%2 && buffer > 0 && !zeroFlag) {
            terminal_key.lock();
            //you code here
            std::cout << buffer;
            zeroFlag = true;
            buffer++;
            terminal_key.unlock();
        }
    }
}

void print_evens() {
    while (!callEnd) {
        if (!(buffer%2) && buffer > 0 && !zeroFlag) {
            terminal_key.lock();
            //you code here
            std::cout << buffer;
            zeroFlag = true;
            buffer++;
            terminal_key.unlock();
        }
    }
}

int main () {
    int input = 0;
    std::cout << "Enter a number: ";
    std::cin >> input;

    std::thread th0(print_zero,input);
    std::thread th1(print_odds);
    std::thread th2(print_evens);

    th0.join();
    std::cout << "Thread 0 joined\n";
    th1.join();
    std::cout << "Thread 1 joined\n";
    th2.join();
    std::cout << "Thread 2 joined\n";
    
    std::cout << "\n";
    return 0;
}