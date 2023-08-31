/*This is more review I do not need to create this file*/
#include <string>
#include <list>
#include <iostream>
using namespace std; 

/*A variable that is part of a class, yet is not part of an object of the class is called static member. There is exactly one copy of a "static" member instead of one copy per object, as for ordinary non-static memebers.*/
/*Here is a redesign that prevers the semantics of default constructor values for "Date" without the problems stemming from reliance on a global.*/

class Date 
{
	int d; 
	int m; 
	int y; 
	static Date default_date; 
public: 
	Date(int dd = 0, int mm = 0, int yy = 0); 
	/*...*/
	static void set_default(int dd, int mm, int yy); 	/*set default_sdate to Date(dd,mm,yy)*/
}; 

/*You can now define the "Date" constructor to use "defaule_date" like below*/
Date::Date(int dd, int mm, int yy)
{
	d = dd ? dd : default_date.d; 
	m = mm ? mm : default_date.m; 
	y = yy ? yy : default_date.y; 

	/*...check that Date is valid...*/
}/*Using "set_default()" you can change the defualt date when appropriate.*/

/*A "static" member can be referred to without mentioning an object. Its name is qualified by the name of its class. example below*/

void f()
{
	Date::set_default(4, 5, 1945); 			/*Call Date's static member "set_default()"*/
}; 

/*The keyword "static" is not repreated in the fefinition of a "static" member.*/

Date Date::default_date{16, 12, 1770}		/*definition of Date::default_date*/

void Date::set_default(int d, int m, int y)	/*definition of Date::set_default*/
{
	default_date = {d,m,y}; 		/*assign new value to default_date*/
}

/*Note that "Date{}" servers as a notation for the value of "Date::default_date"*/

Date copy_of_default_date = Date{}; 

void f(Date); 

void g()
{
	f(Date{})
}
