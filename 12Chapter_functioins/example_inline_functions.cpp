#include <string>
#include <list>
#include <iostream>
using namespace std; 

/*A function can be defined to be "inline". */
inline int fac(int n)
{
	return (n<2) ? 1 : n*fac(n-1); 
}
/*The "inline" speciier is a hint to the compiler that it should attempt to generate code for a call of "fac()" inline rather than laying down the code for the function once and then calling throught the ususal function call mechanism. */
