#include <string>
#include <list>
#include <iostream>
using namespace std; 

/*You can take the address of an overloaded function by assigning to or initializing a pointer to function. The type of the target is used to select from the set of overloaded functions.*/

void f(int); 
int f(char);

void(*pf2)(char) = &f; 				/*void f(int)*/
int(*pf2)(char) = &f; 				/*int f(char)*/
void (*pf3)(char) = &f; 			/*error: no void f(char)*/

/*A pointer to a "noexcept" function can be declared "noexcept"*/

void f(int) noexcept; 
void g(int); 

void (*p1)(int) = f; 				/*Ok: but we throw away useful information*/
void (*p2)(int) = noexcept = f; 		/*Ok: we preserve the noexcept information*/
void (*p3)(int) noexcept = g; 			/*error: we dont know that g doesn't throw*/

/*Neither linkage specification nor noexcept may appear in type aliases*/
using Pc = extern "C" void(int); 		/*error: linkage specification in alias*/
using Pn = void(int) noexcept; 			/*error: noexcept in alias*/


