#include <iostream>
#include <thread>
//#include <chrono>

// lets set a flag condition
static bool task1_Finish = false;
static bool task2_Finish = false;
static unsigned int input;
/*
Your multithread class body here...
*/
void Task_1() {
    /*
    For timing purpose
    */
    using namespace std::literals::chrono_literals;

    //this can call the thread id for own use
    std::cout << "Task 1 ID: " << std::this_thread::get_id()
    << "\n";

    //assume this is thread_1, main thread = thread_0
    // do some random work 
    while (!task1_Finish) {
        //do this task forever
        std::cout << "Task 1: Working\n" ;

        //sleep this thread for 1s
        std::this_thread::sleep_for(1s);
    }
    std::cout << "Exit: Task 1 is done!\n";
}

void Task_2() {
    /*
    For input checking, this will active until Task1 is complete
    */
    using namespace std::literals::chrono_literals;

    //this can call the thread id for own use
    std::cout << "Task 2 ID: " << std::this_thread::get_id()
    << "\n";

    while (!task2_Finish) {
        //do this task forever
        //Task2 will pause here:
        std::cin >> input;
        if (2 == input) {
            /*
            Enter '2' will stop Task 1.
            */
            task1_Finish = true;
            task2_Finish = true;
            break;
        }
        else {
            std::cout << "Invalid input, enter '2' to end..\n";
            input =0;
        }
        /*
        Delay added to debounce input from user
        */
        std::this_thread::sleep_for(0.3s);
    }   
}
 
int main() {
    
    std::cout << "Main thread, thread id: " << std::this_thread::get_id()
    << "\n";
    /*
    Create an object with type <std::thread> object with task that we want that thread to perform
    Assume: Worker = thread, workload = task;
    this is a function pointer in arg
    When std::thread was called, the thread task will run
    */
    std::thread worker1(Task_1);
    std::thread worker2(Task_2);

    /*
    We call join() function to wait for both worker1 and worker2 to join after
    their executions are completed.
    */
    worker1.join();
    worker2.join();
    /*
    Both worker1 and worker2 will be working in parallel for now...
    We will need to do something so that both will react without interfering
    each other.
    */

    
    /*
    join() will be called to wait thread_1 to complete.
    in more modern programming lang this is similar to wait()
    This also make sure we dont proceed before getting response from
    thread_1 completion
    */

    std::cout << "Program ended, press enter to exit";
    
    return 0;
}