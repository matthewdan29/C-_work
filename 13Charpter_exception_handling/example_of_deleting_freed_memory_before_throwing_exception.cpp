#include <string>
#include <list>
#include <iostream>
using namespace std; 

/*All memory allocated must be either deallocated or owned by some object, which in turn must ensure that memory is properly deallocated before throwing an exception*/

void f(int i)
{
	int* p = new int[10]; 
	/*...*/
	if(i < 0)
	{
		delete[] p; 				/*delete before the throw or leak*/
		throw Bad(); 
	}
	/*...*/
}/*Memory isn't the only kind of resource that can leak. Consider anything that has to be acquired from another part of the system and given back to be a resource. Files, locks, network connection, and threads are examples of system resources.*/
