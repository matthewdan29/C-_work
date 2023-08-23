#include <string>
#include <list>
#include <iostream>
using namespace std;

/*simplest "range-for-statement"*/

int sum(vector<int>& v)
{
	int s = 0; 
	for (int x : v)	/*this reads: "for each element 'x' in range 'v'"*/
		s += x; 
	return s; 
}

/*The controlled variable, x in the example below refers to the current element is equivalent to "*p" when using and equivalent "for"-statement*/

int sum2(vector<int>& v)
{
	int s = 0; 
	for (auto p = begin(v); p!=end(v); ++p)
		s += *p; 
	return s; 
}

/*References are also appropriate for elements that might be large, so that copying them to the element value could be costly. Example below*/
template<class T> T accum(vector<T>& v)
{
	T sum = 0; 
	for (const T& x : v)
		sum += x; 
	return sum; 
}
