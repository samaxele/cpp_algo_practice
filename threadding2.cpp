/*
Threadding tutorial by Derek Banas
https://www.youtube.com/watch?v=IdwJdJw65tU&ab_channel=DerekBanas
*/

#include "myCustomHeader.h"
#include <thread> 
#include <ctime>
#include <mutex>

/* =================================================================
Global variables
================================================================= */
double accBalance = 100;

/* =================================================================
Thread controls
================================================================= */   
std::mutex acctLock;

/* =================================================================
User defined functions
================================================================= */
int getRandom(int Range) {
    srand(time(NULL));  //generate seed
    return rand()%Range;
}

std::string getTime() {
    auto rawTime = std::chrono::system_clock::now();
    std::time_t tTime = std::chrono::system_clock::to_time_t(rawTime);
    return std::ctime(&tTime);
}

/* =================================================================
Threads routine
================================================================= */
void getMoney(int userid, double withdrawal) {
    // std::lock_guard<std::mutex> lock(acctLock);
    // //your code here
    // std::this_thread::sleep_for(std::chrono::seconds(3));
    // std::cout << "User ID: " << userid << "\nTries to withdraw $"
    // << withdrawal << " on " << getTime << "\n"; 

    // if ((accBalance-withdrawal) >= 0) {
    //     accBalance -= withdrawal;
    //     std::cout << "Your Balance: $"; 
    // }
    // else {
    //     std::cout << "Insufficient funds: $";
    // }
    // std::cout << accBalance << "\n";
    
    
    //Another method to lock the key
    acctLock.lock();

    //your code here
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout << "User ID: " << userid << "\nTries to withdraw $"
    << withdrawal << " on " << getTime() << "\n"; 

    if ((accBalance-withdrawal) >= 0) {
        accBalance -= withdrawal;
        std::cout << "Your Balance: $"; 
    }
    else {
        std::cout << "Insufficient funds: $";
    }
    std::cout << accBalance << "\n";
    
    acctLock.unlock();
    
}


/* =================================================================
Main()
================================================================= */
int main() {
    std::thread th1(getMoney,9876,23.55);
    th1.join(); 
    return 0;
}

