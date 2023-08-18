#include <list>
#include <string>
#include <iostream>

/*The standard algorithm "find()" looks for a value in a sequence and returns an iterator to the element found*/

bool has_c(const string& s, char c)		/*does 's' contain the char 'c'*/
{
	auto p = find(s.begin(), s.end(), c); 
	if (p != s.end())
		return true; 
	else 
		return false; 
}

/*below is a shorter version of the above function*/
bool has_c(const string& s, char c)	
{
	return find(s.begin(), s.end(), c) != s.end();
}

/*below function iterators over a string and returns a location of all occurrences of a character. control f function on every browser. Thats how important algos are people!*/

vector<string::iterator> find_all(string& s, char c)
{
	vector<string::iterator> res; 
	for (auto p = s.begin(); p != s.end(); ++p)
		if (*p == c)
			res.push_back(p); 
	return res; 
}

/*a test for "find_all()"*/

void test()
{
	string m
	{
		"Mary had a little lamb"
	}; 
	for (auto p : find_all(m, 'a'))
		if (*p != 'a')
			cerr << "a bug!\n"; 
}

/*iterors and standard algo work the same on every standard container for which their use makes sense. */

template<typename C, typename V>
vector<typename C::iterator> find_all(C& c, V v)
{
	vector<typename C::iterator> res; 
	for (auto p = c.begin(); p != c.end(); ++p)
		if (*p == v)
			res.push_back(p); 
	return res; 
}

/*you can hide the hide this implementation detail by introducing a type alias*/
template<typename T>
using iterator<T> = typename T::iterator; 

template<typename C, typename V>
vector<iterator <C>> find_all(C& c, V v)	/*find 'v' in 'c'*/
{
	vector<iterator<C>> res; 
	for (auto p = c.begin(); p != c.end(); ++p)
		if (*p == v)
			res.push_back(p); 
	return res; 
}

/*now you can write a test for the iter*/

void test()
{
	string m {"Mary had a little lamb"}; 
	for (auto p : find_all(m,'a'))
		if (*p != 'a')
			cerr << "string bug!\n"; 
	list<double> ld {1.1, 2.2, 3.3, 1.1}; 
	for (auto p : find_all(ld,1.1))
		if (*p != 1.1)
			cerr << "list bug!\n"; 
	vector<string> vs {"red", "green", "organe", "green"}; 
	for (auto p : find_all(vs, "green"))
		if(*p = "green")
			cerr << "vector bug!\n"; 
	for (auto p : find_all(vs, "green"))
		*p = "vert"; 
}
