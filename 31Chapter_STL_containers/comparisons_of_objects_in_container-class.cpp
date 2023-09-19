#include <string>
#include <list>
#include <iosteam>
#include <vector>
using namespace std; 

/*You might decide to sort "fruit" using a comparison that isn't case sensitive.
 * You do that by defining a function object that does the comparison when invoked for a pair of "string"'s: like below*/

class Nocase				/*case-insensitive string compare*/
{
public: 
	bool operator()(const string&, const string&) const;
}; 

bool Nocase::operator()(const string& x, const string& y) const
	/*return true if 'x' is lexicographically less that y, not taking case into accout*/
{
	auto p = x.begin(); 
	auto q = y.begin(); 
	
	while (p!=x.end() && q!=y.end() && toupper(*p) == toupper(*q))
	{
		++p; 
		++q; 
	}
	if (p == x.end()) return q != y.end(); 
	if (q == y.end()) return false; 
	return toupper(*p) < toupper(*q); 
}

/*You can call "sort()" using that comparison criterion. Conseder below:*/

fruit: 
	apple pear Apple Pear lemon

/*Sorting using "sort(fruit.begin(),fruit.end(),Nocase())" would yield something like below*/

fruit: 
	Apple apple lemon Pear pear

/*Assuming a character set in which uppercase letters precede lowercase letter, plain "sort(fruit.begin(),fruit.end())" would give the below example:*/

fruit: 
	Apple Pear apple lemon pear 

/*Beware that '<' on C-style strings compares pointers values. Associative containers will not work as most people would expect them to if C-style strings are used as keys. Less-than operation that compares based on lexicographical order must be used like the example below:*/

struct Cstring_less
{
	bool operator()(const char* p, const char* q) const{return strcmp(p,q)<0; }
}; 

map<char*, int,Cstring_less> m; 		/*map that uses "strcmp()" const char* keys */
