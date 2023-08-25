#include <list>
#include <iostream>
#include <list>
using namespace std; 

/*By specifying a function "constexpr", we indicate that we want it to be usable in constant expressions if given constant expressions as arguments. */

constexpr int fac(int n)
{
	return (n > 1) ? n*fac(n-1) : 1; 
}
constexpr int f9 = fac(9); 			/*must be evaluated at compile time*/
