#include <iostream>

void test(complex z1)
{
	complex z2{z1}	/*copy initialization*/
	complex z3; 
	z3 = z2; 	/*copy assignment*/
}

/*Now "z1", "z2" and "z3" have the same value because both the assigment and the initialization copied both members. */
