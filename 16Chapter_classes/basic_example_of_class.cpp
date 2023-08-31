#include <iostream>
#include <list>
#include <string>
using namespace std; 

/*below is a example of basic class*/

class X 
{
private: 			/*the representation is private*/
	int m; 		
public: 			/*the user interface is public*/
	X(int i = 0) :m{i}{ }	/*a constructor (initialize the data memeber)*/

	int mf(int i)		/*a member function*/
	{
		int old = m; 
		m = i;		/*set a new value*/
		return old; 	/*return the old value*/
	}
}; 

X var {7}; 			/*a variable of type X, initialized to 7*/

int user(X var, X* ptr)
{
	int x = var.mf(7); 	/*access using .(dot)*/
	int y = ptr->mf(9); 	/*access using ->(arrow)*/
	/*int z = var.m;*/	/*error: cannot access private member*/ 
}
