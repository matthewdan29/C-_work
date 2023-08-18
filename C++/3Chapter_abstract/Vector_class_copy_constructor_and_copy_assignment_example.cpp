#include <iostream>

/*Copy of an object of a class is defined by two members: a copy constructor and a copy assignment.*/

class Vectory 
{
private: 
	double* elem;	/*elem points to an array of sz doubles*/
	int sz; 
public: 
	Vector(int s); 
	~Vector()	/*This is the delete constructor*/
	{
		delete[] elem; 
	}

	double& operator[] (int i);
	const double& operator[](int i) const; 

	int size() const; 
}; 

/*Copy constructor for "Vector" allocates the space for the required number of elements and then copies the elements into it, so that after a copy each "Vector" has its own copy of elements:*/

Vectory::Vector(const Vector& a)	/*copy constructor*/
	:elem{new double[sz]},		/*allocate space for elements*/
	sz[a.sz]
{
	for (int i = 0; i != sz; ++i)	/*copy elements*/
		elem[i] = a.elem[i]; 
}

/*Next copy assignment in addition to the copy constructor*/
Vertor& Vector::operator=(const Vector& a)	/*copy assignment*/
{
	double* p = new double[a.sz]; 
	for (int i = 0; i != a.sz; ++i)
		p[i] = a.elem[i]; 
	delete[] elem;		/*delete old elements*/
	elem = p; 
	sz = a.sz; 
	return *this; 
}

