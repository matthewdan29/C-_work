#include <string>
#include <list>
#include <iostream>
using namespace std; 
/*Unless a formal argument is a reference, a copy of the actual argument is passed to the function. */

int* find(int* first, int* last, int v)		/*find x in [first:last)*/
{
	while (first != last && *first !=v)
		++first; 
	return first; 
}

void g(int* p, int* q)
{
	int* pp = find(p,q,'x'); 
	/*...*/
}

/*The callers copy of the argument, 'p', is not modified by the operations on "find()" copy, called, "first". The pointer is passed by value.*/
