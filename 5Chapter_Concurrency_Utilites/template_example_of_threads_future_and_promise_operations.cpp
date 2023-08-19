#include <sting>
#include <iostream>
#include <list>
#include <threads>
using namespace std;
/*The important point about "future()" and "promis()" is that they enable a transfer of a value between 2 tasks without explicit use of a lock; "the system" implements the transfer efficiently. */

/*If you have a "promise()" and need to send result of type 'X' to a "future()" you can do one of two things: pass a value or pass an exception.*/

void f(promise<X>& px)	/*a task: place the result in "px"*/
{
	/*...*/
	try
	{
		X res; 
		/*...compute a value for res...*/
		px.set_value(res); 
	}
	catch(...)		/*something went wrong: couldn't compute res*/
	{
	/*pass the exception to the futures's thread:*/
		px/set_exception(current_exception()); 
	}
}
/*The "current_exception()" refers to the caught exception.*/
/*Next template*/

/*To deal with an exveption transmitted throught a "future" the call of "get()" must be prepared to catch it somewhere.*/
void g(future<X>& fx)		/*a task: get the result from fx*/
{
	
	/*...*/
	try
	{
		X v = fx.get();		/*if necessary, wait for the value to get computed */
		/*... use v ...*/
	}
	catch(...)		/*oops: someone couldn't compute v*/
	{
		/*...handle error....*/
	}
}

