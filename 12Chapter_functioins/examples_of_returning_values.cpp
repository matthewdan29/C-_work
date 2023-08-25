#include <string>
#include <list>
#include <iostream>
using namespace std; 

/*The following two declarations are equivalent*/
string to_string(int a); 				/*prefix return type*/
auto to_string(int a)->string; 				/*suffix return type: personally I seen this before but never used it */

/*The essential use for a suffix return type comes in fuction template declarations in which the return type depends on the arguments. */
template<class T, class U>
auto product(const vector<T>& x, const vector<U>& y)->decltype(x*y); 

/*A return value is specified by a "return"-statement.*/
int fac(int n)
{
	return (n > 1) ? n*fac(n-1) : 1; 
}

/*A function that calls itself is said to be recursive. There can be more than one "return"-statement in a function: */
int fac2(int n)
{
	if (n > 1)
		return n*fac2(n-1); 
	return 1; 
}/*Like the semantic of argument passing, the semantics of function value return are identical to the semantic of copy initialization. */
