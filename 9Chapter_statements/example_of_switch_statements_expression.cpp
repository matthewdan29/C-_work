#include <string>
#include <list>
#include <iostream>
using namespace std; 

/*A value may not be used more than once for "case"-lables in a "switch"-statment*/

void f(int i)
{
	switch (i)
	{
		case 2.7:		/*error: floating point uses for case*/
			/*...*/
		case2: 
			/*...*/
		case 4-2: 	/*error: 2 use twice case labels*/
	}
}; /*This switch version is preferred because the nature of the operation is explicit.*/

/*It is a good idea to comment the (rare) cases in which a fall through is intentional so that an uncommented fall-through can be assumed to be an error. */

switch (action)
{
	case do_and_print: 
		act(value); 
		/*no break: fall through to print*/
	case print: 
		print(value); 
		break; 
		/*...*/
}/*A "break" is the most common way of terminating a case, but a "return" is often useful.*/

/*If a "switch" is intended to have one case for each enumerator of an enumeration. Leaving out the "default" gives the compiler a chance to warn against a set of "cases" that almost but not quite match the set of enumerators.*/

enum class Vessel {cup, glass, goblet, chalice}; 

void problematic(Vessel v)
{
	switch(v)
	{
		case Vessel::cup: 	/*...*/ break; 
		case Vessel::glass;	/*...*/ break; 
		case Vessel::goblet:	/*...*/ break; 
	}
}/*such a mistake can easily occur when a new enumerator is added during maintenance.*/
