#include <string>
#include <list>
#include <iostream>
using namespace std; 

/*The standard-library exception hierarchy is rooted in class "exception"*/

class exception
{
public: 
	exception(); 
	exception(const exception&); 
	exception& operator=(const exception&); 
	virtual ~exception(); 
	virtual const char* what() const; 
};/*The "what()" function can be used to obtain a string that is supposed to indicate something about the error that caused the exception.*/

/*A programmer can define an exception by deriving from a standard-library exception like the function below:*/

struct My_error : runtime_error
{
	My_error(int x) :runtime_error{"My_error"}, interesting_value{x}{}
	int interesting_value; 
}; 

/*Unless you know that no facility i sused in a way that could throw an exception, it is a good idea to somewhere catch all exceptions. like below*/

int main()
	try
	{
		/*...*/
	}
catch (My_error& me)			/*a My_error happened*/
{
	/*you can use me. interseting_value and me.what()*/
}

catch (runtime_error& re)		/*a runtime_error happened*/
{
	/*we can use re.what()*/
}

catch(exception& e)			/*some standard-library exception happened*/
{
	/*we can use "e.what()"*/
}

catch(...)				/*some unmentioned exception happened*/
{
	/*we can do local cleanup*/
}
