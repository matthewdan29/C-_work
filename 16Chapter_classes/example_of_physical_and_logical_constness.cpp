#include <string>
#include <list>
#include <iostream>
using namespace std;

/*A member function is logically "const", but it still needs to change the value of a member. 
 * That is to a user, the function appears not to change the state of its object, but som detail that the user cannot directly observe is updated. 
 * This is called "Logical constness."
 * The "Date" class might have a function returning a string representation. 
 * Construction this representation could be a relatively expensive operation.
 * It would make sense to keep a copy so that repreated request would simply return the copy, unless the "Date" value had been changed. 
 * Caching values like that is more common for more complicated data structures, but let's see how it can be achieved for a "Date":*/

class Date
{
public: 
	/*...*/
	string string_rep() const; 		/*string representation*/
private: 
	bool cache_valid; 
	string cache; 
	void compute_cache_value(); 		/*fill cache*/
	/*...*/
}/*From a user's point of view, "string_rep" doesn't change the state of its "Date", so it clearly should be a "const" member function. */
