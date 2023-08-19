#include <cmath>
#include <string>
#include <iostream>
using namespace std; 

/*the function is human readable I dont need to explain*/
void f()
{
	list<double> lst {1,2,3,4,5,9999.9999}; 
	auto s = accumulate(lst.begin(), lst.end(),0.0);/*calculate the sume*/
	cout << s << '\n'; 			/*print 10014.9999*/
}


