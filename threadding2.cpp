/*
Threadding tutorial by Derek Banas
https://www.youtube.com/watch?v=IdwJdJw65tU&ab_channel=DerekBanas
*/

#include "myCustomHeader.h"
#include <thread> 
#include <ctime>
#include <mutex>

/*
Threads routine
*/
void execThread (int ThreadID) {
    
}

/*
Function definition
Tips: if you define function, you dont need to declare again
*/
int GetRandom(int max) {
    srand(time(NULL));
    return rand()%max;
}


int main() {
    
    return 0;
}
