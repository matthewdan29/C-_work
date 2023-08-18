#include <iostream>

/*you can write a function that calculates the sum of the elements values of any container.*/

template<typename Container, typename Value>
Value sum(const Container& c, Value v)
{
	for (auto x : c)
		v += x; 
	return v; 
}

/*"Value" template argument and the function argument 'v' are there to allow the caller to specify the type and initial value of the accumulator(the variable in which to accumulate the sum)*/

void user(Vector<int>& vi, std::list<double>& ld, std::vector<complex<double>>& vc)
{
	int x = sum(vi,0);	/*the sum of a vector of ints (add ints)*/
	double d = sum(vi, 0.0);	/*sum of cector of ints (add doubles)*/
	double dd = sum(ld, 0.0);	/*sum of a vector of list double*/
	auto z = sum(vc, complex<double>{}); 	/*sum of vector complex*/
}
