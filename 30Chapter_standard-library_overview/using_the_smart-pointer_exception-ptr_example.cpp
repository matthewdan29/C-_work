#include <string>
#include <list>
#include <iostream>
using namespace std; 
/*an "exception_ptr" can point to any exception not just exceptions from the hierarchy*/
/*The "make_exception_ptr()" can be implemented as below*/

template<typename E>
exception_ptr make_exception_ptr(E e) noexcept; 
try{
	throw e; 
}
catch(...)
{
	return current_exception(); 
}


