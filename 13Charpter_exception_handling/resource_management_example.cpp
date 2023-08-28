#include <string>
#include <list>
#include <iostream>
using namespace std; 

/*When a function acquires a resource that is, it opens a file, allocates some memory from the free stroe, acquires a mutx, it is often essential for the future running of the system that the resource be properly released*/

void use_file(const char* fn)		/*naive code*/
{
	FILE* f = fopen(fn, "r"); 

	/*...use f...*/
	fclose(f); 
}/*something could happen between fopen and fclose causing the resource to leak*/

/*first attempt to make "use_file" fault-tolerant looks like this its bad but it works.*/
void use_file(const char* fn)			/*clumsy code*/
{
	FILE* f = fopen(fn, "r"); 

	try 
	{
		/*...use f...*/
	}
	catch (...)			/*catch every possible exceptin*/
	{
		fclose(f); 
		throw; 
	}
	fclose(f); 
}
