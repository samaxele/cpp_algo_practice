#include <iostream>
#include <thread>
//#include <chrono>

// lets set a flag condition
static bool isFinish = false;

/*
Your multithread class body here...
*/
void someTask() {
    //this is use for timing purpose
    using namespace std::literals::chrono_literals;

    //this can call the thread id for own use
    std::cout << "Thread running, thread id: " << std::this_thread::get_id()
    << ", this is task\n";

    //assume this is thread_1, main thread = thread_0
    // do some random work 
    while (!isFinish) {
        //do this task forever
        std::cout << "Working...\n" ;

        //sleep this thread for 1s
        std::this_thread::sleep_for(1s);
    }
    std::cout << "Finish is called!\n";
}

int main() {
    std::cout << "Thread running, thread id: " << std::this_thread::get_id()
    << ", this is the main\n";
    /*
    Create a std::thread object with function task that we want to perform
    this is a function pointer in arg
    When std::thread was called, the thread task will be started and the
    main thread needs to wait task to end
    */
    std::thread myThread(someTask);

    /*
    get() will block the code (main thread or thread 0) until we tap Enter
    Since we called thread_1 previously, thread_1 will continue work while
    thread_0 proceed to next step get(). 

    When enter is pressed, isFInish will be set to true to end the
    while() running in thread_1 
    */
    std::cin.get();
    std::cout << "Enter pressed! program ending!\n";
    isFinish = true;

    /*
    join() will be called to wait thread_1 to complete.
    in more modern programming lang this is similar to wait()
    This also make sure we dont proceed before getting response from
    thread_1 completion
    */
    myThread.join();
    std::cout << "Program ended, press enter to exit";
    // exit the code with enter
    std::cin.get();
    return 0;
}