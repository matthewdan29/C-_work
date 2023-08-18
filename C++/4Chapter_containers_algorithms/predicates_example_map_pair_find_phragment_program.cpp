#include <string>
#include <iostream>
#include <list>
#include <iterator>
#include <vector>	/*i'm not even using this but afraid of the compiler*/
#include <set>		/*This one too*/
using namespace std; 
/*really these are examples just getting in the habbit of doing it early for yall but ya I'm afraid of blowing off my leg not having all the includes*/

void f(map<string, int>& m)
{
	auto p = find_it(m.begin(), m.end(), Greater_than{42})
		/*...*/
}

/*Here, "Greater_than" is a function object hoding the value (42) to be compared against:*/

struct Greater_than
{
	int val; 
	Greater_than(int v) : val{v}{}
	bool operator()(const pair<string,int>& r){return r.second>val;}
}; 
/*Alternatively, we could use a lamnda expresstion.*/

int cxx = count_if(m.begin(), m.end(), [](const pair<string, int>& r){return r.second>42;}); 
