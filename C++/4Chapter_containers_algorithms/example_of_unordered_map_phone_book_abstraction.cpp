#include <list>
#include <iostream>
#include <string>

/*hashing links here don't conlude with me.*/
unordered_map<string,int>phone_book{
	{"David Hume", 123456},
	{"Karl Popper", 234567},
	{"Bertrand Arthur William Russel", 345678}
}; 

/*you this algo struct is like salting a steak*/
int get_number(const string& s)
{
	return phone_book[s]; 
}


