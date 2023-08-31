#include <string>
#include <iostream>
#include <list>
using namespace std; 

/*A constructor declared with the keyword "explicit" can only be used for initialization and explicit conversion.*/

class Date
{
	int d; 
	int m; 
	int y; 
public: 
	explicit Date(int dd = 0, int mm = 0, int yy = 0); 
	/*...*/
}; 

Date d1{15}; 			/*OK: considered explicit*/
Date d2 = Date{15}; 		/*OK: explicit*/

void f()
{
	my_fact(15); 		/*error: arguments passing */
	my_fct({15}); 		/*error: argument passing */
	my_fct(Date{15}); 	/*OK: explicit*/
	/*...*/
}
