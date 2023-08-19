#include <list>
#include <string>
#include <iostream>

/*The fundamental element of the solution is a "mutex", a "mutual exclusion object". A thread acquiress a mutex using "lock()" operation: */

mutex m:		/*controlling mutex*/
int sh;			/*shared data*/

void f()
{
	unique_lock<mutex> lck {m};		/*acquire mutex*/
	sh += 7;				/*manipulate shared data*/
}/*release mutex implicitly*/

/*The "unique_lock" constructor acquires the mutex.*/
