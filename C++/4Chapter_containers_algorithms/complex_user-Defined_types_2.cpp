#include <iostream>
#include <string>
#include <list>

/*this is a more complex input operator because it has to check for correct formatting and deal with errors*/

istream& operator>>(istream& is, Entry& e)
	/*read {"name", number} pair. Note: formatted with {" ", and}*/
{
	char c; 
	char c2; 
	if (is >> c && c == '{' && is >> c2 && c2 == " ")
	{ /*start with a {" */
		sting name; 	/*the default value of a string is the empty string: ""*/
		while (is.get(c) && c != " ")	/*anything before a '"' is part of the name*/ /*also "is.get(c)" does not skip whitespaces*/
			name += c; 
		if (is >> c && c == ',') /*"is>>c" skips whitespaces*/
		{
			int number = 0; 
			if (is >> number >> c && c == '}')
			{	/*read the number and a "}"*/
				e = {name, number};	/*assign to entry*/
				return is; 
			}
		}
	}
	is.setf(ios_base::failbit); 
	return is; 
}

/*An input operation returns a reference to its "istream" which can be used to test if the operation succeeded. */

/*you can read pair of values from input into Entry*/
for (Entry ee; cin>>ee;)	/*read from "cin" into "ee"*/
	cout << ee << '\n';	/*write "ee" to "cout"*/
