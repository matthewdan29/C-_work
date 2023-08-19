#include <string>
#include <list>
#include <iostream>
#include <threads>
using namespace std::chrono;

auto t0 = high_resolution_clock::now(); 
do_work(); 
auto t1 = high_resolution_clock::now(); 
cout << duration_cast<milliseconds>(t1-t0).count() << "msec\n"; 

/*this returns the time during some type of diraction. best if you want to test the time of a function. */
