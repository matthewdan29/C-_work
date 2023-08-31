#include <string>
#include <list>
#include <iostream>
using namespace std; 

/*Most uses of "this" are implicit. Every reference to a non-"static" member from within a class relies on an implicit use of "This" to get the member of the appropriate object. Example The "add_year" function could equivalently, but tediously, have been defined like below*/

Date& Date::add_year(int n)
{
	if (this->d==29 && m==2 && !leapyear(this->y+n))
	{
		this->d = 1; 
		this->m = 3; 
	}
	this->y +=n; 
	return *this; 
}

/*One common explicit usee of "this"is in linked-list manipulation.*/
struct Link
{
	Link* pre; 
	Link* suc; 
	int data; 

	Link* insert(int x)			/*insert 'x' before this*/
	{
		return pre = new Link{pre, this, x}; 
	}

	void remove() 				/*remove and destroy this*/
	{
		if (pre) 
			pre->suc = suc; 
		if (suc)
			suc->pre = pre; 
	}

	/*...*/
}; 

/*Explicit use of "this" is required for access to members of base classes from a derived class that is a template.*/
