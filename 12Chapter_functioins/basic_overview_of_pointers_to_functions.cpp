#include <string>
#include <iostream>
#include <list>
#include <threads>
using namespace std; 

/*Derferencing a pointer to function using '*' is optional. Using '&' to get the address of a function is optional: */

void (*f1)(string) = &error; 			/*Ok: same as = error*/
void (*f2)(string) = error; 			/*Ok: same as = &error*/

void g()
{
	f1("Vasa"); 				/*Ok: same as (*f1)("Vasa")*/
	(*f1)("Mary Rose"); 			/*Ok: as f1("Mary Rose")*/
}

/*Pointers to functions have arguments types declared just like functions themselves. In pointer assignments, the complete function type must match exactly. as below*/

void (*pf)(string);				/*pointer to void(string)*/
void f1(string); 				/*void(string)*/
int f2(string); 				/*int(string)*/
void f3(int*); 					/*void(int*)*/

void f()
{
	pf = &f1; 				/*Ok*/
	pf = &f2; 				/*error: bad return type*/
	pf = &f3; 				/*error: bad argument type*/

	pf("Here"); 				/*OK*/
	pf(1); 					/*error: bad argument type*/

	int i = pf("Zeus"); 			/*error: void assigned to int*/
}/*The rules for argument passing are the same for calls directly to a function and for calls to a function through a pointer.*/

/*You can convert a pointer to function to a different pointer-to-function type, but you must cast the ressulting pointer back to its orginal type or strange things may happen: like below*/
using P1 = int(*)(int*); 
using p2 = void(*)(void); 

void f(P1 pf)
{
	P2 pf2 = reinterpret_cast<P2>(pf)	
	pf2(); 					/*likely serious problem*/
	P1 pf1 = reinterpret_cast<P1>(pf2); 	/*convert pf2 "back again"*/
	int x = 7; 
	int y = pf1(&x); 			/*Ok*/
	/*...*/
}/*We need the nastiest of cast, "reinterpret_cast, to do conversion of pointer-to-function" types. The reason is that the result of using a pointer to function of the wrong type is so unpredictable and system-depentdent. The call function may write to the object pointed to by its argument, but the call "pf2()" didn't supply any argument!*/
