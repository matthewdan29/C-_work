#include <string>
#include <list>
#include <iostream>
using namespace std; 

/*You can also use the access specifier "private:" to say that the members follwing are private, just as "public:" says that the members following are public*/

struct Date2
{
private: 
	int d; 
	int m; 
	int y; 
public: 
	Date2(int dd, int mm, int yy); 
	void add_year(int n); 			/*add 'n' years*/
}; 

/*it often makes sense to place data members last to emphasize the functions providing the public user interface.*/

/*It is not a requirement to declare data first in a class. It ofthen makes sense to place data members last to emphasize the functions providing the public user interface.*/

class Date3
{
public: 
	Date3(int dd, int mm, int yy); 
	void add_year(int n); 			/*add 'n' years*/
private: 
	int d; 
	int m;
	int y; 
}; 

/*To access specifier can be used many times in a single class declaration. For example:*/

class Date4
{
public: 
	Date4(int dd, int mm, int yy); 
private: 
	int d; 
	int m; 
	int y; 
public: 
	void add_year(int n); 			/*add 'n' year*/
}; /*Having more than one public section, as in "Date4", tends to be messy, though, and might affect the object layout. So does having more than one private sectionl.*/
