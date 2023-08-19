#include <string>
#include <iostream>
#include <list>
using namespace std; 

/*this is a small example of the lock process.*/
/*This is mainly for multi threading*/
mutex m;		/*used to protect access to shared data*/
/*...*/

void f()
{
	unique_lock<mutex> lck {m};	/*acquire the mutex m*/
	/*...manipulate shared data...*/
}

/*A "thread" will not proceed until "lck" constructor has acquired its "mutex", m. */
/*The correctsponding destructor releases the resource.*/

