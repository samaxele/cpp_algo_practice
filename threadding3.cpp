/*
Create 3 threads that do the following:
Thread 1: print 0
Thread 2: print odd numbers
Thread 3: print even numbers

Example: input 3
Output: 010203
*/

#include "myCustomHeader.h"
#include <thread> 
#include <mutex>

/* =================================================================
Global variables
================================================================= */
int buffer = 0;
bool callEnd = false;
bool num_update = false;

/* =================================================================
Thread controls
================================================================= */   
std::mutex cmd_key;
std::mutex incre_key;

/* =================================================================
User defined functions
================================================================= */


/* =================================================================
Threads routine
================================================================= */
void print_zero(int n) {
    /*
    the arg buffer <= n is to avoid trailing zeros to be printed
    */
    while(!callEnd) {
        if (num_update == true && buffer <= n) {   //everytime there is an update to buffer
            cmd_key.lock();
            std::cout << "0";
            num_update = false;
            cmd_key.unlock();
        }
        else if (buffer == 0) {
            cmd_key.lock();
            buffer++;
            num_update = true;
            cmd_key.unlock();
        }
    }
}

void print_odds() {
    while(!callEnd) {
        if (buffer%2 && !num_update && buffer > 0) { //if buffer = odd
            cmd_key.lock();
            std::cout << buffer;
            buffer++;
            num_update = true;
            cmd_key.unlock();
        }
    }
}

void print_even() {
    while(!callEnd) {
        if (!(buffer%2) && !num_update && buffer > 0) {
            cmd_key.lock();
            std::cout << buffer;
            buffer++;
            num_update = true;
            cmd_key.unlock();
        }
    }   
}

/* =================================================================
Main()
================================================================= */
int main() {
    int count;

    std::cout  << "enter number: ";
    std::cin >> count;
    
    std::thread th0(print_zero, count);
    std::thread th1(print_odds);
    std::thread th2(print_even);

    while (true){
        /*
        Main thread to poll the buffer
        */
        if (buffer > count) {
            callEnd = true;
            break;
        }
    }
    std::cout << "\n";
    th0.join();
    std::cout << "thread 0 joined\n";
    th1.join();
    std::cout << "thread 1 joined\n";
    th2.join();
    std::cout << "thread 2 joined\n";

   
    return 0;
}
