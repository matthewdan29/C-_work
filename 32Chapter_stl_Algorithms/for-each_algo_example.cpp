#include <string>
#include <list>
#include <iostream>
#include <vector>
using namespace std; 

/*When possible prefer a more specific algorithm this is just to show to use algorithms.*/
/*Ther operation passed to "for_each()" may modify elements. like below*/

void increment_all(vector<int>& v)		/*increment each element of v*/
{
	for_each(v.begin(), v.end(), [](int& x) {++x}); 
}


/*personaly: I would add an after effect to an operation to a for loop to add to which ever value but please to remember this is just a guide of the C++ lang*/

