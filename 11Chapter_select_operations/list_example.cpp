#include <string>
#include <iostream>
#include <list>
using namespace std; 

/*The rules constructing an object using a qualified list are those of direct */
/*One way of looking at a qualified initializer list with one element is as conversion from one type to another. */

template<class T>
T square(T x)
{
	return x*x; 
}

void f(int i)
{
	double d = square(double{i}); 
	complex<double> z = square(complex<double>{i}); 
}
