#include <string>
#include <iostream>
#include <list>
#include <vector>
using namespace std; 

/*RAII ("Resource Acquisition is initialization") and is the basic technique for avoiding resource leaks and making error handling using exceptions simple and safe.*/
/*The standard-library "vector" is an example of these techniques: */
void f(const string& s)
{
	vector<char> v; 
	for(auto c : s)
		v.push_back(c); 
	/*...*/
}/*the vector keeps its elements on the free store, but it handles all allocations and deallocations itself. "push_back()" does "news" to acquire space for its elements and "delete"s to free space that it no longer needs. */

/*The "Token_stream" from the calculator example is an even simpler example. There, a user can use "new" and hand the resulting pointer to a "Token_stream" to manage: below*/
Token_stream ts{new istringstream{some_string}}; 

/*We do not need to use the free store just to get a large object out a function. */
string reverse(const string& s)
{
	string ss; 
	for (int i=s.size() - 1; 0 <= i; --i)
		ss.push_back(s[i]); 
	return ss
}/*Like "vector", a string is really a handle to its elements. We simply move the "ss" out of "reverse()" rather than copying any elements*/


