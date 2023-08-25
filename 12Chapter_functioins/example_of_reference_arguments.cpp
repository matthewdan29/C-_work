#include <list>
#include <string>
#include <iostream>
using namespace std; 

/*it can, be noticably more efficient to pass a large object by reference than to pass it by value. In that case, the argument might be declared a "const" reference to indicate that the reference is used for efficiency reasons only and not to enable the called function to change the value of the object: */

void f(const Large& arg)
{
	/*the value of "arg" cannot be changed*/
	/*(except by using explicit type conversion; )*/
}

/*The absence of const in the declaration of a reference argument is taken as a statement of intent to modify the variable*/
	void g(Large& arg); 			/*assume that g() modifies arg*/

/*Declaring a pointer argument "const" tells readers that the value of an object pointed to by that argument is not changed by the function.*/

int strlen(const char*); 			/*number of character in a C-style string*/
char* strcpy(char* to, const char* from); 	/*copy a C-style string*/
int strcmp(const char*, const char*); 		/*compare C-style strings*/
/*The importance of using "const" arguments increases with the size of a program. */



