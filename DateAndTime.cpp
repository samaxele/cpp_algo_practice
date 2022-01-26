#include <iostream>
#include <ctime>    //this is the c method of time calling
#include <chrono>
#include <string>

/*
This is a sample code for all the time utility
*/
int main() {
    /*
    The C method
    */
    /*
    Init the time
    time_t time(time_t *time);
    >> return current calendar time since 1970 01 01
    We will have 'now' storing our time data.
    We are creating an object 'now', not pointer
    */
    time_t now = time(0);

    /*
    char *ctime(const time_t *time);
    This will convert any time data from time_t to a human-readable string
    the function is ctime.
    Since we have now as data, we need to pass by reference -> &now.
    */
    std::string myLocalTime = ctime(&now);
    
    std::cout<< "Build date = " << myLocalTime;
    std::cout << "This is ctime library\n\n";

    /*
    The C++ method
    */
    /*
    cppTimeNow now holds the system_clock return with the type
    std::chrono::time_point
    */
    auto cppTimeRAW = std::chrono::system_clock::now(); //return time now in ms

    std::time_t cppTimeNowRaw = std::chrono::system_clock::to_time_t(cppTimeRAW);
    std::string timemsg = ctime(&cppTimeNowRaw);

    std::cout << "Hello World, cpp time method = " << timemsg << std::endl;


    return 0;
}