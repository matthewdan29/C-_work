#include <string>
#include <list>
#include <iostream>
using namespace std; 
/*"shared_ptr" are copied not moved*/
/*The "shared_ptr" for an object shar ownership of an object and that object is destroyed when the last "shared_ptr" is destroyed.*/
void f(shared_ptr<fstream>); 
void g(shared_ptr<fstream>); 

void user(const string& name, ios_base::openmode mode)
{
	shared_ptr<fstream> fp{new fstream(name, mode)}; /*file handler*/ 
	if (!*fp)
		throw No_file{};	/*make sure the file was properly opened*/

	f(fp); 
	g(fp); 		/*look the pointer is being shared by 2 functions*/
	/*...*/
}

/*Now, the file opened by "fp" constructor will be closed by the last function to destroy a copy of "fp".*/

/*This makes the lifetime of the shared object hard to predict. using "shared_ptr" only if you actually need shared ownership.*/
