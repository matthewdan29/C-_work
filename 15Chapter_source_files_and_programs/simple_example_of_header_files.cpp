#include <string>
#include <iostream>
#include <list>
using namespace std; 

/*You keep "inline" function definitions consistent by using header files.*/

/*h.h:*/
inline int next(int i) {return i+1;}

/*file1.cpp*/
#include "h.h" 				/*you have to put this at the top of each file in the "package"*/
int h(int i)	{return next(i); }		/*fine*/

/*file2.cpp:*/
#include "h.h"
/*...*/


/*By, default, "const" objects, "constexpr" objects, types aliases, and anything declared "static" in a namespace scope have internal linkage. This example is legal below*/

/*file1.cpp:*/
using T = int; 
const int x = 7; 
constexpr T c2 = x+1; 

/*file2.cpp*/
using T = double; 
const int x = 8; 
constexpr T c2 = x+9; 
/*To ensure consistency, place aliases, "const", "constexpr" and inline in headers files. */

/*A "const" can be given external linkage by an explicit declaration:*/
/*file1.cpp: */
extern const int a = 77; 

/*file2.cpp: */
extern const int a; 

void g()
{
	cout << a << '\n'; 
}/*Here, "g()" will print 77*/
