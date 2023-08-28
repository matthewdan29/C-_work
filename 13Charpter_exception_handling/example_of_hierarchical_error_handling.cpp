/*Error handling should be -- as far as possible -- hierarchical. (reread I had to it confused me at first)*/
#include <string>
#include <list>
#include <iostream>
using namespace std; 

/*It is necessary to convert from one style of error reporting to another. You might check "errno" before and possibly throw an exception after a call to a 'C' library or, conversely, catch an exception and set "errno" befroe returning to a 'C' program from the "C++" library:*/

void callC()			/*Call a 'C' function from "C++"; convert "errno"  to a throw*/
{
	errno = 0; 
	c_function(); 
	if (errno)
	{
		/*...local cleanup, if possible and necessary...*/
		throw C_blewit(errno); 
	}
}

extern "C" void call_from_C() noexcept	/*call a C++ function from C; convert a throw to "errno"*/
{
	try{
		c_plus_plus_function(); 
	}
	catch (...)
	{
		/*... local cleanup, if possible and necessary...*/
		errno = E_CPLPLFCTBLEWIT;	 
	}
}/*It is important to be systematic enough to ensure that the conversion of error-reporting styles is complete. Such conversions are often most desirale in "messy code" without a clear error-handling strategy and therefore defficult to be systematic about. */
