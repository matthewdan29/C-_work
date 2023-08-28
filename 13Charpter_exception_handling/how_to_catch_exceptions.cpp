#include <string>
#include <list>
#include <iostream>
using namespace std; 

/*Consider*/

void f()
{
	try
	{
		throw E{}; 
	}
	catch(H)
	{
		/*when do we get here*/
	}
}

/*The "{}" in both the "try"-part and a "catch"-clause of a "try"-block are real scopes. If a name is to be used in both parts of a "try"-block or outside it, that name must be declared outside the "try"-block*/

void g()
{
	int x1; 

	try
	{
		int x2 = x1; 
		/*...*/
	}
	catch (Error)
	{
		++x1; 			/*OK*/
		++x2; 			/*error: x2 not in scope*/
		int x3 = 7; 	
		/*...*/
	}
	catch(...)
	{
		++3; 			/*error: x3 not in scope*/
		/*...*/
	}

	++x1; 				/*OK*/
	++x2; 				/*error: not in scope*/
	++x3; 				/*error: x3 not in scope*/
}
