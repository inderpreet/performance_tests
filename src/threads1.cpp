/**
 * @file    threads1.cpp
 * @author  Inderpreet Singh
 */
#include <threads1.h>
#include <iostream>
#include <chrono>
#include <thread>

using namespace std::chrono_literals;
using namespace std::chrono;

/**
 * @brief   Function to loop for a fixed duration
 */
void
loop_by_time(void) {
    time_point<system_clock> start, end;
    start = system_clock::now();
    end = system_clock::now();
    for (;;) {
        end = system_clock::now();
        duration<double> elapsed_seconds = end - start;
        // std::cout << elapsed_seconds.count(); 
        if (elapsed_seconds.count() > 5)
            break;
    }
}

/**
 * @brief   Function to loop for a fixed count.
 */
void
loop_by_count() {
    double i = 1000000000; //!< Around 1 seconds on a descent machine
    while (i != 0) {
        i--;
    }
}

/**
 * @brief Function to generate multiple threads
 * @param n
 */
void
test_threads(int n) {
    std::thread t1(loop_by_count);
    std::thread t2(loop_by_count);
    std::thread t3(loop_by_count);
    std::thread t4(loop_by_count);
    std::thread t5(loop_by_count);
    std::thread t6(loop_by_count);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();

}