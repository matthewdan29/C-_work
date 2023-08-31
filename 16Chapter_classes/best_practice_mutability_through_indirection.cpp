#include <string>
#include <list>
#include <iosteam>
using namespace std; 

/*Declaring a member "mutable" is most appropriate when only a small part of a representation of a small object is allowed to change. 
 * More complicated cases are often better handled by placing the changing data in a separate object and accessing it indirectly. 
 * If that techneque is used, the string-with-cache example becomes: */

struct cache
{
	bool valid; 
	string rep; 
}; 

class Date
{
public: 
	/*...*/
	string string_rep() const; 		/*string representation*/
private: 
	cache* c; 				/*initialize in constructor*/
	void compute_cache_value() const; 	/*fill what cache refers to*/
	/*...*/
}; 

string Date::string_rep() const
{
	if(!c->valid)
	{
		compute_cache_value(); 
		c->valid = true; 
	}
	return c->rep; 
}/*The programming techniques that support a cache generalize to various forms of lazy evaluation. */
