#include <string>
#include <list>
#include <iostream>
#include <vector>
using namespace std; 

/*An element is moved if its position is after the inseration/deletion point or if all elements are moved because the new size exceeds the previous capacity. Truthfuly That doest explain what the examples explain below*/

vector<int> v {4,3,5,1}; 
auto p = v.begin()+2; 			/*points to "v[2]", that is, the 5*/
v.push_back(6); 			/*'p' becomes invalid; v == {4,3,5,1,6}*/
p = v.begin()+2; 			/*p2 points to v[4] that is the 6*/
auto p2 = v.begin()+4; 			/*p2 points to v[4] that is the 6*/
v.erase(v.begin()+3); 			/*v=={4,3,5,6}; p is still valid; p2 is invalid*/

/*The "emplace()" operation is used when it is notationally awkward or potentially inefficient to first create an object and then copy it into a container like below*/

void user(list<pair<string,double>>& lst)
{
	auto p =  lst.begin(); 
	while (p!=lst.end() && p->first!="Denmark")	/*find an insertion point*/
		/*do nothing*/; 

	p = lst.emplace(p,"England", 7.5); 		/*nice and terse*/
	p = lst.insert(p,make_pair("France", 9.8)); 	/*helper function*/
	p = lst.insert(p,pair<string,double>>{"Greece", 3.14})	/*verbose*/
}/*The "forward_list" does not provide operations, such as "insert()" that operate before an element identified by an iterator. it uses "insert_after()" use data structure and algo logic my guy*/
