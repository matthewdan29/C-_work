#include <iostream>

/*You can control copying by defining a copy constructor and a copy assignment, but copying can be costly for large container.*/
/*This function copies "Vector& a" to "Verctor b"*/

Vector operator+(const Vector& a, const Vector& b)
{
	if (a.size() != b.size())
		throw Vector_size_mismatch{}; 
	Vector res(a.size()); 
	for (int i = 0; i != a.size(); ++i)
		res[i] = a[i] + b[i]; 
	return res; 
}
