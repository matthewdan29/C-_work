#include <string>
#include <list>
#include <set>
#include <map>
using namespace std; 

/*Try to think of a "set" as a "map" with no separate "value_type". 
 * For a "set", the "value_type" is also the "key_type"*/

struct Record{
	string label; 
	int value; 
}; 

/*To have a "set<Record>", you need to prove a comparison function. like the example below:*/

bool operator <(const Record& a, const Record& b)
{
	return a.label<b.label; 
}

/*Given that you can write: */

set<Record> mr {{"duck",10}, {"pork",12}}; 

void read_test()
{
	for (auto& r : mr)
	{
		cout << '{' << r.label << ':' << r.value << '}'; 
	}
	cout << endl; 
}

/*You cannot even change a member of an element that takes no part in the comparison*/
