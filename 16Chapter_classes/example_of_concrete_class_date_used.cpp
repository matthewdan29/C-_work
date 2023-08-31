#include <list>
#include <string>
#include <iostream>
using namespace std; 

/* Here is a small and contrived example of how Concrete class "Date"s can be used:*/

void f(Date& d)
{
	Date lvb_day{16, Month::dec, d.year()}; 

	if(d.day() == 29 && d.month() == Month::feb)
	{
		/*...*/
	}
	if (midnight()) d.add_day(1); 

	cout << "day after:" << d+1 << '\n'; 

	Date dd; 			/*initialized to the default date*/
	cin >> dd; 
	if (dd == d)
		cout << "Hurray!\n"; 
}/*This assumes that the addition operator, '+', has been declared for "Date"s*/
