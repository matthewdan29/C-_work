#include <string>
#include <list>
#include <iostream>
using namespace std; 

/*You can handle such resource acquistion and release problems using objects of classes with constructors and destructors. You can define a class "File_ptr" that acts like a "FILE*"*/

class File_ptr
{
	FILE* p; 
public: 
	File_ptr(const char* n, const char* a)			/*open file 'n'*/
		:p{fopen(n,a)}
	{
		if (p == nullptr) throw runtime_error{"File_ptr: Can't open file"}; 	
	}

	File_ptr(const string& n, const char* a)		/*open file n*/
		:File_ptr{n.c_str(),a}
	{}
	
	explicit File_ptr(FILE* pp)				/*assume ownership of ppp*/
		:p{pp}
	{
		if (p == nullptr) throw runtime_error("File_ptr: nullptr"); 
	}

	/*...suitable move and copy operations...*/

	~File_ptr(){fclose(p); }
	
	operator FILE*() {return p; }
}; /*You can construct a "File_ptr" given either a "FILE*" or the arguments required for "fopen()". A File_ptr will be destroyed at the end of its scope and its destructor will close the file. */

/*The function needed to open read write and edit files shrinks to the example below */

void use_file(const char* fn)
{
	File_ptr f(fn, "r"); 
	/*...use f...*/
}/*The destructor will be called independently of whether the function is exited normally or exited because an exception is throw. */
