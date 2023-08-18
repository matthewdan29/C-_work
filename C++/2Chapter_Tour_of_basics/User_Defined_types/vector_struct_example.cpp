#include <iostream>

struct vector 
{
	int sz;		/*number of elements*/
	double* elem;	/* pointer to elements */
}; 
vector v;

void vector_init(vector& v, int s)
{
	v.elem = new double[s];		/*Just like java new operation*/
	v.sz = s; 
}

/* a simple use of vector looks like this:*/

double read_and_sum(int s)
{/* read 's' integers from "cin" and return their sum; 's' is assumed to be + */
	vector v; 
	vector_init(v,s); 	/*allocate 's' elements for 'v'*/
	for (int i = 0; i != s; ++i)
		cin >> v.elem[i];		/*reads into elements*/
	double sum = 0; 
	for (int i = 0; i != s; ++i)
		sum+=v.elem[i]; 
	return sum; 
}


void f(vector v, vector& rv, vector* pv)
{
	int i1 = v.sz;		/*access through name*/
	int i2 = rv.sz;		/*access through reference*/
	int i4 = pv->sz;	/*access through pointer*/
}


