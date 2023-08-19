#include <iostream>
#include <list>
#include <string>
using namespace std; 

/*unique_ptr represent unique ownership*/
/*This smart pointer is to prevent memory leaks caused by careless programming.*/
void f(int i, int j)
{
	X* p = new X;		/*allocate a new X*/
	unique_ptr<X>sp {new X};	/*allocate a new X and give its pointer to unique_ptr*/
	/*...*/

	if (i < 99)
		throw Z{};	/*may throw an exception*/
	if (j < 77)
		return;		/*may return "early"*/
	p->do_something();	/*may throw an exception*/
	sp->do_something();	/*may throw an exception*/
	/*...*/
	delete p;		/*destroy *p*/
}

/*Here deleting p was forgoten if conditions i<99 or if j<77 are meet but unique_ptr ensures that its object is properly destroyed whichever way you exit f().*/

/*you could of just used local variable*/
void f(int i, int j)	/*use a local variable*/
{
	X x; 
	/*...*/
}

