#include <iostream>
#include <string>
#include <list>

/*"list" is repusented as a doubley linked list abstraction part of the std library*/

list<Entry> phone_book = {
	{"David Hume", 123456},
	{"karl Popper", 234567},
	{"Bertrand Arthur WIlliam Russell", 345678}
}; 

/*With linked list you might search the list looking for an element with a given value. To do this, take advantage of the fact that a "list" is a sequence.*/
int get_number(const string& s)
{
	for (const auto& x : phone_book)
		if (x.name == s)
			return x.number; 
	return 0;	/*use 0 to represent "number not found"*/
}

/*doubley linked list iter*/
int get_number(const string& s)
{
	for (auto p = phone_book.begin(); p != phone_book.end(); ++p)
		if (p->name == s)
			/* printf(p->number); lol c*/ 
			return p->number; 
	return 0;	/*use 0 to represent "number not found"*/
}

/*like with linked list adding and removing from a "list" is easy*/
void f(const Entry& ee, list<Entry>::iterator p, list<Entry>::iterator q)
{
	phone_book.insert(p,ee);	/*add "ee" before the element referred to by 'p'*/
	phone_book.erase(q); 		/*remove the element referred to by 'q'*/
}


