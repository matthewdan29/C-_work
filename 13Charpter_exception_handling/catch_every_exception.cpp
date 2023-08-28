#include <string>
#include <iostream>
#include <list>
#include <stdexcept>		/*I dont think you would need this*/
using namespace std; 

/*in the "<stdexcept>", the standard library provides a small hierarchy of exception classes with a common base "exception"*/

void m()
{
	try
	{
		/*..do something..*/
	}
	catch(std::exception& err)		/*handle every standard-librar exception*/
	{
		/*...cleanup...*/
		throw; 
	}
}/*This catches every standard-library exception.*/

/*As for functions, the ellipsis, ..., indicates "any argument", so "catch(...)" means "catch any exception". */

void m()
{
	try
	{
		/*...something...*/
	}
	catch(...)			/*handle every exception*/
	{
		/*...cleanup*/
		throw; 
	}
}
