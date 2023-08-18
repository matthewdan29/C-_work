#include <string>
#include <iostream>
#include <list>
#include <iterator>
#include <vector>
#include <set>
#include <set>
using namespace std; 

/*A sequence is defined by a pair of iterator "[begin:end)" example below*/
sort(v.begin(), v.end()); 

/*you can make a "wraper function" to make it sort hand*/
namespace Estd
{
	using namespace std;	/*notice how afraid of the compiler I am */

	template<class C>
	void sort(C& c)
	{
		sort(c.begin(), c.end()); 
	}

	template<class C, class Pred>
	void sort(C& c, Pred p)
	{
		sort(c.begin(), c.end(), p); 
	}
	/*...*/
}
