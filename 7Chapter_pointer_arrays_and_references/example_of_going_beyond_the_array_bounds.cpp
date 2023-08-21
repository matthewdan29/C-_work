#include <list>
#include <iostream>
#include <threads>
#include <string>
/*#include <array>*/
using namespace std; 

/*you get a pointer value in a array if you subtrack or add to the pointer*/
/*If that value does not point to an element of the same array as the orgiginal pointer or one beyond, the result of using that calue is undefined */

void f()
{
	int v1[10]; 
	int v2[10]; 

	int i1 = &v1[5] - &v1[3];		/*i1 = 2*/
	int i2 = &v1[5] - &v2[3]; 		/*result undefined*/

	int* p1 = v2+2; 			/*p1 = &v2[2]*/
	int* p2 = v2-2; 			/* *p2 undefined*/
}
/*complicated pointer arithmetic is best avoided.*/

/*Arrays are not self-describing because the number of elements of an array is not guaranteed to be stored with the array. This implies that to traverse an array that does not contain a terminator the way C-style string do, you must somehow supply the number of elements.*/

void fp(char v[], int size)
{
	for (int i = 0; i != size; ++i)
		use(v[i]);			/*hope that 'v' has at least size elements*/

	for (int x: v)
		use(x);				/*error: range-for does not work for pointers*/

	const int N = 7; 
	char v2[N]; 
	for (int i = 0; i!= N; ++i)
		use(v2[i]); 
	for (int x : v2)
		use(x);				/*range-for works for arrays of known size */
}
