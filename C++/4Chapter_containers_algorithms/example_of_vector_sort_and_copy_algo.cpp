#include <list>
#include <string>
#include <iostream>

/*A lot of great computer scienist stress a lot out about Algo' and struct...*/
/*yet see someone talk about frameworks or lang. but a lot of math.*/
/*This set of programs sorts a "vector" and places a copy of each unique "vector" element on a list.*/

bool operator<(const Entry& x, const Entry& y)	/*less than*/
{
	return x.name < y.name;		/*order Entrys by their names*/
}

void f(vector<Entry>& vec, list<Entry>& lst)
{
	sort(vec.begin(), vec.end());		/*use < for order*/
	unique_copy(vec.begin(), vec.end(), lst.begin());	/*dont copy adjacent equal elements*/
}

list<Entry> f(vector<Entry>& vec)
{
	list<Entry> res; 
	sort(vec.begin(), vec.end()); 
	unique_copy(vec.begin(), vec.end(), back_inserter(res)); /*append to res*/
	return res; 
}

/*"back_inserter()" adds elements at the end of a container, extending the container to make room for them.*/
