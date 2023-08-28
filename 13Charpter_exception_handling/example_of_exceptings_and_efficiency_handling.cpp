#include <string>
#include <list>
#include <iostream>
using namespace std; 

/*Code using ordinary code to handle errors instead of exceptions is something like this*/

bool g(int); 
bool h(const char*); 
char* read_long_string(); 

bool f()
{
	char* s = read_long_string(); 
	/*...*/
	if (g(1))
	{
		if (h(s))
		{
			free(s); 
			return true; 
		}
		else 
		{
			free(s); 
			return false; 
		}
	}
	else 
	{
		free(s); 
		return false; 
	}
}/*Using a local buffer for 's' would simplify the code by eliminating the calls to "free()", but then we'd have range-checking code instread. Complexity tends to move around rather than just disappear. */
