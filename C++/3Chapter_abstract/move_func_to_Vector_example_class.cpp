#include <iostream>

/*This is adding the abilty to use move to move the data in "Vector a" to another vector*/

class Vector
{
	/*...*/
	Vector(const Vector& a);		/*copy constructor*/
	Vector& operator=(const Vector& a);	/*copy assignment*/

	Vector& operator=(Vector&& a);		/*move assignment*/
};

/*This means that "r=x+y+z" will involve no copying of "Vectors". Instead, "Vectors" are just moved. */


