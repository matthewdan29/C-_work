#include <iostream>

/*it is very common for a parameterized type to provide an alias for types related to their template arguments. */

template<typename T>
class Vector
{
public: 
	using value_type = T; 
	/*...*/
};

/*This allows us to write code that will work for every container that follows this convention.*/

template<typename C>
using Element_type = typename C::value_type; 

template<typename Container>
void algo(Container& c)
{
	Vector<Element_type<Container>> vec; /*keep results here*/
}

/*The aliasing mechanism can be used to define a new template by binding some or all template arguments. */

template<typename Key, typename Value>
class Map
{
	/*...*/
}; 

template<typename Value>
using String_map = Map<string, Value>; 

String_map<int> m;	/*'m' is a "Map<string,int>"*/
