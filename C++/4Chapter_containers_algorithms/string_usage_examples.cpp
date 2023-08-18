#include <string>
#include <list>
#include <iostream>

/*this shows the concatenation of strings*/
string compose(const string& name, const string& domain)
{
	return name + '@' + domain; 
}

auto addr = compose("dmr", "bell-labs.com";)

/*"+=" directly supports concatenation to the end of a string*/
void m2(string& s1, string& s2)
{
	s1 = s1 + '\n';		/*append newline*/
	s2 += '\n';		/*append newline*/
};

/*"(s1 = s1 + '\n')" == "(s2 += '\n')" they mean the samething. */

/*Among other useful features, it provides the ability to manipulate substrings. below is a example.*/

string name = "Niels Stroustrup"; 

void m3()
{
	string s = name.substr(6,10); 		/*s = "Stroustrup"*/
	name.replace(0,5,"nicholas");		/*name becomes "nicholas Stroustrup"*/
	name[0] = toupper(name[0]);		/*name becomes "Nicholas Stroustrup"*/
}
/*"replace()" operation replaces a substring with a value. */

/*Naturally, "strings" can be compared against each other and against string literals. */

string incantation; 

void respond(const string& answer)
{
	if (answer == incantation)
	{
		/*perform magic (thats what the creator of C++ put)*/
	}
	else 
		if (answer == "yes")
		{
			/*...*/
		}
	/*...*/
}
