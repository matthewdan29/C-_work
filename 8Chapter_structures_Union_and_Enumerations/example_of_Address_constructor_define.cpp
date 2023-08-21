#include <string>
#include <iostream>
#include <list>
using namespace std; 
/*also you should read this as dir 8* file example_of_strurt* */
/*Address can be defined in this type of way too*/

Address::Address(const string& n, int nu, const string& s, const string& t, const string& st, int z)
	/*validate postal code*/
	:name{n},
	number{nu}, 
	streets{s},
	town{t}
{
	if (st.size()!= 2)
		error("State abbreviation should be two characters")
	state = {st[0], st[1]};		/*store postal code as characters*/
	ostringstream ost; 		/*an output string stream;*/
	ost << z; 			/*extract characters from int*/
	string zi {ost.str()};
	switch(zi.size())
	{
		case 5: 
			zip = {zi[0], zi[1], zi[2], zi[3], zi[4]}; 
			break;

		case 4: 	/*starts with '0'*/
			zip = {'0', zi[0], zi[1], zi[2], zi[3]}; 
			break; 

		default: 
			error("unexpected ZIP code format"); 
	}
	/*...check that the code makes sense...*/
}
