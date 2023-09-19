#include <string>
#include <list>
#include <iostream>
#include <container>
using namespace std; 

/*As the file says the unordered assoviative containers are hash tables(Note: you might see me calling it salt tables)
 * There are only few deffereences from (ordered: think of probing) containters because the associative containers share most operations*/

unordered_map<string,int> score1
{
	{"andy", 7}, {"al", 9}, {"bill", -3}, {"barbara", 12}
}; 

map<string,int> score2
{
	{"andy", 7}, {"al", 9}, {"bill", -3}, {"barbara", 12}
}; 

template<typename X, typename Y> 
ostream& operator <<(ostream& os, pair<X,Y>& p)
{
	return os << '{' << p.first << ',' << p.second << '}'; 
}

void user()
{
	cout << "unordered: "; 
	for(const auto& x : score1)
		cout << x << ","; 

	cout << "\nordered: "; 
	for (const auto& x : score2)
		cout << x << ", "; 
}

/*The visible difference is that iteration through a "map" is ordered for the an "unordered_map" it is not*/

unordered: {andy,7}, {al,9}, {bill,-3}, {barbara,12};  
ordered: {al,9}, {andy,7}, {barbara,12}, {bill,-3}; 

/*Iteration over an "unordered_map" depends on the order of insertion, the hash function, and the load facter. There is no guarantee that elements are printed in the order of their insertion. but the time it take to do operations is amazing*/


