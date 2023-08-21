#include <string>
#include <iostream>
#include <list>
using namespace std; 

/*To declare a pointer itself, rather than the object pointed to, to be constant, we use the declarator operator "*const" instead of plain '*'.*/

void f1(char* p)
{
	char s[] = "Gorm"; 

	const char* pc = s;		/*pointer to constant*/
	pc[3] = 'g'; 			/*error: pc points to constant*/
	pc = p; 			/*OK*/

	char *const cp = s;		/*constant pointer*/
	cp[3] = 'a'; 			/*ok*/
	cp = p;				/*error: cp is constant*/

	const char *const cpc = s; 	/*const pointer to const*/
	cpc[3] = 'a'; 			/*error: cpc points to constant*/
	cpc = p; 			/*error: cpc is constant*/
}


/*The declarator operator that makes a pointer constant is "*const". There is no "const*" declarator operator, so a "const" appearing befor the '*' is taken to be part of the base type. */

char *const cp; 			/*const pointer to char*/
char const* pc; 			/*pointer to const char*/
const char* pc2;			/*pointer to const char*/

/*"cp" is a "const" pointer to a "char" and "pc2" is a pointer to a "char const".*/


/*By declaring a pointer argument "const", the function is prohibited from modifying the object pointed to.*/

const char* strchr(const char* p, char c);		/*fid first occurrence of 'c' in 'p'*/
char* strchr(char* p, char c);				/*find first occurrence of 'c' in 'p'*/
