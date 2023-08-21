#include <string>
#include <list>
#include <iostream>
using namespace std; 

/*The notation "X&" means "reference to X". It is used for references to "Lvalues", so it is often called an "lvalue reference".*/

void f()
{
	int var = 1; 
	int& r{var};		/*'r' and "var" now refer to the same int*/
	int x = r; 		/*x becomes 1*/

	r = 2; 			/*var becomes 2*/
}

/*To ensure that a reference is a name for something, we must initialize the reference.*/

int var = 1; 
int& r1 {var};			/*OK: r1 initialized*/
int& r2; 			/*error: initializer missing*/
extern int& r3; 		/*OK: r3 initialized elsewhere*/


/*Initialization of a reference is something quite different from assignment to it. Despite appearance, no operator operates on a reference. example below*/

void g()
{
	int var = 0; 
	int& rr{var}; 
	++rr; 			/*var incremented to 1*/
	int* pp = &rr; 		/*pp points to var*/
}/*"++rr" does not increment the reference "rr"; rather, "++" is applied to the "int" to which "rr" refers, that is, to "var".*/

/*NOTE: a reference is not an object.*/
