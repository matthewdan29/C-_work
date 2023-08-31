#include <string>
#include <iostream>
#include <list>
using namespace std; 

/*When you use several constructors, member initialization can become repetitive. 
 * You can deal with that by introducing default arguments to reduce the number of constructors. 
 * Alternatively, you can add initializers to data members*/

class Date
{
	int d {today.d}; 
	int m {today.m}; 
	int y {today.y}; 
public: 
	Date(int, int, int); 			/*day, month, year*/
	Date(int, int); 			/*day, month, today's year*/
	Date(int); 				/*day, today's month and year*/
	Date(); 				/*default Date: today*/
	Date(); 				/*default Date: today*/
	Date(const char*); 		/*date in string representation*/
	/*...*/
};


/*NOW: you can do the two equivalent Date constructor initializtions.*/
Date::Date(int dd)
	:d{dd}
{
	/*check that the Date is valid*/
}

/*Also you can do */
Date::Date(int dd)
	:d{dd}, m{today.m}, y{today.y}
{
	/*check that Date is valid*/
}
