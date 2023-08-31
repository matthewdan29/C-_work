/*First off I know thats a long name for a file*/
#include <string>
#include <list>
#include <iostream>
using namespace std; 

/*A class has a number of functions asociated with it that need not be defined in the class itself because they don't need direct access to the representation. example below*/

int diff(Date a, Date b); 		/*Number of days in the range [a,b) or [b,a)*/

bool is_leapyear(int y); 
bool is_date(int d, Month m, int y); 

const Date& default_date(); 
Date next_weekday(Date d); 
Date next_saturday(Date d); 
/*Defining such functions above in the class itself would complicate the class API and increase the number of functions that would potentially need to be examined when a change to the representation was considered.*/

/*Although, you can make the association explicit by enclosing the class and its helper functions in a namespace.*/

namespace Chrono		/*facilities for dealing with time*/
{
	class Date {/*...*/}; 

	int diff(Date a, Date b); 
	bool is_leapyear(int y); 
	bool is_date(int d, Month m, int y); 
	const Date& default_date(); 
	Date next_weekday(Date d); 
	Date next_saturday(Date d); 
	/*...*/
}/*The "Chrono" namespace would naturally also contain related classes, such as "Time" and "Stopwatch", and thier helper functions. Using a namespace to hold a single class is usually an overlaboration that leads to inconvenience.*/
