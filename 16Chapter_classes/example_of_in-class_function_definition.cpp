#include <string>
#include <iostream>
#include <list>
using namespace std; 

/*A member function defined within the class definition is taken to be a inline member functioin.*/
/*A member can refer to another member of its class independently of where that member is defined.*/
/*That is, function and data member declarations are order independent.*/

class Date
{
public: 
	void add_month(int n){m+=n; }		/*increment the Date's 'm'*/
	/*...*/
private: 
	int d; 
	int m; 
	int y; 
}; 

inline void Date::add_month(int n)		/*add 'n' months*/
{
	m+=n; 					/*increment the Date's 'm'*/
}/*This latter style is often used to keep class definitions simple and easy to  read.*/
