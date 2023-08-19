#include <string>
#include <iostream>
#include <threads>
using namespace std; 

/*standard library offer help in the form of an operation for acquiring several locks simultaneously*/

void f()
{
	/*...*/
	unique_lock<mutex> lck1 {m1, defer_lock};	/*defer_lock: dont yet try to acquire the mutex*/
	unique_lock<mutex> lck2 {m2, defer_lock};
	unique_lock<mutex> lck3 {m3, defer_lock}; 
	/*...*/
	lock(lck 1, lck 2, lck 3);		/*acquire all three locks*/
	/*...manipulate shared data...*/
}/*implicitly release all mutexes*/

/*This "lock()" will only proceed after acquiring all its "mutex" arguments and will never block while holeing a mutex.*/
