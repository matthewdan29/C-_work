#include <string>
#include <list>
#include <iostream>
using namespace std; 

/*By default, the allocator throw a standard-library "bad_alloc" exception when "new" can not find no store to allocate*/

void f()
{
	vector<char*> v; 
	try
	{
		for (;;)
		{
			char* p= new char[10000]; 	/*acquire some memory*/
			v.push_back(p);			/*make sure the new memory is referenced*/
			p[0] = 'x'; 			/*use the new memory*/
		}
	}
	catch(bad_alloc)
	{
		cerr << "Memory exhausted!\n"; 
	}
}/*The "new" operator is not guaranteed to throw "bad_alloc" when you run out of physical main memory.*/


