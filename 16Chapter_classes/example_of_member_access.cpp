#include <string>
#include <list>
#include <iostream>
using namespace std; 

/*A member of a class 'X' can be accessed by applying the .(dot) operator to an object of class 'X' or by applyin the "->" (arrow) operator to a pointer to an object of class 'X', examples below*/

struct X
{
	void f(); 
	int m; 
}; 

void user(X x, X* px)
{
	m = 1; 				/*error: there is no 'm' in scope*/
	x.m = 1; 			/*OK*/
	x->m = 1; 			/*error: 'x' is not a pointer*/
	px->m = 1; 			/*OK*/
	px.m = 1; 			/*error: px is a pointer*/
}; 

/*From inside a class no operator is needed. example below*/
void X::f()
{
	m = 1; 				/*OK: "this->m = 1"*/
};


/*If you want to refer to a member in general, rather than to a member of a particular object, you qualify by the class name follwed by "::" example below*/

struct S
{
	int m; 
	int f(); 
	static int sm; 
}; 

int X::f(){return m; }				/*X's f*/
int X::sm {7}; 					/*X's static member sm*/
int(S::*)pmf(){&S::f}; 				/*X's member f*/

/*The last construct (a pointer to member) is fairly rare and esotric. It's to emphasize the generality of the rule for "::"*/
