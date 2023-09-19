#include <string>
#include <list>
#include <iostream>
#include <map>
using namespace std; 

/*The "unordered_map" has a lot of template arguments and member type aliases to match lik below: if you opened this file I'm pretty sure you did not need to read the commit*/

template<typename Key, 
	typename T, 
	typename Hash = hash<key>, 
	typename Pred = std::equal_to<Key>, 
	typename Allocator = std::allocator<std::pair<const Key, T>>>
class unordered_map
{
	public: 
		using key_type = Key; 
		using value_type = std::pair<const Key, T>; 
		using mapped_type = T; 
		using hasher = Hash; 
		using key_equal = Pred; 
		using allocator_type = Allocator; 
		using pointer = typename allocator_traits<Allocator>::pointer; 
		using const_pointer= typename allocator_traits<Allocator>::const_pointer; 
		using reference = value_type&; 
		using const_reference = const value_type&; 
		using size_type = /*implementation-defined*/; 
		using defference_type = /*implementation-defined*/; 
		using iterator = /*implementation-defined*/; 
		using const_iterator = /*implementation-defined*/; 
		using const_local_iterator = /*implementation-defined*/; 
		/*...*/
}; 

/*An "unordered_map<X>" uses "hash<X>" for hashing and "equal_to<X>" to compare keys.
 * The defaul "equal_to<X>" simply compares 'X' values using "==".*/

/*There are lots of ways to construct a "unordered_map" be very careful if you choice to use 1 or 2 arguments. 
 * Below is examples the GOAT *BOOP, BOOP, BOOP* put in his book on his own language*/

map<string, int> m{My_comparator}; 		/*OK*/
unordered_map<string, int> um{My_hasher}; 	/*error you cant just construct a hash function with your own custom hash function */

/*A single constructor argument must be another "unordered_map", a bucket count or an allocator. like below*/

unordered_map<string,int> um {100,My_hasher}; 		/*OK*/
