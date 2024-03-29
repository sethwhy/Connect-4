#include <iostream>
#include <unistd.h>
#include <chrono>
 
using namespace std;
 
// using Chrono library
void display_time()
{
    auto start = chrono::steady_clock::now();
 
    // do some stuff here
    sleep(1);
 
    auto end = chrono::steady_clock::now();

    cout << "Elapsed time in seconds: "
        << chrono::duration_cast<chrono::seconds>(end - start).count()
        << " sec" << endl;
}