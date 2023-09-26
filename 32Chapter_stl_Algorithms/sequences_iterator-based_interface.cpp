#include <string>
#include <list>
#include <iostream>
#include <vector>
using namespace std; 

/*standard-library algorithms aim to acheve the most general and flexible interface to something that can be implemented. 
 * An iterator-based interface does not directly represent the notion of a sequenece, leading to the possibility of confusion and difficulties in detecting range error.*/
/*Many such problems can be alleviated by providing container versions of the standard-library algorithms: like example below*/

template<typename Cont>
void sort(Cont& c)
{
	static_assert(Range<Cont>(), "sort(): Cont argument not a Range"); 
	static_assert(Sortable<Iterator<Cont>>(), "sort(): Cont argument not Sortable"); 

	std::sort(begin(c), end(c)); 
}

template<typename Cont1, typename Cont2>
void copy(const Cont1& source, Cont2& target)
{
	static_assert(Range<Cont1>(), "copy(): Cont1 argument not a Range"); 
	static_assert(Range<Cont2>(), "copy(): Cont2 argument not a Range"); 

	if (target.size()<source.size()) 
		throw out_of_range{"copy target too small"}; 
	std::copy(source.begin(), source.end(), target begin()); 
}

/*This would simplify the definition of "user()", make the most errors impossible to express, and catch the first at run time: */

void user(vector<int>& v1, vector<int>& v2)
{
	copy(v1, v2);		/*overflows will be caught*/
	sort(v1); 
}
/*A complementary approach is to define a "range" or "sequence" abstraction that allows you to define sequences when needed.*/

/*The concept "Range" to denote anything with "begin()" and "end()" iterators*/
