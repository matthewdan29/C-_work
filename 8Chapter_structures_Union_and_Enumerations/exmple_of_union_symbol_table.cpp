#include <string>
#include <iostream>
#include <list>
using namespace std; 

enum Type {str, num}; 

struct Entry 
{
	char* name; 
	Type t; 
	char* s; 		/*use s if t==str*/
	int i; 			/*use i if t==num*/
}; 


void f(Entry* p)
{
	if (p->t == str)
		cout << p->s; 
	/*...*/
}

/*It can be easily recovered by specifying that both should be member of a "union:*/

union Value
{
	char* s; 
	int i; 
}; 

/*The language doesn't keep track of which kind of value is held by a "union", so the programmer must do that: */

struct Entry
{
	char* name; 
	Type t; 
	Value v;		/*use v.s if t==str; use v.i if t==num*/
}; 

void f(Entry* p)
{
	if (p->t == str)
		cout << p->v.s; 
	/*...*/
}/*To avoid error, and can encapsulate a "union" so that the correspondence between a type fielf and access to the "union" members can be guaranteed.*/


