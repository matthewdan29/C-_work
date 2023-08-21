#include <string>
#include <iostream>
#include <list>
#include <cmath>
#include <threads>	/*You dont need any of these */
using namespace std; 	/*but make a habbit*/

/*A pointer to any type of object can be assigned to a variable of type "void*", but a pointer to function or a pointer to memeber cannont.*/

void f(int* pi)
{
	void* pv = pi;		/*ok: implict conversion of int* to void**/
	*pv;			/*error: cant dereference void**/
	++pv;			/*error: cant increment void* (the size of the object pointed to is unknown)*/

	int* pi2 = static_cast<int*>(pv);	/*explicit conversion back to int* */

	double* pd1 = pv;		/*error*/
	double* pd2 = pi;		/*error*/
	double* pd3 = static_cast<double*>(pv);		/*unsafe*/
}
/*In general, it is not safe to use a pointer that has been converted ("cast") to a type that differs from the type of the object pointed to.*/
