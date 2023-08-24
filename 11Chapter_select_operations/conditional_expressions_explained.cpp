#include <string>
#include <iostream>
#include <list>

/*Some "if"-statements can conveniently be replaced by conditional-expressions.*/

if (a <= b)
	max = b; 
	else
		max = a; 

/*This is more directly expressed like this: below*/
	max = (a <= b) ? b : a; 

/*The parentheses around the condition are not necessary, but I found the code to read when they are used. */

/*In addition, one branch maybe a "throw"-expression. */
void fct(int* p)
{
	int i = (p) ? *p : std::runtime_error{"unexpected nullptr"}; 
	/*...*/
}
