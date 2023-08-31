#include <string>
#include <list>
#include <iostream>
using namespace std; 

/*making "init" public with data you want to add to a class is critical for the concept of "OOP"*/

/*The declaration of "Date" in the previous file provides a set of functions for manipulating a "Date". It does not specify that those functions shouldbe the only ones to depend directly on "Date" representation and the only ones to directly access object of class "Date". This restriction can be expressed by using a "class" instead of a struct*/

class Date
{
	int d; 
	int m; 
	int y; 
public: 
	void init(int dd, int mm, int yy); 		/*initialize*/

	void add_years(int n); 				/*add 'n' years*/
	void add_month(int n); 				/*add 'n' months*/
	void add_day(int n); 				/*add 'n' days*/
}; 

/*The "public" label separates the class body int two parts. The names in the first, private, part can be used only by member functions. The second, public, part constitutes the public interface to objects of the class. A "struct" is simply a "class" whos members are public by default; member functions can be defined and used exactly as before.*/

void Date::add_year(int n)
{
	y += n; 
}
