#include <iostream>
#include "myCustomHeader.h" 
#include <ctime>

/*
First Ubuntu code!
*/

int main() {
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
    std::cout << "\n";

    return 0;
}
