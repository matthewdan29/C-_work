#include <string>
#include <iostream>
#include <list>
using namespace std; 

/*A task to be executed concurrently with other tasks is launched by constructing a "std::thread" with the task as its argument. A task is a function or a function object:*/

void f();		/*function*/

struct F		/*function object*/
{
	void operator()(); 	/*"F()" call operator*/
}; 

void user()
{
	thread t1
	{
		f	/*"f()" executes in separate thread*/
	}; 

	thread t2
	{
		F()
	}; 

	t1.join();	/*wait for t1*/
	t2.join();	/*wait for t2*/
}

/*The "join()" ensure that we dont exit "user()" until the threads have completed. To "join" means to "wait for the thread to terminate". */

/*Threads of a program share a single address space. Threads differ from processes, which generally do not directly share data. Since threads share an address space, they communicate through shared objects. "lock()" and "wait()" prevent data races.*/


