#include <string>
#include <iostream>
#include <list>
using namespace std; 

/*I wouldn't do this but I also can't find the bug for the calc on the file before this */

/*This is putting 2 strings in a temp holder*/

void f(string& s1, string& s2, string& s3)
{
	const char* cs = (s1+s2).c_str(); 
	cout << cs; 
	if(strlen(cs=(s2+s3).c_str())<8&&cs[0]=='a')
	{
		/*cs used here*/
	}
}

/*A temporary can be used as an initializer for a const reference or a named object. */

void g(const string&, const string&); 
{
	const string& s = s1+s2; 
	string ss = s1+s2; 

	g(s,ss); 		/*we can use ss here*/
}

/*A temporary object can also be created explicity in an expression by invoking a constructor. */

void f(Shape& s, int n, char ch)
{
	s.move(string{n,ch}); 		/*construct a string with n copies of ch to pass to Shape::move()*/
	/*...*/
}
