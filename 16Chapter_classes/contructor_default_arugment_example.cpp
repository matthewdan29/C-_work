#include <string>
#include <list>
#include <iostream>
using namespace std; 

/*The proliferation of constructors in the "Date" is typical. When designing a class a programmer is always tempted to add features just because somebody might want them. 
 * It takes more thought to carefully decide whatfeatures are really needed and to include only those. 
 * That extra thought typically leads to smaller and more comprehensible programs.
 * One way of reducing the number of related functions is to use default arguments.
 * Each argument can be given a default value interpreted as "pick the default:"today"".*/

class Date
{
	int d; 
	int m; 
	int y; 
public: 
	Date(int dd = 0, int mm = 0; int yy = 0); 	/*The constructor*/
	/*...*/
	Date(int, int, int); 			/*day, month, todaysyear*/
	Date(int, int); 				/*day, todays's month*/
	Date(); 					/*default Date: today*/
	Date(const char*); 		/*date in string representation*/
}; 

Date::Date(int dd, int mm, int yy)
{
	d = dd ? dd : today.d; 
	m = mm ? mm : today.m; 
	y = yy ? yy : today.y; 

	/*check that the Date is valid*/
}
