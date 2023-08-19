#include <cmath>
#include <string>
#include <iostream>
#include <complex>
using namespace std; 

/*if you studied the calcutaions for FTT you know this type is important*/

template<typename Scalar>
class complex
{
public: 
	complex(const Scalar& re = {}, const Scalar& im ={}); 
	/*...*/
}; 

/*The ususal arithmetic operations and the most common mathemtical functions are supported for complex numbers.*/
void f(complex<float> fl, complex<double>db)
{
	complex<long double> ld{fl+squr(db)}; 
	db += fl*3; 
	fl = pow(1/fl,2); 
	/*...*/
}
/*The "sqrt()" and "pow()" functions are among the usual mathematical functions defined in "<comple>" library*/
