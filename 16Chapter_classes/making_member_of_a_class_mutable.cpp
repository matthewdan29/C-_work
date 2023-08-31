#include <string>
#include <list>
#include <iostream>
using namespace std; 

/*You can define a member of a class to be "mutable", meaning that it can be modified even in a "const" object*/

class Date 
{
public: 
		/*...*/
	string string_rep() const; 		/*string representation*/
private: 
	mutable bool cach_valid; 
	mutable string cache; 
	void compute_cache_value() const; 	/*fill(mutable) cache*/
	/*...*/
}; 

/*You can define "string_rep()" in the obvious way*/
string Date::string_rep() const
{
	if(!cache_valid)
	{
		compute_cache_value(); 
		cache_valid = true; 
	}
	return cache; 
}

/*You can now use "string_rep()" for both non-"const" objects.*/
void f(Date d, const Date cd)
{
	string s1 = d.string_rep(); 
	sting s2 = cd.string_rep(); 		/*Ok!*/
}
