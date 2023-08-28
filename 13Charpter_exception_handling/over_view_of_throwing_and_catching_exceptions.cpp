#include <list>
#include <iostream>
#include <string>
using namespace std; 

/*You can "throw" an excepting of any type that can be copied or moved.*/
class No_copy
{
	No_copy(const No_copy&) = delete; 		/*prohibit copying*/
}; 

class My_error
{
	/*...*/
}; 

void f(int n)
{
	switch(n)
	{
		case 0: 	throw My_error{}; 		/*OK*/
		case 1: 	throw No_copy{}; 		/*error: cant copy a No_copy*/
		case 2: 	throw My_error; 		/*error: My_error is a type, rather than an object*/

	}
}

/*The process of passing the exception "up the stack" from the point of throw to a hadler is called "stack unwinding"*/

/*In each scope exited, the destructors are invoked so that every fully constructed object is properly destroyed.*/
void f()
{
	string name{"Matt"}; 
	try
	{
		string s = "in"; 
		g(); 
	}
	catch(My_error)
	{
		/*...*/
	}
}

void g()
{
	string s = "excess"; 
	{
		string s = "or"; 
		h(); 
	}
}

void h()
{
	string s = "not"; 
	throw My_error{}; 
	string s2 = "at all"; 
}/*After the throw in "h()", all the strings that were constructed are destroyed in the reverse order of their construction: "not", "or", "excess", "in", but not "at all", which the thread of control never reached and not "Matt", which was unaffected.*/
