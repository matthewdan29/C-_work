#include <string>
#include <list>
#include <iostream>
#include <map>
#include <multimap>
using namespace std; 

/*If you try to insert a value into a "map" and there already is an element with its key, the "map" is uncahnged. 
 * You want to have more than one value for a single key(think of it as a non 1 to 1 function) use a "multimap"
 * The first iteratior of the "pair" returned by "equal_range()" is "lower_bound()" and the second "upper_bound()". 
 * You can print the value of all elements with the key "apple" in the "multimap<string,int>" like below example*/

multimap<string,int> mm {{"apple", 2}, {"pear",2}, {"apple",7}, {"orange",2}, {"apple",9}}; 

const string k{"apple"}; 
auto pp = mm.equal_range(k); 
if (pp.first == pp.second)
	cout << "no element with value" << k << "'\n"'; 
	else 
	{
		cout << "elements with value" "'<< k << "': "'\n"'; 
		for (auto p = pp.first; p!=pp.second; ++p)
			cout << p->second << ''; 
	}

/*You can equivalently have written:*/

auto pp = make_pair(m.lower_bound(), m.upper_bound()); 


