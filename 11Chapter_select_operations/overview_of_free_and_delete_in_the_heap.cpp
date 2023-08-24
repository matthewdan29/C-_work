#include <string>
#include <iostream>
#include <list>
#include <vector>
using namespace std; 

/*Consider how you might write a compiler in the style used for the desk calculator. The syntax analysis functions might build a tree of the expressions for use by the code generator.*/

struct Encode {
	Token_value oper;
	Enode* left; 
	Enode* right; 
	/*...*/
}; 

Enode* expr(bool get)
{
	Enode* left = term(get); 

	for(;;){
		switch(ts.current().kind){
			case Kind::plus: 
			case Kind::minus:
				left = new Enode{ts.current().kind,left,term(true)}; 
				break; 
			default: 
				return left; 
		}
	}
}/*In case "Kind::plus" and "Kind::minus", a new "Enode" is created on the free store and initialized by the value {ts.current().kind,left,term(true)}. The resulting pointer is assigned to "left" and eventually returned from "expr()". */

/*If a type has a default constructor, we can leave out the initializer, but built-in types by default uninitialized.*/
auto pc = new complex<double>; 		/*the complex is initialized to {0,0}*/
auto pi = new int; 			/*the int is uninitialized*/

/*To be sure to get default initialization, use "{}" */
auto pc = new complex<double>{}; 	/*the complex is initialized to {0,0}*/
auto pi = new int{}; 			/*the int is initialized to 0*/


/*A code generator could use the "Enode"s created by "expr()" and delete them*/
void generate(Enode* n)
{
	switch (n->oper)
	{
		case Kind::plus: 
			/*use n*/
			delete n; 		/*delete an Enode from the free store*/
	}
}/*An object created by "new" exists until it is explicitly destroyed by "delete". The space it occupied can be reused by "new". */
