#include <string>
#include <iostream>
#include <list>
using namespace std; 

/*"plain" "enum" can be implicity converted to an integer and then to a "bool" whereas an "enum class" cannot*/

enum E1 {a, b}; 
enum class E2 {a,b}; 

void f(E1 x, E2 y)
{
	if (x)			/*OK*/
		/*...*/
	if (y) 			/*error: no conversion to bool*/
		/*...*/
	if (y == E2::a)		/*OK*/
		/*...*/
}/*Logical operator are most commonly used in condition. The operators "&&" and "||" will not evaluate their second argument unless doing so is necessary.*/
