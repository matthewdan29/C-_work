#include <string>
#include <list>
#include <iostream>
using namespace std; 

/*This is a define representaion of a "Date" and a set of functions for manipulating variables of this type.*/

struct Date					/*representation*/
{
	int d; 
	int m; 
	int y; 
}; 


void int_date(Date& d, int, int, int); 			/*initialize d*/
void add_year(Date& d, int n); 				/*add 'n' years to d*/
void add_month(Date& d, int n); 			/*add 'n' months to d*/
void add_day(Date& d int n); 				/*add 'n' days to d*/

/*There is no explicit connection between the data type, "Date", and these functions. Such a connection can be established by declaring the function as members*/

struct Date
{
	int d; 
	int m; 
	int y; 

	void intit(int dd, int mm, int yy); 		/*initialize*/
	void add_year(int n); 				/*add 'n' years*/
	void add_month(int n); 				/*add 'n' months*/
	void add_day(int n); 				/*add 'n' days*/
}; 

/*Functions declared with in a class definition are called "member functions" and can be invoked only for specific variable of the appropraiate type using the standard syntax for structure member: example below:*/

Date my_birthday; 

void f()
{
	Date today; 

	today.init(16, 10, 1996); 
	my_birthday.init(30, 12, 1950); //Not: matthews bday 
	
	Date tomorrow = today; 
	tomorrow.add_day(1); 
	/*...*/
}

/*Because different structures can have member functions with the same name, you must specify the structure name when defining a member function: example below*/
void Date::init(int dd, int mm, int yy)
{
	d = dd; 
	m = mm; 
	y = yy; 
}/*member functions names can be used without explicit reference to an object.*/

/*for example "Date::init()" i sinvoked for "today", "m=mm" assigns "today.m"*/
/*On the other hand, when "Date::init()" is invoked for "my_birthday", "m=mm" assigns to "my_birthday.m"*/
