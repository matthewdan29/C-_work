#include <string>
#include <iostream>
#include <list>
using namespace std; 

/*Pointer, integal, and floating-point values can be implicitly converted to "bool". A nonzero value converts to "true" a zero value converts to "false"*/

void f(int* p, int i)
{
	bool is_not_zero = p; 			/*true if p!=0*/
	bool b2 = i; 
	/*...*/
}

/*The pointer-to-"bool" conversion is useful in conditions, but confusing elsewhere:*/

void fi(int); 
voidfb(bool); 

void ff(int* p, int* q)
{
	if (p) do_something(*p);		/*OK*/
	if (q!=nullptr) do_something(*q); 	/*ok, but verbose*/

	/*...*/

	fi(p); 					/*error: no pointer to int converstion*/
	fb(p);					/*OK: pointer to bool conversion(surprise!?)*/
}
