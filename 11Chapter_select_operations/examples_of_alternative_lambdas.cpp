#include <string>
#include <iostream>
#include <list>
using namespace std; 

/*Many lambdas are small and used only once. The realistic equivalent involves a local class defined immediately before its use. */

void print_modulo(const vector<int>& v, ostream& os, int m)
		/*output v[i] to os if v[i]%m==0*/
{
	class Modulo_print
	{
		ostream& os; 		/*memers to hold the capture list*/
		int m; 
	public: 
		Modulo_print(ostream& s, int mm) :os(s), m(mm) {}	/*capture*/
		void operator()(int x) const
		{if (x%m==o) os << x << '\n'; }
	}; 
	for_each(begin(v), end(v), Modulo_print{os, m}); 
}

/*compared to that, the version using the lambda is a clear winner. If we really want to name, we can just name the lambda: */

void print_modulo(const vector<int>& v, ostream& os, int m)
	/*output v[i] to os if v[i]%m==0*/
{
	auto Modulo_print = [&os, m] (int x) {if (x%m==0) os << x << '\n'; }; 

	for_each(begin(v), end(v), Modulo_print); 
}

/*writing a "for"-loop is an alternative to using a lambda with a "for_each()."*/

void print_modulo(const vector<int>& v, ostream& os, int m)
	/*output v[i] to os if v[i]%m==0*/
{
	for (auto x : v)
		if (x%m==0) os << x << '\n'; 
}

/*"for_each" is a rather special algorithm, and "vector<int>" is a very specific container. Consider generalizing "print_modulo()" to handle arbitrary containers*/

template<class C>
void print_modulo(const C& v, ostream& os, int m)
	/*output v[i] to os if v[i]%m==0*/
{
	for (auto x : v)
		if (x%m==0)
			os << x << '\n'; 
}/*This version works nicely for a "map". The C++ range-"for"-statement specifically caters to special case of traversing a sequence from its beginning to its end. The STL container make such traversals easy and general.*/

/*The "for"-loop version of "print_modulo()" is not amenable to change, so we have to rewrite it to an algorithm. */

template<class C>
void print_modulo(const C& v, ostream& os, int m)
		/*output v[i] to os if v[i]%m==0*/
{
	breadth_first(begin(v), end(v), [&os,m](int x){if (x%m==0) os << x << '\n'; }
			); 
}


