#include <iostream>

using namespace std;		/* make names from std visible without std::*/

double square(double x)		/* square a double precision floating-pont number*/
{
	return x*x; 
}

void print_square(double x)
{
	cout<<"The square of " << x << " is " << square(x)<<"\n"; 
}

int main()
{
	print_square(1.234); 		/* print: the square of 1.234 is 1.52276*/
}
