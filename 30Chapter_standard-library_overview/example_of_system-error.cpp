#include <string>
#include <list>
#include <iostream>
#include <system_error>
using namespace std; 

/*if you ever booted up a linux then you should read this and master why the fail signs are popping up*/
/*In <system_error>, the standard library provides a framework for reporting errors from the operation system and lower-level system components. You may write a function to check a file name and then open a file like below.*/

ostream& open_file(const string& path)
{
	auto dn = split_into_directory_and_name(path); 		/*plit into {path,name}*/

	error_code err {does_directory_exist(dn.first)}; 	/*ask "the system" about the path*/

	if(err)			/*err!=0 means error*/
	{
		/*...see if anything can be done...*/

		if(cannot_handle_err)
			throw system_error(err); 
	}

	/*....*/
	return ofstream{path}; 
}/*Assuming that the system doesnt know about C++ exceptions, we have no choice about whether to deal with error codes or not; the only questions are "where" and "how"*/

/*code catching a system_error has its error_code available.*/
try
{
	/*something*/
}
catch (system_error& err)
{
	cout << "caught system_error" << err.what() << '\n'; 	/*error message*/

	auto ec = err.code(); 
	cout << "category:" << ec.category().what() << '\n'; 
	cout << "value:" << ec.value() << '\n'; 
	cout << "message:" << ec.message() << '\n'; 
}/*"system_error" can be used by code that is not part of the stdlib.h. 
A system-specific "error_code" is passed, rather than a potentially portable "error_condition". To get an "error_condition" from an "error_code" use "default_error_condition()". */
