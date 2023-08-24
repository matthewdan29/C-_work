#include <string>
#include <list>
#include <iostream>
using namespace std; 

/*Type "initializer_list<T>" is used to handle variable-length "{}-lists" 
 * Its most obvious use is to allow initializer lists for user-defined conatiners, but it can also be used directly : */

int high_value(initializer_list<int>val)
{
	int high = numeric_traits<int>lowest(); 
	if (val.size()==0)
		return high; 

	for (auto x : val)
		if(x > high)
			high = x; 

	return high; 
}

int v1 = high_value({1,2,3,4,5,6,7}); 
int v2 = high_value({-1,2,v1,4,-9,20,v1}); 
