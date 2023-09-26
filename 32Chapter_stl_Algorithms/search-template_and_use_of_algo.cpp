#include <string>
#include <list>
#include <iostream>
using namespace std; 

/*"search()" is such a useful operation I believe everyone needs to know how to properly us it in their application program interface (yes I did just write it out lol)*/

string quote {"Why waste time learning, when ignorance is instantaneous?"}; 

bol in_quote(const string& s)
{
	auto p = search(quote.begin(), quote.end(), s.begin(), s.end()); /*find 's' in quote*/
	return p!=quote.end(); 
}

void g()
{
	bool b1 = in_quote("learning");		/*b1 = true*/
	bool b2 = in_quote("lemming"); 		/*b2 = false*/
}

/*you can see clearly that search is very useful to any program if it parsing text or looking for info in a output of billions of lines long in seconds*/
