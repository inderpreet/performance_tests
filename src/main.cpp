// A simple program that computes the square root of a number
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <app.h>
#include <iostream>
#include <chrono>
#include <ctime>
#include <threads1.h>

using namespace std::chrono;
using namespace std::chrono_literals;

int main(int argc, char *argv[]) {
    fprintf(stdout, "%s Version %d.%d\n",
            argv[0],
            APP_VERSION_MAJOR,
            APP_VERSION_MINOR);

    //! Set starting time
    high_resolution_clock::time_point t1 = high_resolution_clock::now();

    //! Do stuff here
    test_threads(0);     //! Test multiple Threads
    //loop_by_count();   //! Test Single Loop- No threads

    //! Set end time
    high_resolution_clock::time_point t2 = high_resolution_clock::now();

    //! Calculate elapsed time
    duration<double> time_span = duration_cast<duration<double> >(t2 - t1);

    std::cout << "It Took " << time_span.count() << " Seconds\n";

    return 0;
}

/*
 * Scraps begin here---------------------->
 */
// fprintf(stdout, "It took me %lf seconds", time_span.count() );
// if (argc < 2)
//   {
//   fprintf(stdout,"%s Version %d.%d\n",
//           argv[0],
//           APP_VERSION_MAJOR,
//           APP_VERSION_MINOR);
//   std::cout << std::endl;
//   fprintf(stdout,"Usage: %s number\n",argv[0]);
//   return 1;
//   }
// double inputValue = atof(argv[1]);
// double outputValue = sqrt(inputValue);
// fprintf(stdout,"The square root of %g is %g\n",
//         inputValue, outputValue);
