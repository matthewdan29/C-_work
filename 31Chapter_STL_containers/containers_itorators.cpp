#include <string>
#include <iostream>
#include <list>
#include <vector>
using namespace std; 

/*The most common form of iteration over elements is to traverse a container from its beginning to its end. 
 * The simplest way of doing that is by a range-for loop which implicitly uses "begin()" and "end()": example below*/

for (auto& x : v)			/*implicit use of v.begin() & v.end()*/
	cout << x << '\n'; 

/*When you need to know the position of an element in a container of if you need to refer to more than one element at a time, you use iterators directly. "auto" is useful to minimize source code size and eliminate opportunities for typos. 
 * Assuming a random-access iterator:*/

for (auto p = v.begin(); p!=end(); ++p)		/*use const iterators*/
{
	if(p!=v.begin() && *(p-1) == *p)
		cout << "duplicate" << *p << '\n'; 
}
