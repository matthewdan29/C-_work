#include <string>
#include <iostream>
#include <list>
#include <vector>
using namespace std; 

/*References can also be used as return types. This is mostly used to define functions that can be used on both the left-hand and right-hand sides of an assignment. A "Map" is a good example. */

template<class K, class V>
class Map					/*a simple map class*/
{
public: 
	V& operator[](const K& v);		/*return the value corresponding to the key 'v'*/

	pair<K,V>* begin() {return &elem[0]; }
	pair<K,V>* end(){return &elem[0]+elem.size();}
private: 
	vector<pair<K,V>> elem;		/*{key, value} pairs*/
};


/*This show an implementation based on linear search for a key match:*/

template<class K, class V>
V& Map<K,V>::operator[](const K& k)
{
	for (auto& x : elem)
		if (k == x.first)
			return x.second; 

	elem.push_back({k, V{}}); 		/*add pair at end*/
	return elem.back().second;		/*return the (default) value of the new element*/
}/*He pass the key argument, 'k', by reference because it might be of a type that is expensive to copy.*/

int main()			/*count the number of occurrences of each word on input*/
{
	Map<string, int>buf; 

	for(string s; cin>>s;)
		/*Befor runing this Enters into a non stop loop add a break point to reach the program end. */
		++buf[s];
	 

	for (const auto& x : buf)
		cout << x.first << ": " << x.second << '\n'; 
}
/*Each time around, the input loop reads one word from the standard input stream "cin" into the string 's' and then updates the counter associated with it.*/

