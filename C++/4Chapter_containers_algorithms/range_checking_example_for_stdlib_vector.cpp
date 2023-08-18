#include <iosteam>
#include <string>
#include <list>

/*you should use simple range-checking adaptation of "vector"*/
template<typename T>
class Vec : public std::vector<T>
{
	using vector<T>::vector;	/*use the constructors from vector*/

	T& operator[](int i)		/*range check*/
	{
		return vector<T>::at(i); 
	}

	const T& operator[](int i) const	/*range check const objects*/
	{
		return vector<T>::at(i); 	/*range check const objects*/
	}
};
/*"Vec" inherits everything from "vector" except for the subscript operations that it redefines to do range checking. */


/*for "Vec", an out-of-range access will throw an exception that the user can catch.*/

 void checked(Vec<Entry>& book)
{
	try
	{
		book[book.size()] = {"Joe", 9999999};	/*will throw an exception*/
		/*...*/
	}
	catch (out_of_range)
	{
		cout << "range error\n"; 
	}
}


/*One way to minimize surprises from uncaught exceptions is to use a "main()" with a "try" block as its body. */

int main()
	try
{
	/*the code for exacution*/	
}
catch (out_of_rang)
{
	cerr << "range error\m"; 
}
catch(...)
{
	cerr << "unknown exceptiong thrown\n"; 
}
