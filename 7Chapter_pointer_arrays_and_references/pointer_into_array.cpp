#include <string>
#include <list>
#include <iostream>
#include <cmath>	/*again you dont need this */
using namespace std; 

/*The name of an array can be used as a pointer to its initial element.*/

int v[] = {1,2,3,4}; 
int* p1 = v;			/*pointer initial element(implicit conversion)*/
int* p2 = &v[0];		/*pointer to initial element*/
int* p3 = v+4;			/*pointer to one beyond last element*/

/*The result of taking the address of the element before the initial element or beyond one-past-the-last element is undefined and should be avoided.*/

int* p4 = v-1;		/*befor the beginning, undefined: dont do it*/
int* p5 = v+7;		/*beyond the end, undefined: dont do it*/

/*The implicit conversion of an array name to a pointer to the initial element of the array is extensively used in fuction calls in C-style code. */

extern "C" int strlen(const char*);		/*from <string.h>*/

void f()
{
	char v[] = "Annemarie";
	char* p = v;			/*implicit conversion of char[] to char**/
	strlen(p);
	strlen(v);			/*implicit conversion of char[] to char**/
	strlen(v);			/*implicit conversion of char[] to char**/
	v = p;				/*error cannont assign to array*/
}
/*The same value is passed to the standard-library function "strlen()" in both calls. The snag is that it is impossible to avoid the implicit conversion.*/
