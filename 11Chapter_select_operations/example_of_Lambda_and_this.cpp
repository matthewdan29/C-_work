#include <string>
#include <iostream>
#include <list>
using namespace std; 

/*How do we access members of a class object from a lambda used in a member function? You can include class memebers in the set of names potentially captured by adding "this" to the capture list. This is used when we want to use a lambda in the implementation of a member function. For example, you might have a class for building up request and retrieving results: */

class Request
{
	function<map<string,string>(const map<string, string>&)> oper; 
	map<string, string> values; 		/*arguments*/
	map<string, string> results; 		/*targets*/
public: 
	Request(const string& s); 		/*parse and store request*/

	void execute()
	{
		[this](){results=oper(values); }	/*do oper to values yielding results*/
	}
}; 
/*Members are always captured by reference. That is, "[this]" implies that members are accessed through "this" rather than copied into the lambda. Unfortunately, "[this]" and "[=]" are incompatible. */
