#include <string>
#include <iostream>
#include <list>
using namespace std; 

/*The state update functions "add_year()", "add_month()", and "add_day()" were defined not to return values.
 * For such a set of related update functions, it is often useful to return a reference to the updated object so that the operations can be chained.*/
/*if you would like to write:*/

void f(Date& d)
{
	/*...*/
	d.add_day(1).add_month(1).add_year(1); 
	/*...*/
}
/*To add a day, a month, and year to 'd'. Each function must be declared to return a reference to a "Date":*/

class Date
{
	/*...*/
	Date& add_year(int n); 			/*add 'n' years*/
	Date& add_month(int n); 		/*add 'n' months*/
	Date& add_day(int n); 			/*add 'n' days*/
}; 

/*Each member function knows for which object it was invoked and can explicitly refer to it.*/

Date& Date::add_year(int n)
{
	if(d == 29 && !leapyear(y+n))
	{
		d = 1; 
		m = 3; 
	}
	y += n; 
	return *this; 
}
