#include <string>
#include <iostream>
#include <list>
using namespace std; 

/*If a lambda body does not have a return-statement, the lambda returns a "void". If a lambda body consists of just a single "return"-statement, the lambda's return type is the type of the return's expression. If neither is the case, we have to explicitly supply a return type. */

void g(double y)
{
	[&]{f(y); }				/*return type is void*/
	auto z1 = [=](int x){return x+y; }	/*return type is double*/
	auto z2 = [=,y]{if (y) return 1; else return 2; }	/*error: body to complicated*/

	auto z3 = [y](){return 1 : 2; }		/*return type is int*/
	auto z4 = [=,y]()->int {if (y) return 1; else return 2; }	/*OK: explicit return type*/
}/*When the suffix return type notation is used, we cannont omit the argument list. */
