#include <string>
#include <iostream>
#include <list>
#include <regex>
using namespace std::regx; 

/*this define and print a pattern:*/
regex pat (R"(\w{2}\s*\d{5}(-\d{4})?)");	/*ZIP code pattern: XXddddd-dddd and variants*/
cout << "pattern: " << pat << '\n'; 

/*Simplest way to using a pattern is to search for it in a stream:*/

int lineno = 0; 
for (string line; getline(cin, line);)		/*read into line buffer */
{
	++lineno; 
	smatch matches; 			/*matched strings go here*/
	if (regex_search(line, matches, pat))	/*search for pat in line*/
		cout << lineno << ":" << matches[0] << '\n'; 
}

/*The "regex_search(line, matches, pat)" searches the "line" for anything that matches the regular expression stored in "pat" and if it finds any matches, it stores them in matches.*/
