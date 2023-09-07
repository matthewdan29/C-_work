#include <string>
#include <list>
#include <iostream>
#include <system_error>
using namespace std; 

/*An "error_category" is an interface to an object of a class derived from "error_category" is passed by reference and stored as a pointer. Each separate "error_category" is represented by an unique object.
 * Consider example below*/

ostream& open_file(const string& path)
{
	auto dn = split_into_directory_and_name(path); 		/*split into {path, name}*/

	if (error_code err {does_directory_exist(dn.first)})	/*ask "the system" about the path*/
	{
		if(err==errc::permission_denied)
		{
			/*...*/
		}
		else if (err==errc::not_a_directory)
		{
			/*...*/
		}
		throw system_error(err); 	/*cant do anything locally*/
	}
	/*...*/
	return ofstream{path}; 
}

