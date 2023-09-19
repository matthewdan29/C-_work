#include <list>
#include <string>
#include <iostream>
#include <map>
using namespace std; 

/*Here are the template arguments and memebers types for "map"*/

template<typename Key, 
	typename T, 
	typename Compare = less<Key>, 
	typename Allocator = allocator<pair<const Key, t>>>
class map{
	public: 
		using key_type = Key; 
		using mapped_type = T; 
		using value_type = pair<const Key, T>; 
		using key_compare = Compare; 
		using allocator_type = Allocator; 
		using reference = value_type&; 
		using iterator = /*implementation-defined*/; 
		using const_iterator = /*implementation-defined*/; 
		using size_type = /*implementation-defined*/; 
		using defference_type = /*implementation-defined*/; 
		using pointer = typename allocator_traits<Allocator>::pointer; 
		using reverse_iterator = std::reverse_iterator<iterator>; 
		using const_reverse_iterator = std::reverse_iterator<iterator>;; 		class value_compare{/*operator() (k1,k2) does a key_compare()(k1,k2)*/}; 
	/*...*/
}; 

/*Associtative containers have constructors allowing a programmer to supply a comparator:*/

map<string,pair<Coordinate,Coordinate>> locations
{
	{"Copenhagen", {"55:40", "12:34E"}},
	{"Rome",{"41:54N","12:30E"}}, 
	{"New York",{"40:40N","73:56W"}}
}

/*if you go looking for key 'k' in the map 'm' and it not found by a subscript operation, "m[k]" a default value is inserted. like example below*/

map<string,string> dictionary; 

dictionary["sea"] = "large body of water"; 		/*insert or assign to element*/

cout << dictionary["seal"]; 				/*read value*/

/*If "seal" is not in the dictionary, nothing is printed: the empty string was entered as the value for "seal" and returned as the result of the lookup*/

/*If that is not the desired behavior, you can use "find()" and "insert()" directly: like example below*/

auto q = dictionary.find("seal"); 		/*lookup; dont insert*/

if (q == dictionary.end())
{
	cout << "entry not found"; 
	dictionary.insert(make_pair("seal", "eats fish")); 
}
else 
	count q->second;

/*The "insert(make_pair())" notation is rather verbose. You should use "emplace()" like the example below*/
dictionary.emplace("sea cow", "extinct"); 	
