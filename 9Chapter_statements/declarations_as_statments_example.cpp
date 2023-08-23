#include <string>
#include <iostream>
#include <list>
using namespace std; 

/*There is rarely a reason to introduce a variable before there is a value for it to hold.*/

void f(vector<string>& v, int i, const char* p)
{
	if (p == nullptr)
		return; 
	if(i < 0; || v.size() <= i)
		error("bad inded"); 
	string s = v[i]; 
	if (s == p)
	{
		/*...*/
	}
	/*...*/
}


/*For user-defined types, postponing the definition of a variable until a suitable initializer is available can also lead to better performance.*/

void use()
{
	string s1; 
	s1 = "The best is the enemy of the good"; 
	/*...*/
}/*This request a default initialization folled by an assignment.*/

/*The most common reason to declear a variable without an initializer is that it requires a statement to give it its desired value.*/

void input()
{
	int buf[max]; 
	int count = 0; 
	for (int i; cin >> i; )
	{
		if (i < 0)
			error("unexpected negative value"); 
		if (count == max)
			error("buffer overflow"); 
		buf[count++] = i; 
	}
	/*...*/
}/*Assume that "error()" does not return; if it does, this code may cause a buffer overflow. Often "push_back()" provides a better solution to such examples.*/
