#include "myCustomHeader.h"

int main() {
    auto timeNow_raw = std::chrono::system_clock::now();
    /*
    we're unable to show the time directly in terminal
    as << was not overloaded by the typedef
    std::chrono::time_point, we will need to convert it to time_t
    which is able to print in terminal.
    */

    std::time_t ostream_time = std::chrono::system_clock::to_time_t(timeNow_raw);
    /*
    After conversion, the time_t type variable now holds the binary
    value of current system time, we will need to convert to hh:mm:ss or
    ddmmyy as a human readable

    std::ctime actually converts time_t to human readable format such as
    DDD MMM dd hh:mm:ss YYYY
    */

    std::cout << "Hello World, curr time is " 
    << std::ctime(&ostream_time) << std::endl;

    /*
    "tm" typedef actually allows us to access detailed info
    such as hour or minute individually

    create a struct varaible and asign the time_t we've created earlier
    function: localtime is a function pointer with type 'tm'
    function 'localtime' also only takes in reference to time_t
    */
    tm myTime = *localtime(&ostream_time);

    /*
    Now we can access calendar numbern (nth day of week / month)
    more info https://en.cppreference.com/w/cpp/chrono/c/tm
    */

    std::cout << "Date: " <<
    myTime.tm_year +1900 << "/" <<  //nday since 1900
    myTime.tm_mon +1 << "/" <<  //n month since jan
    myTime.tm_mday << "\n";

    std::cout << "Time: " <<
    myTime.tm_hour << ":" <<
    myTime.tm_min << ":" <<
    myTime.tm_sec << "\n";

    
    
    return 0;
}