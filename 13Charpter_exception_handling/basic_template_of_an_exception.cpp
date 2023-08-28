#include <string>
#include <iostream>
#include <list>
#include <vector>
using namespace std;

/*A function that wants to handle a kind of problem indicates that by catching the corresponding exception. 
 * A calling component indicates the kinds of failures that is willing to handle be specifying those exceptions in a "catch"-clause of a "try"-block
 * A called component that cannot complete its assigned taske reports its failure to do so by throwing an exception using a "throw"-expression*/

void taskmaster()
{
	try
	{
		auto result = do_task(); 
		/*use result*/
	}
	catch (Some_error)
	{
		/*failure to do_task: handle problem */
	}
}

int do_task()
{
	/*...*/
	if (/*could perform the task*/)
		return result; 
	else 
		throw Some_error{}; 
}

/*The simplest way of defining an exception is to define a class specifically for a kind of error and throw that */

struct Range_error{}; 

void f(int n)
{
	if (n<0 || max<n) 
		throw Range_error{}; 
	/*...*/
}/*If that gets tedious, the standard library defines a small hierarchy of exception classes*/
