#include <list>
#include <string>
#include <iostream>

/*this is a red-black tree struct class*/
/*if you want to look something it this is your choice*/
map<string, int> phone_book{
	{"David Hume", 123456},
	{"Karl Popper", 234567},
	{"Bertrand Arthur William Russell", 345678}
}; 

/*When indexed by a value of its first type, a "map" returns the corresponding value of the second type.*/

int get_number(const string& s)
{
	return phone_book[s]; 
}
/*Subscripting a map is essentially the lookup we call "get_number()". If a "key" isn't found, it is entered into the "map" with a default value for its "value". */
/*if you wanted to avoid entering invalid number into your phone book object you could use "find()" and "insert()" instead of "[]". */
