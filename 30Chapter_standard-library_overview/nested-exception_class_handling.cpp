#include <string>
#include <list>
#include <iostream>
using namespace std; 

/*The intended use of "nested_exception" is as a base class for a class used by an exception handler to pass some information about the local context of an error together with a "exception_ptr" to the exception that caused it to be called example below.*/

struct My_error : runtime_error
{
	My_error(const string&); 
	/*...*/
}; 

void my_code()
{
	try
	{
		/*...*/
	}
	catch(...)
	{
		My_error err {"something went wrong in my_code()"}; 
		/*...*/ 
		throw_with_nested(err); 
	}
}/*Now "My_error" information is passed along together with a "nested_exception" holding an "exception_ptr" to the exception caught.*/

/*Further up the call chain, you might want to look at the nested exception:*/
void user()
{
	try
	{
		my_code(); 
	}
	catch(My_error& err)
	{
		/*...clear up my_error problems...*/
		try
		{
			rethrow_if_nested(err); 	/*rethrow the nested exception, if any*/
		}
		catch(Some_error& err2)
		{
			/*...clear up Some_error problems...*/
		}
	}	
}/*This assumes that we know the "some_error" might be nested with "My_error"*/

