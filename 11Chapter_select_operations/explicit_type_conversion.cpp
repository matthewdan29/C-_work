#include <string>
#include <list>
#include <iostream>
using namespace std; 

double d = 1234567890;				/*integer to floatin-point*/
int i = d; 					/*floating-point to integer*/

/*in other cases, we have to be explicit.*/

/*For converstion between two scalar numeric types, Bjarne Stroustrup tend to use a homemade explicit conversion function, "narrow_cast", where a value might ne barrowed: */

template<class Target, class Source>
Target narrow_cast(Source v)
{
	auto r = static_cast<Target>(v); 		/*convert the value to the target type*/
	if (static_cast<Source>(r)!=v)
		throw runtime_error("narow_cast<>()failed"); 
	return r; 
}/*That is, if Bjarne Stroustrup can convert a value to the target type, convert the result back to the source type, and get back the original value hes happy with the result.*/
/*That is a generalization of the rule the language applies to values in "{}" initialization. example below*/

void test(double d, int i, char* p)
{
	auto c1 = narrow_cast<char>(64); 
	auto c2 = narrow_cast<char>(-64); 		/*will throw if chars are unsigned*/
	auto c3 = narrow_cast<char>(264); 		/*will throw if chars are 8-bit and signed*/

	auto d1 = narrow_cast<double>(1/3.0F); 		/*OK*/
	auto f1 = narrow_cast<float>(1/3.0); 		/*will probably throw*/
	
	auto c4 = narrow_cast<char>(i); 		/*may throw*/
	auto f2 = narrow_cast<float>(d); 		/*may throw*/

	auto p1 = narrow_cast<char*>(i); 		/*compile-time error*/
	auto i1 = narrow_cast<int>(p); 			/*compile-time error*/

	auto d2 = narrow_cast<double>(i); 		/*may throw (but probably will not)*/
	auto i2 = narrow_cast<int>(d); 			/*may throw*/
}/*Depending on your use of floating-point numbers, it may be worthwile to use a range test for floating-point conversions, rather than "!=". That is easily done using specializationor type traits*/

