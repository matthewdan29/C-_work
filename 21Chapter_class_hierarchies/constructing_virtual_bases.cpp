#include <string>
#include <list>
#include <iostream>
using namespace std; 

/*This method ensures that a virtual base is constructed exactly once even if it is mentioned in many places in the class hierarchy. example below.*/

struct V
{
	V(int i); 
	/*...*/
}; 

struct A
{
	A(); 					/*default constructor*/
	/*...*/
}; 

struct B : virtual V, virtual A
{
	B() :V{1}{/*...*/}; 		/*defaul constructor; must initialize base 'V'*/
	/*...*/
}; 

class C : virtual V 
{
public:
       C(int i) : V{i}{/*...*/}; 		/*must initialize base 'V'*/
	/*...*/       
}; 

class D : virtual public B, virtual public C 
{
	/*Implicity gets the virtual base 'V' from 'B' and 'C'*/
	/*implicitly get virtual base 'A' from 'B'*/
public: 
	D(int i, int j) : V{i}, C{j}{/*...*/}		/*OK*/
}; 
