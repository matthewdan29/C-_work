/*The intent of the "ODR" is to allow inclusion of a class definition in different translation units from a common source file.*/

/*s.h:*/
	struct S {int a; char b; }; 
	void f(S*); 

/*file1.cpp:*/
	#include "s.h"
	/*use "f()" here*/

/*file2.cpp*/
	#include "s.h"
	void f(S* p){/*...*/}

/**/
