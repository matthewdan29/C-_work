#include <string>
#include <list>
#include <iostream>
using namespace std; 

/*Lambd expressions can be implemented in a variety of ways, and there are some rather effective ways of optimizing them. I find it useful to understand the semantics of a lambda by considering it a shorthand for defining and using a function object. Consider example below.*/

void print_modulo(const vector<int>& v, ostream& os, int m)
	/*output v[i] to os if v[i]%m==0*/
{
	for_each(begin(v), end(v), [&os, m](int x) {if (x%m==0) os << x << '\n';}); 
}

/*To see what this means you can define the equivalent function object */

class Modulo_print
{
	ostream& os; 			/*members to hold the capture list*/
	int m; 

public: 
	Modulo_print(ostream& s, int mm) :os(s), m(mm) {}	/*capture*/
	void operator()(int x) const
	{if (x%m==0) os << x << '\n'; }
}; 



/*An object of a class generated from a lambda is called a closure object. you can now write the original function like below */
void print_modulo(const vector<int>& v, ostream& os, int m)
	/*output v[i] to os if v[i]%m==0*/
{
	for_each(begin(v), end(v), Modulo_prints{os,m}); 
}
