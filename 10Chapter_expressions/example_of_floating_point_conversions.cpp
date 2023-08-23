#include <cmath>
#include <string>
#include <iostream>
using namespace std; 

/*A floating-point value can be converted to another floating-point type.*/
/*If the source value is between two adjacent destination values, the result is on of those values.*/

float f = FLT_MAx; 			/*large float value*/
double d = f; 				/*OK: d==f*/
double d2 = DBL_MAX; 			/*largest double value*/
float f2 = d2; 				/*undefined if FLT_MAX<DBL_MAX*/

long double ld = d2; 			/*OK:ld =d2*/
long double ld2 = numeric_limits<long double>::max(); 
double d3 = ld2; 
