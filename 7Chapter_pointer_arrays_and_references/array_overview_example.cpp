#include <string>
#include <list>
#include <iostream>
#include <cmath>
using namespace std; /*lol what namespace your using?...*/

/*you can access an array using the subscript operator, "[]" or through a pointer.*/

void f()
{
	int aa[10]; 
	aa[6] = 9;		/*assign to "aa's" 7th element*/
	int x = aa[99]; 	/*undefined behavor*/
}

/*The number of elements of the array, the array bound must be constant expression. If you need variable bounds, use a "vector" standard library version*/

void f(int n)
{
	int v1[n];		/*error: array size not a constant expression*/
	vector<int> v2(n);	/*Ok: vector with 'n' int elemements*/
}

/*An array can be allocated statically, on the stack, and on the free store.*/

int a1[10];			/*10 ints in static storage*/

void f()
{
	int a2[20];		/*20 ints on the stack*/
	int*p = new int[40];	/*40 ints on the free store.*/
}

/*The C++ built-in array is an inherantly low-level facility that should primarily be used inside the implementation of higer-level, better-behaved, data structures, such as the standard-library "vector"  or "array"*/

/*NOTE: avoid arrays in interfaces because the implicit conversion to pointer is the root cause of many common errors in C cod and C-style C++ code. Make sure arrays allocated on the free store is "deleted"*/
