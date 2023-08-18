#include <iostream>

bool operator==(complex a, complex b)		/*equal*/
{
	return a.real()==b.real() && a.imag()==b.imag();
}

bool operator!=(complex a, complex b)		/*not equal*/
{
	return !(a==b); 
}

complex sqrt(complex); 

/*exaple of how you would use complex*/

void f(complex z)
{
	complex a {2.3}; 	/*construct {2.3, 0.0} from 2.3*/
	complex b {1/a}; 
	complex c {a+z*complex{1,2.3}}
	/*its a example it should not be used*/

	if (c != b)
		c =-(b/a)+2*b;
}
