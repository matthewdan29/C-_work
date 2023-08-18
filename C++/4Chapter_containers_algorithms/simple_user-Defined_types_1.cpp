#include <iostream>
#include <list>
#include <string>

/*consider a simple type "Entry" that we might use to represent entries in a telephone book*/

struct Entry
{
	string name; 
	int number; 
};

/*you can define a simple output operator to write an Entry using a "{"name", numbr}" format similar to the one we use for initialization in code*/

ostream& operator <<(ostream& os, const Entry& e)
{
	return os << "{\""<<e.name<< "\"," << e.number <<"}"; 
}

/*A user-defined output operator takes its output stream as its first argument and return it as its result.*/
