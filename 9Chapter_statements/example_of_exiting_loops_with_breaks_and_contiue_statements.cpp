#include <string>
#include <iostream>
#include <list>
using namespace std; 

/*A "break" breaks out of the nearest enclosing switch statement or iteration statement. */
void f(vector<string>& v, string terminator)
{
	char c; 
	string s; 
	while (cin >> c)
	{
		/*...*/
		if (c == '\n')
			break; 
		/*...*/
	}
}/*We use a "break" when we need to leave the loop body in the middle. */

/*Sometimes you dont want to exit the loop completely, you just want to get to the end of the loop body. A "continue" skips the rest of the body of an iteration-statement.*/

void find_prime(vector<string>& v)
{
	for (int i = 0; i != v.size(); ++i)
	{
		if (!prime(v[i]))
			continue; 	/*it not a prime the iteration continues*/
		return v[i]
	}
}

/*This is a different way of to write the above statement*/

void find_prime(vector<string>& v)
{
	for (int i = 0; i != v.size(); ++i)
	{
		if (!prime(v[i]))
		{
			return v[i]; 
		}
	}
}
