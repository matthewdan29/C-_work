#include <string>
#include <list>
#include <iostream>
using namespace std; 

/*In addition to using a lambda as an argument, we can use it to initialize a variable declared "auto" or "std::function<R(AL)>" where 'R' is the lambda's return type and "AL" is its argument list of types.*/

/*I might try to write a lambda to reverse the character in a C-style string: */

auto rev = [&rev](char* b, char* e)
{if (1<e-b){swap(*b, *-e); rev(++b,e); }}; 	/*error*/


/*However, that's not possible because I cannot use "auto" variable before its type has been deduced. 
 * Instead, I can introduce a name and then use it: look below*/

void f(string& s1, string& s2)
{
	function<void(char* b, char* e)> rev= [&](char* b, char* e){if (1<e-b){swap(*b, *--e); rev(++b,e); }}; 

	rev(&s1[0], &s1.size()); 
	rev(&s2[0], &s2[0]+s2.size()); 
}

/*Now, the type of "rev" is specified before it is used. 
 * If we just want to name a lambda, rather than using it recursively, "auto" can simplify thing: */

void g(vector<string>& vs1, vector<string>& vs2)
{
	auto rev= [&](char* b, char* e){while(1<e-b)swap(*b++, *--e); }; 

	rev(&s1[0], &s1[0]+s1.size()); 
	rev(&s2[0], &s2[0]+s2.size()); 
}

/*A lambda that captures nothing can be assigned to a pointer to function of an appropriate type. */

double(*p1)(double) = [](double a){return sqrt(a); }; 
double(*p2)(double) = [&](double a){return sqrt(a); }; /*error: the lambda captures*/
double(*p3)(int) = [](int a){return sqrt(a); }; 	/*error: argument types do not match*/
