#include <string>
#include <list>
#include <iostream>
#include <vector>
using namespace std; 

/*In general this family of Algo's can be thought of like changing the elements in a linked list, vector, or container etc..*/

/*This exmple "transform()" doesn't change the 'x' (input) but modify the 'y' (output). example below*/

template<class In, class Out, class Op>
Out transform(In first, In last, Out res, Op op)
{
	while (first!=last)
		*res++ = op(*first++); 
	return res; 
}
/*The output sequence may be the same as the input sequence:*/

void toupper(string& s) 	/*remove case*/
{
	transform(s.begin(), e.end(), s.begin(), toupper); 
}
