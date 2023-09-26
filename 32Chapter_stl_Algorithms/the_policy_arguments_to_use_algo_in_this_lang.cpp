#include <string>
#include <list>
#include <iostream>
#include <vector>
using namespace std; 

/*below example gives 2 general ways to use algo's which in turn gives increased flexibility of the std library and its range of uses.*/

template<class Iter>
void sort(Iter first, Iter last)
{
	/*sort using e1 < e2*/
}

template<class Iter, class Pred>
void sort(Iter first, Iter last, Pred pred)
{
	/*sort using pred(e1, e2)*/
}

/*To simplify the task for the programmer, the "_if" suffix is often used to indicate that an algorithm takes a predicate. look at example below*/

using Predicate = bool(*)(int); 

void f(vector<Predicate>& v1, vector<int>& v2)
{
	auto p1 = find(v1.begin(), v1.end(), pred); 	/*find element with the value pred*/
	auto p2 = find_if(v2.begin(), v2.end(), pred); 	/*count elements for which "pred()" returns true*/
}
/*GENERAL: Some operations passed as arguments to an algorithm are meant to modify the elements to which they are applied, but most are predicates.*/

/*NOTE: a predicate should not carry state that changes the meaning of it operations */
