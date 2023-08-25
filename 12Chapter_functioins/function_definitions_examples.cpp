#include <string>
#include <iostream>
#include <list>
using namespace std; 

/*A function definition is a function declaration in which the body of the function is presented.*/

void swap(int*, int*); 				/*a declaration*/

void swap(int* p, int* q)			/*a definition*/
{
	int t = *p; 
	*p = *q; 
	*q = t; 
}

/*To preserve 'C' compatibility, a "const" is ignored at the highest level of an argument type. This is two declarations of the same function*/

void f(int); 					/*type is void(int)*/
void f(const int); 				/*type is void(int)*/

/*function, f(), could be defined as*/
void f(int x) {/*we can modify x here*/}

/*Alternatively, we could define f() as below*/
void f(const int x){/*we cannot modify x here*/}

/*Function argument names are not part of the function type and need not be identical in different declarations.*/

int& max(int& a, int& b, int& c); 		/*return a reference to the larger of a, b, and c*/
int& max(int& x1, int& x2, int& x3)
{
	return (x1>x2)?((x1>x3) ? x1 : x3): ((x2 > x3) ? x2 : x3); 
}

/*Conversely, we can indicate that an argument is unused in a function definition by not naming it.*/
void search(table* t, const char* key, const char*)
{
	/*no use of the third argument*/
}

/*unnamed arguments arise from the simplification of code or from planning ahead for extensions. In both cases leavin the argument in place, although unused, that callers are not affected by the change */ /*Me: personlly i knew about this but I did not even think this was what it was for */
