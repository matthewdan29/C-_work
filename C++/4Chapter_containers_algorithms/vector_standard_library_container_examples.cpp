#include <iostream>
#include <string>
#include <list> /*you need this*/

/*you can init(initialize) a "vector" with a set of values of its types*/
vector<Entry>phone_book ={
	{"David Hume", 123456},
	{"Karl Popper", 234567}. 
	{"Bertrand Arthur William Russel", 345678}
};

/*Elements can be accessed through subscripting*/
void print_book(const vector<Entry>& book)
{
	for (int i = 0; i != book.size(); ++i)
		cout << book[i] << '\n'; 
}

/*The elements of a "vector" constitute a range, so we can use a rang-for loop*/
void print_book(const vector<Entry>& book)
{
	for (const auto& x : book) 
		cout << x << '\n'; 
}

/*You can define a "vactor", you give it an initial size */
vector<int> v1 = {1, 2, 3, 4}; 	/*size is 4*/
vector<string> v2;		/*size is 0*/
vector<shape*> v3(23);		/*size is 23; initial element value: nullptr*/
vector<double> v4(32, 9.9);	/*size is 32; initial element value: 9.9*/

/*One of the most useful operations on a "vector" is push_back(), which adds a new element at the end of a vector, increasing its size by one.*/

void input()
{
	for (Entry e; cin>>e;)
		phone_book.push_back(e); 
}

/*A "vector" can be copied in assignments and initialization like below*/
vector<Entry>book2 = phone_book;

/*side note 
 * 	When "vector" holds many elements, such innocent-looking assignments and initializations can be expensive. Where copying is undesirable, references or pointer or move operations should be used. */
